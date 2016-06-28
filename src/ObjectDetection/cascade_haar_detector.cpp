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

#include "cascade_haar_detector.h"

CascadeHaarDetector::CascadeHaarDetector(std::string file_name, double scale_factor, int min_neighbors, cv::Size min_size, cv::Size max_size) :
                                               scale_factor_(scale_factor),
                                               min_neighbors_(min_neighbors),
                                               min_size_(min_size),
                                               max_size_(max_size)
{

    cascade_haar_classifier_.load("../../assets/" + file_name);

    // check if classifier was loaded
    if (cascade_haar_classifier_.empty() == true) {
        cascade_haar_classifier_.load("../../src/ObjectDetection/" + file_name);

        if (cascade_haar_classifier_.empty() == true) {
            cascade_haar_classifier_.load("../../ObjectDetection/" + file_name);
        }
    }
}

std::vector<cv::Rect> CascadeHaarDetector::Detect(cv::Mat *frame) {

      std::vector<cv::Rect> detected_objects;
      cascade_haar_classifier_.detectMultiScale(*frame, detected_objects, scale_factor_, min_neighbors_, 0, min_size_, max_size_);

      return detected_objects;
}

std::vector<cv::Rect> CascadeHaarDetector::DetectInROI(cv::Mat *frame, std::vector<cv::Rect> *rois) {

    std::vector<cv::Rect> detected_objects;
    cascade_haar_classifier_.detectMultiScale(*frame, detected_objects, scale_factor_, min_neighbors_, 0, min_size_, max_size_);

    return detected_objects;
}
