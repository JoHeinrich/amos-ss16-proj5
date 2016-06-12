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

#include "people_detector.h"

std::vector<cv::Rect> PeopleDetector::detect(cv::Mat *frame) {

  //set hog detector
  // TO DO: test the daimler detector again with proper settings
  cv::HOGDescriptor hog;
  hog.setSVMDetector(cv::HOGDescriptor::getDefaultPeopleDetector());

  //detect people in the frame
  std::vector<cv::Rect> detectedPeople;
  hog.detectMultiScale(*frame, detectedPeople, 0.35, cv::Size(4,4), cv::Size(16,16), 1.04, 1);

  return detectedPeople;
}
