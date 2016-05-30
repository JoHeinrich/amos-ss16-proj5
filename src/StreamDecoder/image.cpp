//
// image.cpp
// Projectname: amos-ss16-proj5
//
// Created on 21.05.2016.
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


#include <sstream>

#include "image.h"


namespace patch{

    template < typename T > std::string to_string( const T& n ){

        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;

    }

}

Image::Image(const std::string & payload, int width, int height){

   image_payload_ = payload;
   image_width_ = width;
   image_height_ = height;

   // create and fill the payload array buffer
   ConvertToArray();

}

Image::~Image(){

}

std::string Image::GetImagePayload(){

    return image_payload_;
}

int Image::GetImageWidth(){

    return image_width_;
}

int Image::GetImageHeight(){

    return image_height_;
}

Mat Image::GetBGGRImage(){

    // create a Mat object from data
    // TODO is CV_16UC1 the correct type?
    Mat result_image(this->GetImageHeight(), this->GetImageWidth(), CV_16UC1, image_payload_array_);

    return result_image;
}

Mat Image::GetBGRImage(){

    Mat bggr_image = this->GetBGGRImage();

   //convert BGGR image to BGR
   // Mat bggr_8bit_image = bggr_image.clone();
   // bggr_8bit_image.convertTo(bggr_8bit_image, CV_8UC1);

    Mat rgb_8bit_image(this->GetImageHeight(), this->GetImageWidth(), CV_8UC3);
    cvtColor(bggr_image, rgb_8bit_image, CV_BayerGR2BGR);

    return rgb_8bit_image;
}

void Image::ConvertToArray(){

    // convert image payload to unsigned char array
    unsigned int image_buffer_size = this->GetImagePayload().size();
    image_payload_array_ = new unsigned char[image_buffer_size];
    const char* image = this->GetImagePayload().c_str();

    for(int i = 0; i < image_buffer_size; i++){

        image_payload_array_[i] = static_cast<unsigned char>(image[i]);
    }
}
