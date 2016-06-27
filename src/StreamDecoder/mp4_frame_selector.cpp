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

#include "mp4_frame_selector.h"

MP4FrameSelector::MP4FrameSelector(std::string file){
    file_name_=file;
    cap.open(file);
    if( !cap.isOpened()){
        std::cout << "could not open mp4 video" << std::endl;
    }
}

MP4FrameSelector::~MP4FrameSelector(){
}

Image * MP4FrameSelector::ReadImage(unsigned int frame_index){
    cv::Mat current_frame;
    cap.set (CV_CAP_PROP_POS_FRAMES , frame_index );
    bool success = cap.read(current_frame);
    if ( ! success ) {
        std::cout << "could not read frame " << frame_index << std::endl;
    }
    MP4Image * current_image = new MP4Image (current_frame, current_frame.rows, current_frame.cols);
    return current_image;
}

int MP4FrameSelector::GetImageCount(){
    return cap.get(CV_CAP_PROP_FRAME_COUNT);
}