//
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

#include "protofiles/CameraImage.pb.h"

class ProtobufImageWrapper {

public:
    /**
     * Parses the protobuf files from an unsigned char*
     *
     *  @param file The file as char*
     *  @param protobuf_file_size the size of the file
     */
    bool ParseFromArray (unsigned char* file, int protobuf_file_size);
    
    /**
     * Gets the image payload as string
     *
     *  @return the payload as string
     */
    const ::std::string& GetImagePayload();
    
    /**
     * Queries if the protobuf-iamge has a payload-value included
     *
     *  @return bool
     */
    bool HasImagePayload();
    
    
    /**
     * Gets the image width
     *
     *  @return the image width as int
     */
    int GetImageWidth();
    
    /**
     * Queries if the protobuf-image has a width-value included
     *
     *  @return bool
     */
    bool HasImageWidth();
    
    /**
     * Gets the image height
     *
     *  @return the image height as int
     */
    int GetImageHeight();
    
    /**
     * Queries if the protobuf-image has a height-value included
     *
     *  @return bool
     */
    bool HasImageHeight();
    
private:
    
    pb::SensorNearData::MFC::CameraImage protobuf_image;

};