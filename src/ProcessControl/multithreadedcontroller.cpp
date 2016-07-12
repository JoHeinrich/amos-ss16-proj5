//
// Projectname: amos-ss16-proj5
//
// Copyright (c) 2016 de.fau.cs.osr.amos2016.gruppe5
//
// This file is part of the AMOS Project 2016 @ FAU
// (Friedrich-Alexander University Erlangen-Nürnberg)
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public
// License along with this program. If not, see
// <http://www.gnu.org/licenses/>.


#include "multithreadedcontroller.h"

//opencv
#include <opencv2/opencv.hpp>

//local
#include "../ObjectDetection/cascade_haar_detector.h"
// #include "../ObjectDetection/daimler_people_detector.h"
#include "../ObjectDetection/detection.h"
#include "../ObjectDetection/hog_people_detector.h"
#include "../StreamDecoder/image_view.h"
#include "../ScenarioAnalysation/scenario.h"
#include "../ScenarioAnalysation/humans_in_front_of_bus_scenario.h"
#include "../ScenarioAnalysation/analyser.h"
#include "controller.h"
#include "../CarCommunication/protoagent.h"
#include "basicqueue.h"
#include "blockingqueue.h"

void MultithreadedController::Unlock()
{
    imageQueue->Unlock();
    analysationQueue->Unlock();
    warningQueue->Unlock();
    displayQueue->Unlock();
}

MultithreadedController::MultithreadedController(std::string videofile, uint16_t port, std::string host):videofile(videofile),port(port),host(host)
{
    bool b = true;
    imageQueue = new BlockingQueue<Image>(b);
    analysationQueue = new BlockingQueue<ImageData>(b);
    warningQueue = new BlockingQueue<string>(b);
    displayQueue = new BlockingQueue<ImageData>(b);
    
     #pragma omp parallel sections num_threads(5)// starts a new team
    {
        {
            StreamDecoder(b);
        }
        #pragma omp section
        {
            ObjectDetection(b);
        }
        #pragma omp section
        {
            ScenarioAnalysation(b);
        }
        #pragma omp section
        {
            CarCommunication(b);
        }
        #pragma omp section
        {
            ShowVideo(b);
        }
    }

}


void MultithreadedController::StreamDecoder(bool& loop)
{
    FrameSelectorFactory frame_selector_factory(videofile);
    FrameSelector* pipeline = frame_selector_factory.GetFrameSelector();
    int protobuf_counts = pipeline->GetImageCount();
    for (int i=0; i<protobuf_counts; i++) {
        //cout << "StreamDecoder" << endl;
        Image * current_image = pipeline->ReadImage(i);
        imageQueue->Add(current_image);
        if(!loop)break;
    }
    loop = false;
}

void MultithreadedController::ObjectDetection(bool& loop)
{
    //namedWindow( "Camera stream", WINDOW_AUTOSIZE );
    // DaimlerPeopleDetector people_detector;
     CascadeHaarDetector vehicle_detector("cars3.xml");
     CascadeHaarDetector people_detector("haarcascade_fullbody.xml", 1.5, 0, cv::Size(14,28), cv::Size(98,196));

    Detection detection(&people_detector, &vehicle_detector);
    do
    {
        
        Image * current_image = imageQueue->Remove();
        if(current_image==NULL)continue;
        FrameDetectionData* current_detections = detection.ProcessFrame(current_image);
        if(current_detections != NULL){
            analysationQueue->Add(new ImageData(current_image,current_detections));
            //cout << "ObjectDetection" << endl;
        }
        else
        {
            delete current_image;
        }
        
        current_image = NULL;
    }while(loop);
}

void MultithreadedController::ScenarioAnalysation(bool& loop)
{
    // set up all objects needed for analysing
    std::vector<Scenario*> possible_scenarios;
    possible_scenarios.push_back(new HumansInFrontOfBusScenario());
    Analyser analyser(possible_scenarios);
    do
    {
        //cout << "ScenarioAnalysation" << endl;
        ImageData * imagedata = analysationQueue->Remove();
        if(imagedata == NULL) continue;
        FrameDetectionData* current_detections = imagedata->frame_detection_data;
        if(current_detections == NULL) continue;
        Scenario* scenario = analyser.Analyse(*current_detections);
        if(scenario != NULL)
        {
            string message = scenario->GetScenarioInformation();
            warningQueue->Add(new string(message));
        }
        displayQueue->Add(imagedata);
        current_detections = NULL;
    }while(loop);
    
}

void MultithreadedController::CarCommunication(bool& loop)
{
    try
    {
        ProtoAgent protoagent(port,host);
        do
        {
            //cout << "CarCommunication" << endl;
            string* warningpointer = warningQueue->Remove();
            if(warningpointer==NULL)continue;
            protoagent.sendMsgFromClient(Scenarios::WARN1);
            delete warningpointer;
        }while(loop);
    }
    catch(caf::network_error)
    {
        cout << "could not connect to server going local mode" << endl;
        do
        {
            //cout << "CarCommunication" << endl;
            string* warningpointer = warningQueue->Remove();
            if(warningpointer==NULL)continue;
            delete warningpointer;
        }while(loop);
    }


}

void MultithreadedController::ShowVideo(bool& loop)
{
    ImageView image_view;
    do
    {
        
        ImageData * imagedata  = displayQueue->Remove();
        if(imagedata == NULL) continue;
        FrameDetectionData* current_detections = imagedata->frame_detection_data;
        if(current_detections == NULL) continue;
        
        image_view.ShowImageAndDetections(imagedata->current_image, current_detections->GetElementsOfType(OBJECT_HUMAN), current_detections->GetElementsOfType(OBJECT_VEHICLE));
        int key = cvWaitKey(10);
        if(key == KEY_ESC)
        {
            loop = false;
            Unlock();
        }

    }while(loop);
}



