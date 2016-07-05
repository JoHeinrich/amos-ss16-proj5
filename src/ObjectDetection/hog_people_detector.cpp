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

#include "hog_people_detector.h"

HOGPeopleDetector::HOGPeopleDetector() {
    hog_descriptor_.setSVMDetector(cv::HOGDescriptor::getDefaultPeopleDetector());
}

std::vector<cv::Rect> HOGPeopleDetector::Detect(cv::Mat *frame) {

    std::vector<cv::Rect> detectedPeople;
    hog_descriptor_.detectMultiScale(*frame, detectedPeople, 0, cv::Size(4,4), cv::Size(16,16), 1.04, 0);

    return detectedPeople;
}

std::vector<cv::Rect> HOGPeopleDetector::DetectInROI(cv::Mat *frame, std::vector<cv::Rect> *rois) {

    std::vector<cv::Rect> detectedPeople;

    for( size_t i = 0; i < rois->size(); i++ ) {

        cv::Rect* rescaled_roi = RescaleROI(&(rois->at(i)), 128, 64, frame->rows, frame->cols);

        cv::Mat ROI = frame->operator()( *rescaled_roi );

        hog_descriptor_.detectMultiScale(ROI, detectedPeople, 0, cv::Size(4,4), cv::Size(1,1), 1.04, 0);

    }

    return detectedPeople;
}
