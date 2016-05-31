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

#include <opencv2/opencv.hpp>

using namespace cv;

void detectAndDisplay(cv::Mat *image);

const int KEY_ESC = 27;

HOGDescriptor hog;
int main (int argc, const char * argv[])
{
    if(argc < 2){
        std::cout << "Usage " << argv[0] << " video.mp4" << std::endl;
        return 0;
    }

    //set hog detector
    // TO DO: test the daimler detector again with proper settings
    hog.setSVMDetector(cv::HOGDescriptor::getDefaultPeopleDetector());

    //open video
    cv::VideoCapture capture(argv[1]);
    if (!capture.isOpened()){
        std::cout << "Failed to open video" << std::endl;
        return -1;
    }

    //run video
    cv::Mat frame;
    do{
        if (!capture.read(frame))
            break;
        detectAndDisplay(&frame);
        char key = cvWaitKey(10);
        if (key == KEY_ESC)
            break;
    } while(1);

    return 0;
}

void detectAndDisplay(cv::Mat *frame){
    //resize the image to width of 400px to reduce detection time and improve detection accuracy
    //0.3125 is used because the test video is 1280 x 720, so the width resized images is 400px this has to be changed to our image size (best would be no hard coded scaling so other images sizes work too!)

    cv::Mat resizedImage;
    resize(*frame, resizedImage, Size(0, 0), 0.3125, 0.3125, CV_INTER_AREA);

    //detect people in the resizedImage
    std::vector<Rect> foundHumans;
    hog.detectMultiScale(resizedImage, foundHumans, 0.35, Size(4,4), Size(16,16), 1.04, 1);

    //add retangle to found humans
    for (int i=0; i<foundHumans.size(); i++){
        Rect r = foundHumans[i];
        rectangle(resizedImage, r.tl(), r.br(), Scalar(255,255,255), 3);
    }
    imshow("demo", resizedImage);
}
