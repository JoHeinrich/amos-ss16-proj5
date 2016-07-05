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

cv::Rect* Detector::RescaleROI(cv::Rect *roi, int window_height, int window_width, int max_height, int max_width){

    // if the roi is smaller than the detector window,
    // shift and rescale it

    cv::Rect* result;

    std::cout << "Rescaling : Before: " << roi->width << " " << roi->height << " " << roi->x << "  " << roi->y << std::endl;

    if(roi->width < window_width){

        int difference = window_width - roi->width;
        std::cout << "width diff : "<< difference << std::endl;
        //int half_width = window_width/2 + 1;
        result->x = roi->x - (difference/2 );
        if(result->x < 0){
            result->x = 0;
        }

        result->width = roi->width + difference;

        if( (result->x + result->width) > max_width){
            int width = max_width - result->x ;
            result->width = width;
        }

        //std::cout << "half width " << half_width << std::endl;

    }
    if(roi->height < window_height){

        int difference = window_height - roi->height;
        std::cout << " Height diff: " << difference << std::endl;
        //int half_height = window_height/2;
        result->y = roi->y - (difference/2 );
        if(result->y < 0){
            result->y = 0;
        }
        result->height = roi->height + difference;

        if( (result->y + result->height) > max_height){
            int height = max_height - result->y;
            result->height = height;
        }

        //std::cout << "half height " << half_height << std::endl;

    }

    std::cout << "Rescaling : After: " << result->width << " " << result->height << " " << result->x << " " << result->y << std::endl;
    std::cout << max_width << " " << max_height << std::endl;

    return roi;

}
