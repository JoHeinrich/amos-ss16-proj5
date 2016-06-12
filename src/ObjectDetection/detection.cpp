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

#include "detection.h"
#include "people_detector.h"
#include "vehicle_detector.h"

using namespace std;
using namespace cv;

void Detection::ProcessFrame(Mat *frame) {

  PeopleDetector peopleDetector;
  VehicleDetector vehicleDetector;

  Mat resizedFrame = ResizeFrame(frame);

  std::vector<Rect> detectedPeople = peopleDetector.Detect(&resizedFrame);
  std::vector<Rect> detectedVehicles = vehicleDetector.Detect(&resizedFrame);

  DisplayDetectedObjects(detectedPeople, detectedVehicles, &resizedFrame);
}

Mat Detection::ResizeFrame(Mat *frame) {
  //resize the image to width of 400px to reduce detection time and improve detection accuracy
  //0.3125 is used because the test video is 1280 x 720, so the width resized images is 400px this has to be changed to our image size (best would be no hard coded scaling so other images sizes work too!)

  Mat resizedFrame;
  resize(*frame, resizedFrame, Size(0, 0), 0.3125, 0.3125, CV_INTER_AREA);
  return resizedFrame;
}

void Detection::DisplayDetectedObjects(std::vector<Rect> firstDetection, std::vector<Rect> secondDetection, Mat *frame) {
  //add retangle for each Object in firstDetection
  for (int i=0; i<firstDetection.size(); i++){
      Rect r = firstDetection[i];
      rectangle(*frame, r.tl(), r.br(), Scalar(0,255,0), 2);
  }

  //add retangle for each Object in secondDetection
  for (int i=0; i<secondDetection.size(); i++){
      Rect r = secondDetection[i];
      rectangle(*frame, r.tl(), r.br(), Scalar(255,150,0), 2);
  }

  imshow("Camera stream", *frame);
}
