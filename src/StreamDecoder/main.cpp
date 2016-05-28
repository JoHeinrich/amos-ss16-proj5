//
// main.cpp
// Projectname: amos-ss16-proj5
//
// Created on 21-05-2016.
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

#include <iostream>
#include <sstream>
#include "frame_selector.h"

using namespace std;


int main(int argc, const char* argv[]) {

    if (argc > 3 || argc == 1){
        
        cerr << "Usage:  " << " FULL_PATH_TO_HDF5_FILE (optional: image index)" << endl;
        return -1;
        
    }


    FrameSelector pipeline(argv[1]);

    if(argc == 2){
        
        // read all images
        pipeline.ReadAllImages();
        //TODO give all images to imageviewer
        
    } else if(argc == 3){
        
        // read one image
        unsigned int index = 0;
        stringstream string_index(argv[2]);
        string_index >> index;
        pipeline.ReadImage(index);

        // TODO give image to image viewer
        
    }



    return 0;
}
