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

#include "vehicle_detector.h"

std::vector<cv::Rect> VehicleDetector::Detect(cv::Mat *frame) {

  cv::CascadeClassifier vehicle_classifier;
  vehicle_classifier.load("../../assets/vehicle_classifier.xml");

  // check if classifier was loaded
  if (vehicle_classifier.empty() == true) {
    std::cout << "Failed to load vehicle classifier" << std::endl;
    vehicle_classifier.load("../../ObjectDetection/vehicle_classifier.xml");
  }

  //detect vehicles in the frame
  std::vector<cv::Rect> detectedVehicles;
  vehicle_classifier.detectMultiScale(*frame, detectedVehicles, 1.1, 2, 0, cv::Size(70,70), cv::Size(400,400)); // TODO: adjust settings to HDF5 data

  return detectedVehicles;
}
