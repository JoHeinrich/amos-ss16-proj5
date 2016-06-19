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
#include "element.h"

using namespace std;
using namespace cv;

Detection::Detection(Detector * peopleDetector, Detector * vehicleDetector) {

    people_detector_ = peopleDetector;
    vehicle_detector_ = vehicleDetector;
}

FrameDetectionData* Detection::ProcessFrame(Image * image) {

  Mat frame = image->GetRGBImage();
  Mat resized_frame = ResizeFrame(&frame);

  std::vector<Rect> detected_people = people_detector_->Detect(&resized_frame);
  std::vector<Rect> detected_vehicles = vehicle_detector_->Detect(&resized_frame);

  DisplayDetectedObjects(detected_people, detected_vehicles, &resized_frame);

  // write the detected people and vehicle data into frame detection data and return it
  FrameDetectionData* detected_objects = new FrameDetectionData();
  std::vector<Element> people_elements;
  std::vector<Element> vehicle_elements;

  for(int i=0; i<detected_people.size(); i++){

      Rect current_rec = detected_people.at(i);

      std::vector<int> position;
      std::vector<int> box;

      position.push_back(current_rec.x);
      position.push_back(current_rec.y);

      box.push_back(current_rec.width);
      box.push_back(current_rec.height);

      Element current_elem(position, box);

      people_elements.push_back(current_elem);
  }

  detected_objects->AddElementsOfType(OBJECT_HUMAN, people_elements);

  for(int i=0; i<detected_vehicles.size(); i++){

      Rect current_rec = detected_vehicles.at(i);

      std::vector<int> position;
      std::vector<int> box;

      position.push_back(current_rec.x);
      position.push_back(current_rec.y);

      box.push_back(current_rec.width);
      box.push_back(current_rec.height);

      Element current_elem(position, box);

      vehicle_elements.push_back(current_elem);
  }

  detected_objects->AddElementsOfType(OBJECT_VEHICLE, vehicle_elements);

  return detected_objects;

}

Mat Detection::ResizeFrame(Mat *frame) {
  //resize the image to width of 400px to reduce detection time and improve detection accuracy
  //0.3125 is used because the test video is 1280 x 720, so the width resized images is 400px this has to be changed to our image size (best would be no hard coded scaling so other images sizes work too!)
  // TODO: dynamic risizeing depending on input (min width 400px)

  Mat resizedFrame;
  resize(*frame, resizedFrame, Size(0, 0), 0.3125, 0.3125, CV_INTER_AREA);
  return resizedFrame;
}

void Detection::DisplayDetectedObjects(std::vector<Rect> firstDetection, std::vector<Rect> secondDetection, Mat *frame) {
  //add retangle for each Object in firstDetection
  for (int i=0; i<firstDetection.size(); i++) {
      Rect r = firstDetection[i];
      rectangle(*frame, r.tl(), r.br(), Scalar(0,255,0), 2);
  }

  //add rectangle for each Object in secondDetection
  for (int i=0; i<secondDetection.size(); i++) {
      Rect r = secondDetection[i];
      rectangle(*frame, r.tl(), r.br(), Scalar(255,150,0), 2);
  }

  imshow("Camera stream", *frame); // TODO: Use image_view class
}
