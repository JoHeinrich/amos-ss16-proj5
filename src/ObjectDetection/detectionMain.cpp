//
// main2.cpp
// Projectname: amos-ss16-proj5
//
// Created by Elisabeth Hoppe on 10-05-2016.
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

#include <opencv2/opencv.hpp>
// using namespace std;
using namespace cv;
//#include "imageprocessing/humandetector.h"

Mat resizeFrame(Mat *image);
std::vector<Rect> detectPeople(Mat *image);
void diplayDetectedObjects(std::vector<Rect> detectedObjects, Mat *image);

const int KEY_ESC = 27;
const int KEY_SPACE = 32;

int main(int argc, const char * argv[]) {

  if(argc < 3)
  {
    std::cout << "Usage " << argv[0] << " classifier.xml video.mp4" << std::endl;
    return 0;
  }

  //open video
  cv::VideoCapture capture(argv[2]);
  if (!capture.isOpened()){
      std::cout << "Failed to open video" << std::endl;
      return -1;
  }

  // run video
   Mat frame;
   do{
       if (!capture.read(frame))
           break;

       Mat resizedFrame = resizeFrame(&frame);
       std::vector<Rect> foundPeople = detectPeople(&resizedFrame);
       diplayDetectedObjects(foundPeople, &resizedFrame);
       char key = cvWaitKey(10);

       if (key == KEY_SPACE)
           key = cvWaitKey(0);

       if (key == KEY_ESC)
           break;
   } while(1);

    return 0;
}

Mat resizeFrame(Mat *frame) {
  //resize the image to width of 400px to reduce detection time and improve detection accuracy
  //0.3125 is used because the test video is 1280 x 720, so the width resized images is 400px this has to be changed to our image size (best would be no hard coded scaling so other images sizes work too!)

  Mat resizedFrame;
  resize(*frame, resizedFrame, Size(0, 0), 0.3125, 0.3125, CV_INTER_AREA);
  return resizedFrame;
}

std::vector<Rect> detectPeople(Mat *frame){
    //set hog detector
    // TO DO: test the daimler detector again with proper settings
    HOGDescriptor hog;
    hog.setSVMDetector(cv::HOGDescriptor::getDefaultPeopleDetector());

    //detect people in the frame
    std::vector<Rect> detectedPeople;
    hog.detectMultiScale(*frame, detectedPeople, 0.35, Size(4,4), Size(16,16), 1.04, 1);

    return detectedPeople;
}

void diplayDetectedObjects(std::vector<Rect> detectedObjects, Mat *frame){
    //add retangle for each Object, that was detected
    for (int i=0; i<detectedObjects.size(); i++){
        Rect r = detectedObjects[i];
        rectangle(*frame, r.tl(), r.br(), Scalar(0,255,0), 2);
    }
    imshow("CameraStream", *frame);
}
