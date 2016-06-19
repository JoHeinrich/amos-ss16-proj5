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

//local
#include "image_view.h"

//opencv
#include <opencv2/opencv.hpp>


using namespace cv;

void ImageView::ShowImage(Image * image){
    ShowImage(image, 5);
}

void ImageView::ShowImage(Image * image, int sleep_time){
    cv::imshow("name", image->GetRGBImage());
    waitKey(sleep_time);
}

void ImageView::ShowImageAndDetections(Image *image, std::vector<Element> people_detections, std::vector<Element> vehicle_detections){

      Mat frame = image->GetRGBImage();

      //add retangle for each object in people_detections
      for (int i=0; i<people_detections.size(); i++) {
          Element current_element = people_detections.at(i);
          Rect current_rect;
          current_rect.x = current_element.GetPosition().at(0);
          current_rect.y = current_element.GetPosition().at(1);
          current_rect.width = current_element.GetBoxSize().at(0);
          current_rect.height = current_element.GetBoxSize().at(1);

          rectangle(frame, current_rect.tl(), current_rect.br(), Scalar(0,255,0), 2);
      }

      //add rectangle for each object in vehicle_detections
      for (int i=0; i<vehicle_detections.size(); i++) {
          Element current_element = vehicle_detections.at(i);
          Rect current_rect;
          current_rect.x = current_element.GetPosition().at(0);
          current_rect.y = current_element.GetPosition().at(1);
          current_rect.width = current_element.GetBoxSize().at(0);
          current_rect.height = current_element.GetBoxSize().at(1);
          rectangle(frame, current_rect.tl(), current_rect.br(), Scalar(255,150,0), 2);
      }

      imshow("Camera stream", frame);
}
