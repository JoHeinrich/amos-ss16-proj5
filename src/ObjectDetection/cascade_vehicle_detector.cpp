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

#include "cascade_vehicle_detector.h"

CascadeVehicleDetector::CascadeVehicleDetector() {
    std::string classifier_file = "cars3.xml";

    cascade_vehicle_classifier_.load("../../assets/" + classifier_file);

    // check if classifier was loaded
    if (cascade_vehicle_classifier_.empty() == true) {
        cascade_vehicle_classifier_.load("../../src/ObjectDetection/" + classifier_file);

        if (cascade_vehicle_classifier_.empty() == true) {
            cascade_vehicle_classifier_.load("../../ObjectDetection/" + classifier_file);
        }
    }
}

std::vector<cv::Rect> CascadeVehicleDetector::Detect(cv::Mat *frame) {

      std::vector<cv::Rect> detectedVehicles;
      cascade_vehicle_classifier_.detectMultiScale(*frame, detectedVehicles, 1.1, 3, 0, cv::Size(20,20), cv::Size(80,80));

      return detectedVehicles;
}
