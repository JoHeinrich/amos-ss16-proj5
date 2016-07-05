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

#include "detector.h"

cv::Rect* Detector::RescaleROI(cv::Rect *roi, int window_height, int window_width){

    // if the roi is smaller than the detector window,
    // shift and rescale it

    if(roi->width < window_width){

        int half_width = window_width/2 + 1;
        roi->x = roi->x + half_width;
        roi->width = roi->width + window_width;

    }
    if(roi->height < window_height){

        int half_height = window_height/2 + 1;
        roi->y = roi->y + half_height;
        roi->height = roi->height + window_height;

    }

    return roi;

}
