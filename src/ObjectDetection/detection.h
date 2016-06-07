
//
// detection.h
// Projectname: amos-ss16-proj5
//
// Created on 02.06.2016.
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

#ifndef DETECTION_H
#define DETECTION_H


// #include "image.h"
#include "people_detector.h"
#include "vehicle_detector.h"

class Detection {

public:



private:

  /**
   * Resizes an image for better accuracy and better detection
   *
   * @param frame The current image of the stream
   *
   * @return The resized image
   **/
  cv::Mat resizeFrame(cv::Mat *frame);

  /**
   * Resizes an image for better accuracy and better detection
   *
   * @param firstDetection Vector of detected objects
   * @param secondDetection Vector of detected objects
   * @param frame The resized image of the stream
   *
   **/
  void displayDetectedObjects(std::vector<cv::Rect> firstDetection, std::vector<cv::Rect> secondDetection, cv::Mat *frame);

};


#endif // DETECTION_H
