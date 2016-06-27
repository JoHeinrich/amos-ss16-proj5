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

#include <string>


//local
#include "../StreamDecoder/frame_selector.h"
#include "../StreamDecoder/frame_selector_factory.h"
#include "../StreamDecoder/image.h"
#include "../ObjectDetection/frame_detection_data.h"
#include "queue.h"

using namespace std;

#ifndef MULTITHREADEDCONTROLLER
#define MULTITHREADEDCONTROLLER
class MultithreadedController
{
    string videofile;
    int port;
    string host;

    Queue<Image>* imageQueue;
    Queue<FrameDetectionData>* fddQueue;
    Queue<string>* warningQueue;

public:
    MultithreadedController(std::string videofile, uint16_t port = 0, std::string host = "");

    /*
    * loads ONE ore more Images from filename and pushes them into imageQueue
    *
    * @loop continues the loop while true
    */
    void StreamDecoder(bool& loop);

    /*
    * Takes ONE ore more Images out of the imageQueue executes the objectDetection and pushes
    *
    * @loop continues the loop while true
    */
    void ObjectDetection(bool& loop);

    /*
    * takes ONE or more FrameDetectionData from the ffdQueue and analyses the data.
    * If a Situation is detected the warning will be written into the waringQueue
    *
    * @loop continues the loop while true
    */
    void ScenarioAnalysation(bool& loop);
    
    /*
    * takes ONE or more strings out of the warningQueue and sends them to the other car
    *
    * @loop continues the loop while true
    */
    void CarCommunication(bool& loop);

    
};

#endif