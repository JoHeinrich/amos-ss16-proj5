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

#ifndef __amos_ss16_proj5__image__
#define __amos_ss16_proj5__image__

//std
#include <stdio.h>

//opencv
#include <opencv2/opencv.hpp>

class Image{
    
public:
    
    /**
     * Destructor
     */
    virtual ~Image(){};
    
    /**
     * Gets the image width
     *
     * @return The image width
     */
    virtual int GetImageWidth()=0;
    
    /**
     * Gets the image height
     *
     * @return The image height
     */
    virtual int GetImageHeight()=0;
    
    /**
     * Gets the bgr image
     *
     * @return The bgr image
     */
    virtual cv::Mat GetRGBImage()=0;
    
    
private:


};

#endif /* defined(__amos_ss16_proj5__image__) */
