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

#ifndef __amos_ss16_proj5__mp4_frame_selector__
#define __amos_ss16_proj5__mp4_frame_selector__

#include <stdio.h>
#include <string>
#include "frame_selector.h"
#include <opencv2/opencv.hpp>
#include "mp4_image.h"

class MP4FrameSelector : public FrameSelector{
    
public:
    
    /**
     * Constructor
     *
     * @param file  The filename of the mp4 file to read
     */
    MP4FrameSelector(std::string file);
    
    /**
     * Destructor
     */
    ~MP4FrameSelector();
    
    /**
     * Reads one image at the given index from mp4 file
     *
     * @param frame_index The frame index of the image
     *
     * @return The image object at the given frame index
     */
    Image * ReadImage(unsigned int frame_index);
    
    
    /**
     * Returns number of containing images
     *
     * @return Count of images
     */
    int GetImageCount();
    
    
private:
    
    std::string file_name_;   ///< The full path file name of the mp4 file
    cv::VideoCapture cap; // The Video capture fore the video
};

#endif /* defined(__amos_ss16_proj5__mp4_frame_selector__) */
