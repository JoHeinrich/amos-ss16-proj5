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
//

//opencv
#include <opencv2/opencv.hpp>

//local
#include "../ObjectDetection/cascade_haar_detector.h"
#include "../ObjectDetection/daimler_people_detector.h"
#include "../ObjectDetection/template_matching_people_detector.h"
#include "../ObjectDetection/detection.h"
//#include "../ObjectDetection/hog_people_detector.h"
#include "../StreamDecoder/image_view.h"
#include "../ScenarioAnalysation/scenario.h"
#include "../ScenarioAnalysation/humans_in_front_of_bus_scenario.h"
#include "../ScenarioAnalysation/analyser.h"
#include "controller.h"
#include "../CarCommunication/protoagent.h"

//define keys
const int KEY_ESC = 27;
const int KEY_SPACE = 32;

void Controller::PlayAsVideo(std::string videofile) {
  FrameSelectorFactory frame_selector_factory(videofile);
  FrameSelector* pipeline = frame_selector_factory.GetFrameSelector();
  ImageView image_view;
  int protobuf_counts = pipeline->GetImageCount();
  for (int i=0; i<protobuf_counts; i++) {
      Image * current_image = pipeline->ReadImage(i);
      image_view.ShowImage(current_image);
      delete current_image;
      current_image = NULL;
      if( cvWaitKey(5) == KEY_ESC ) break;
  }
}

void Controller::AnalyseVideo(std::string videofile, uint16_t port, std::string host) {
  ImageView image_view;
  FrameSelectorFactory frame_selector_factory(videofile);
  FrameSelector* pipeline = frame_selector_factory.GetFrameSelector();
  int protobuf_counts = pipeline->GetImageCount();

  //DaimlerPeopleDetector people_detector;
  //HOGPeopleDetector people_detector;
  TemplateMatchingPeopleDetector people_detector("/home/anyuser/Desktop/amos/amos-ss16-proj5/src/ObjectDetection/TemplateContrast.png");
  CascadeHaarDetector vehicle_detector("cars3.xml");
  Detection detection(&people_detector, &vehicle_detector);

  // set up all objects needed for analysing
  std::vector<Scenario*> possible_scenarios;
  possible_scenarios.push_back(new HumansInFrontOfBusScenario());
  Analyser analyser(possible_scenarios);

  for (int i=0; i<protobuf_counts; i++) {

    Image * current_image = pipeline->ReadImage(i);
    FrameDetectionData* current_detections = detection.ProcessFrame(current_image);

    if(!current_detections){
        continue;
    }

    Scenario* scenario = analyser.Analyse(*current_detections);

    if(!scenario){

        std::cout << "No scenario in frame " << i << " was detected!" <<std::endl;

    }else{

        if( HumansInFrontOfBusScenario* result = dynamic_cast<HumansInFrontOfBusScenario*>(scenario) ){

            // TODO here for later: inform the communication module that a "Humans in front of bus" scenario was detected
        }
        // for demo: show information about scenario in current frame
        std::cout << "Current detected scenario: " << scenario->GetScenarioInformation() << " in frame: " << i << std::endl;

        //#ifdef COMBINE
        //Notifying other car
        if(port!=0)
        {
            std::cout << "Informing other car" << std::endl;
            ProtoAgent::startClient(port,host);
        }
        //#endif
    }

    int key = cvWaitKey(10);
    if(key == KEY_ESC)
      break;

    if (key == KEY_SPACE)
      key = cvWaitKey(0);

    delete current_image;
    current_image = NULL;
    delete current_detections;
    current_detections = NULL;
    //delete scenario;
    scenario = NULL;

   }
}

void Controller::SaveAllImagesAsJPEG(std::string videofile) {
    FrameSelectorFactory frame_selector_factory(videofile);
    FrameSelector* pipeline = frame_selector_factory.GetFrameSelector();
    int protobuf_counts = pipeline->GetImageCount();
    std::string filename = videofile.substr(videofile.find_last_of("/\\")+1);
    std::ostringstream os;
    for (int i=0; i<protobuf_counts; i++){
        os << i;
        cv::imwrite(filename+"_"+os.str()+".jpeg", pipeline->ReadImage(i)->GetRGBImage());
    }
}
