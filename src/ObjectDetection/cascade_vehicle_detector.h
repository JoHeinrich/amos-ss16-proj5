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

#ifndef VEHICLE_DETECTOR_H
#define VEHICLE_DETECTOR_H

#include "detector.h"

class CascadeVehicleDetector : public Detector {

public:

    /**
    * Default constructor.
    **/
    CascadeVehicleDetector();

  /**
   * Detects vehicles in the given frame (cv::Mat)
   *
   * @param frame The current frame
   *
   * @return The vector of all detected vehicles in the current Frame
   **/
  std::vector<cv::Rect> Detect(cv::Mat *frame);

private:

    cv::CascadeClassifier cascade_vehicle_classifier_;

};


#endif // VEHICLE_DETECTOR_H
