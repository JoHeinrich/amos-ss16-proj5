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

void MultithreadedController::StreamDecoder(bool& loop)
{
    FrameSelectorFactory frame_selector_factory(videofile);
    FrameSelector* pipeline = frame_selector_factory.GetFrameSelector();
    int protobuf_counts = pipeline->GetImageCount();
    for (int i=0; i<protobuf_counts; i++) {
        Image * current_image = pipeline->ReadImage(i);
        if(!loop)break;
    }
}

void MultithreadedController::ObjectDetection(bool& loop)
{
    ImageView image_view;
    // DaimlerPeopleDetector people_detector;
    HOGPeopleDetector people_detector;
    CascadeHaarDetector vehicle_detector("cars3.xml");
    Detection detection(&people_detector, &vehicle_detector);
    do
    {
        FrameDetectionData* current_detections = detection.ProcessFrame(current_image);
        if(current_detections){

        }
            delete current_image;
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
        Scenario* scenario = analyser.Analyse(*current_detections);
        scenario->GetScenarioInformation()
        
        delete current_detections;
        current_detections = NULL;
    }while(loop);
    
}

void MultithreadedController::CarCommunication(bool& loop)
{
    do
    {
        
        ProtoAgent::startClient(port,host);
    }while(loop);

}

  



