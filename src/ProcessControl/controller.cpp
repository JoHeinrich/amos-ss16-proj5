//
// Projectname: amos-ss16-proj5
//
// Created on 21.05.2016.
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

#include "controller.h"
#include <opencv2/opencv.hpp>
#include "../StreamDecoder/image_view.h"
#include "../ObjectDetection/detection.h"


//define keys
const char KEY_ESC = 27;
const int KEY_SPACE = 32;

void Controller::PlayHDFAsVideo(std::string videofile){
  FrameSelector pipeline(videofile);
  ImageView image_view;
  int protobuf_counts = pipeline.GetImageCount();
  for (int i=0; i<protobuf_counts; i++){
      image_view.ShowImage(pipeline.ReadImage(i));
      if( cvWaitKey(5) == KEY_ESC ) break;
}
}

void Controller::AnalyseHDF5Video(std::string videofile){

  FrameSelector pipeline(videofile);
  ImageView image_view;
  int protobuf_counts = pipeline.GetImageCount();

  Detection detection;
  cv::Mat current_frame;

  for (int i=0; i<protobuf_counts; i++) {

      current_frame = pipeline.ReadImage(i).GetRGBImage();
      detection.ProcessFrame(&current_frame);

      char key = cvWaitKey(10);
      if(key == KEY_ESC)
        break;

      if (key == KEY_SPACE)
        key = cvWaitKey(0);
  }
}

void Controller::SaveAllImagesAsJPEG(std::string videofile){
    FrameSelector pipeline(videofile);
    int protobuf_counts = pipeline.GetImageCount();
    std:String filename = videofile.substr(videofile.find_last_of("/\\")+1);
    std::ostringstream os;
    for (int i=0; i<protobuf_counts; i++){
        os << i;
        cv::imwrite(filename+"_"+os.str()+".jpeg", pipeline.ReadImage(i).GetRGBImage());
    }
}
