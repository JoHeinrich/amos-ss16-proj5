//
// main.cpp
// Projectname: amos-ss16-proj5
//
// Created by Richard Fuchs on 24.04.16.
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
#include <fstream>
#include <string>
#include "msg_cameraimage_reader.h"

using namespace std;


int main(int argc, const char* argv[]) {
    // Verify compatibility of linked and compiled headers
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    
    if (argc != 2) {
        cerr << "Usage:  " << argv[0] << " CAMERA_IMAGE_FILE" << endl;
        return -1;
    }
    
    pb::Grid::MsgCameraImage camera_image;
    {
        // Read the existing camera image;
        fstream input(argv[1], ios::in | ios::binary);
        if (!camera_image.ParseFromIstream(&input)) {
            cerr << "Failed to parse image." << endl;
            return -1;
        }
    }
    
    MsgCameraImageReader reader;
    reader.listInfosAboutMsgImage(camera_image);
    
    // As suggested by Google: Delete all global objects allocated by libprotobuf.
    google::protobuf::ShutdownProtobufLibrary();
    
    return 0;
}
