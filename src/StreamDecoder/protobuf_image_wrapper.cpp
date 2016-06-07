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


#include "protobuf_image_wrapper.h"

bool ProtobufImageWrapper::ParseFromArray (unsigned char* file, int protobuf_file_size){
    return protobuf_image.ParseFromArray(file, protobuf_file_size);
}

const ::std::string& ProtobufImageWrapper::GetImagePayload(){
    return protobuf_image.image_payload();
}

bool ProtobufImageWrapper::HasImagePayload(){
    return protobuf_image.has_image_payload();
}

int ProtobufImageWrapper::GetImageWidth(){
    return protobuf_image.image_width();
}

bool ProtobufImageWrapper::HasImageWidth(){
    return protobuf_image.has_image_width();
}

int ProtobufImageWrapper::GetImageHeight(){
    return protobuf_image.image_height();
}

bool ProtobufImageWrapper::HasImageHeight(){
    return protobuf_image.has_image_width();
}