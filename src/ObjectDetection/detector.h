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

#ifndef DETECTOR_H
#define DETECTOR_H

#include <opencv2/opencv.hpp>
#include <vector>

class Detector {

public:

    /**
    * Detects objects in the given frame (cv::Mat). Must be overwritten in subclass.
    *
    * @param frame The current frame
    *
    * @return The vector of all detected objects in the current Frame
    **/
    virtual std::vector<cv::Rect> Detect(cv::Mat *frame) = 0;

    /**
    * Detects objects in the given frame given as a cv::Mat object only in the ROIs. Must be overwritten in subclass.
    *
    * @param frame The current frame
    * @param frame The rois
    *
    * @return The vector of all detected objects in the current frame
    **/
    virtual std::vector<cv::Rect> DetectInROI(cv::Mat *frame, std::vector<cv::Rect> *rois) = 0;

private:

};


#endif // DETECTOR_H
