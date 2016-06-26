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

using namespace std;

int main(int argc, const char* argv[]) {

    if (argc > 3 || argc == 1){

        cerr << "Usage:  " << " FULL_PATH_TO_VIDEO_FILE (optional: image index)" << endl;
        return -1;

    }

    if(argc == 2){

        Controller controller;
        controller.AnalyseVideo(argv[1]);


    } else if(argc == 3){

        FrameSelectorFactory frame_selector_factory(argv[1]);
        FrameSelector* pipeline = frame_selector_factory.GetFrameSelector();
        // read one image
        unsigned int index = 0;
        stringstream string_index(argv[2]);
        string_index >> index;
        Image * result_image = pipeline->ReadImage(index);

        ImageView image_viewer;
        image_viewer.ShowImage(result_image, 0);
    }



    return 0;
}

