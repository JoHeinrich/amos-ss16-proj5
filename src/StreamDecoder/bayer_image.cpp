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

//std
#include <sstream>

//local
#include "bayer_image.h"


namespace patch{

    template < typename T > std::string to_string( const T& n ){

        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;

    }

}

BayerImage::BayerImage(const std::string payload, int width, int height){

   image_payload_ = payload;
   image_width_ = width;
   image_height_ = height;
}

BayerImage::~BayerImage(){

}

std::string BayerImage::GetImagePayload(){

    return image_payload_;
}

int BayerImage::GetImageWidth(){

    return image_width_;
}

int BayerImage::GetImageHeight(){

    return image_height_;
}

Mat BayerImage::GetRGBImage(){

    uint16_t decompressed_payload [GetImageWidth() * GetImageHeight()];
    std::string payload =GetImagePayload();
    std::vector<char> writable(payload.c_str(), payload.c_str() + payload.length() + 1);
    char *temp_dest_buffer = reinterpret_cast<char *>(&decompressed_payload);
    char *buffer = &writable[0];

    // (1176 * 640) / 2 bytes => 376320
    int image_pixel_count = (GetImageWidth() * GetImageHeight()/2);
    for (int i = 0; i < image_pixel_count; i++)
    {
        temp_dest_buffer[0] = buffer[0];
        temp_dest_buffer[1] = ((unsigned char) buffer[1]) >> 4;
        *((unsigned short*)&temp_dest_buffer[2]) = (((unsigned char)buffer[2]) << 4) | (buffer[1] & 0x0F);
        temp_dest_buffer += 4;
        buffer += 3;
    }
    cv::Mat rgb_image;
    cv::Mat bayer_16bit_image(GetImageHeight(), GetImageWidth(), CV_16UC1, reinterpret_cast<uint8_t *>(&decompressed_payload));
    cv::Mat bayer_8bit_image = bayer_16bit_image.clone();
    bayer_8bit_image.convertTo(bayer_8bit_image, CV_8UC3, 0.0625);

    cv::cvtColor(bayer_8bit_image, rgb_image, CV_BayerGR2RGB);
    return rgb_image;
}
