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

#include <opencv2/opencv.hpp>
#include "detection.h"

using namespace std;
using namespace cv;

const int KEY_ESC = 27;
const int KEY_SPACE = 32;
const std::string WindowName = "Camera Stream";

int main(int argc, const char * argv[]) {

  if(argc < 2)
  {
    std::cout << "Usage " << argv[0] << " video.mp4" << std::endl;
    return 0;
  }

  //open video
  cv::VideoCapture capture(argv[1]);
  if (!capture.isOpened()){
      std::cout << "Failed to open video" << std::endl;
      return -1;
  }

  Detection detection;

  // run video
   Mat frame;
   do{
       if (!capture.read(frame))
           break;

        // To do
        detection.processFrame(&frame);
        // Mat resizedFrame = resizeFrame(&frame);
        // std::vector<Rect> detectedPeople = detectPeople(&resizedFrame);
        // std::vector<Rect> detectedVehicles = detectVehicles(&resizedFrame);
        // displayDetectedObjects(detectedPeople, detectedVehicles, &resizedFrame);

       char key = cvWaitKey(10);
       if (key == KEY_SPACE)
           key = cvWaitKey(0);

       if (key == KEY_ESC)
           break;
   } while(1);

    return 0;
}
