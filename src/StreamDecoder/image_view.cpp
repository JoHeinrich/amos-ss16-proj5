//
// image_view.cpp
// Projectname: amos-ss16-proj5
//
// Created on 28.05.2016.
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

#include "image_view.h"
#include <opencv2/opencv.hpp>

using namespace cv;

void ImageView::ShowImage(Image image){

    // get BGGR image
    // TODO get bgr image later
    Mat bggr_image = image.GetBGGRImage();

    // display image
    namedWindow( "Image View", WINDOW_AUTOSIZE );
    imshow( "Image View", bggr_image );
    waitKey(0);
}
