//
// msg_cameraimage_reader.cpp
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
#include <string>

#include "msg_cameraimage_reader.h"
#include <iostream>
#include <fstream>

using namespace std;

void MsgCameraImageReader::listInfosAboutMsgImage(const pb::Grid::MsgCameraImage camera_image){
    cout << "timestamp: " << camera_image.header().timestamp()<< endl;
    cout << "m_imagecounter: " << camera_image.m_imagecounter()<< endl;
    cout << "m_imagewidth: " << camera_image.m_imagewidth() << endl;
    cout << "m_imageheight: " << camera_image.m_imageheight() << endl;
    cout << "m_oimagewidth: " << camera_image.m_oimagewidth() << endl;
    cout << "m_oimageheight: " << camera_image.m_oimageheight() << endl;
    cout << "m_oimagepattern: " << camera_image.m_oimagepattern() << endl;
    cout << "m_imagecompressed: " << camera_image.m_imagecompressed() << endl;
    cout << "m_imagecompressiontype: " << camera_image.m_imagecompressiontype() << endl;
    cout << "m_imagetype: " << camera_image.m_imagetype() << endl;
    cout << "m_byteperpixel: " << camera_image.m_byteperpixel() << endl;
    cout << "m_bitperpixel: " << camera_image.m_bitperpixel() << endl;
    cout << "m_imagepayload().size(): " << camera_image.m_imagepayload().size() << endl;
    cout << "mbmpimage().size(): " << camera_image.mbmpimage().size() << endl;
    cout << "m_imagepayload().empty(): " << camera_image.m_imagepayload().empty() << endl;
    cout << "mbmpimage().empty(): " << camera_image.mbmpimage().empty() << endl;    
}
