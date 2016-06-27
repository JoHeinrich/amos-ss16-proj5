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

/**
* This is the global main of amos-ss16-proj5.
*
* It takes a video (hdf5 or mp4), extracts it, executes object detection and scenario analysation.
* Every time a specific scenario is detected, the communication is performed.
*/

//std
#include <iostream>
#include <sstream>
#include <vector>

//local
#include "StreamDecoder/hdf5_frame_selector.h"
#include "StreamDecoder/frame_selector_factory.h"
#include "StreamDecoder/image_view.h"
#include "ProcessControl/controller.h"
#include "ProcessControl/multithreadedcontroller.h"
#include "CarCommunication/protoagent.h"

using namespace std;

static bool
str_to_uint16(const char *str, uint16_t *res)
{
  char *end;
  errno = 0;
  intmax_t val = strtoimax(str, &end, 10);
  if (errno == ERANGE || val < 0 || val > UINT16_MAX || end == str || *end != '\0')
    return false;
  *res = (uint16_t) val;
  return true;
}

int main(int argc, const char* argv[]) {

    if (argc > 4 || argc == 1){

        cerr << "Usage1:  " << " FULL_PATH_TO_VIDEO_FILE (IMAGE_INDEX)\n";
        cerr << "Usage2:  " << " PORT (SERVERIP FULL_PATH_TO_VIDEO_FILE)" << endl;
        return -1;

    }

    if(argc == 2){
        uint16_t port;
        if(str_to_uint16(argv[1],&port))
        {
            cout << "Server port: " << port << endl;
            ProtoAgent protoagent(port);
        }
        else
        {
            cerr << "Analysing video in file " << argv[1] << endl;
            Controller controller;
            controller.AnalyseVideo(argv[1]);
        }
    } 

    if(argc == 3){
        /*FrameSelectorFactory frame_selector_factory(argv[1]);
        FrameSelector* pipeline = frame_selector_factory.GetFrameSelector();
        // read one image
        unsigned int index = 0;
        stringstream string_index(argv[2]);
        string_index >> index;
        Image * result_image = pipeline->ReadImage(index);

        ImageView image_viewer;
        image_viewer.ShowImage(result_image, 0);*/
    }
    
    if(argc == 4){
        uint16_t port;
        if(str_to_uint16(argv[1],&port))
        {
            MultithreadedController controller(argv[3],port,argv[2]);
            //Controller().AnalyseVideo(argv[3],port,argv[2]);
        }
        else
        {
            cerr << "Could not read port" << endl;
        }

}


    return 0;
}

