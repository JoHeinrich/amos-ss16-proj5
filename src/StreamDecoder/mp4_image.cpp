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

//local
#include "mp4_image.h"

MP4Image::MP4Image(const cv::Mat rgb_image, int width, int height){
    rgb_image_ = rgb_image;
    image_width_ = width;
    image_height_ = height;
}

MP4Image::~MP4Image(){
}

int MP4Image::GetImageWidth(){
    return image_width_;
}

int MP4Image::GetImageHeight(){
    return image_height_;
}

Mat MP4Image::GetRGBImage(){
    return rgb_image_;
}
