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

Detection::Detection(Detector * people_detector, Detector * vehicle_detector) {

    people_detector_ = people_detector;
    vehicle_detector_ = vehicle_detector;
    image_view_ = new ImageView();
}

Detection::~Detection(){
    delete image_view_;
    image_view_ = NULL;
}

FrameDetectionData* Detection::ProcessFrame(Image * image) {

    Mat frame = image->GetRGBImage();
    Mat resized_frame = ResizeFrame(&frame);

    std::vector<Rect> detected_people = people_detector_->Detect(&resized_frame);
    std::vector<Rect> detected_vehicles = vehicle_detector_->Detect(&resized_frame);

    // write the detected people and vehicle data into frame detection data and return it
    // resize the position and the box of detected elements to real size again
    FrameDetectionData* detected_objects = new FrameDetectionData();
    std::vector<Element> people_elements;
    std::vector<Element> vehicle_elements;

    for(int i=0; i<detected_people.size(); i++) {

        Rect current_rec = detected_people.at(i);

        std::vector<int> position;
        std::vector<int> box;

        int pos_x_resized = current_rec.x/0.3125;
        int pos_y_resized = current_rec.y/0.3125;

        if(pos_x_resized < 0){
            pos_x_resized = 0;
        }
        if(pos_x_resized > image->GetImageWidth()){
            pos_x_resized = image->GetImageWidth();
        }

        if(pos_y_resized < 0){
            pos_y_resized = 0;
        }
        if(pos_y_resized > image->GetImageHeight()){
            pos_y_resized = image->GetImageHeight();
        }

        position.push_back(pos_x_resized);
        position.push_back(pos_y_resized);

        int box_width_resized = current_rec.width/0.3125;
        int box_height_resized = current_rec.height/0.3125;

        if((position.at(0) + box_width_resized) > image->GetImageWidth()){
            box_width_resized = image->GetImageWidth()-position.at(0);
        }
        if((position.at(1) + box_height_resized) > image->GetImageHeight()){
            box_height_resized = image->GetImageHeight()-position.at(1);
        }

        box.push_back(box_width_resized);
        box.push_back(box_height_resized);

        //std::cout << "Process Frame: position of elem: " << position.at(0) << " " << position.at(1) << std::endl;
        //std::cout << "Process Frame: width and height: " << box.at(0) << " " << box.at(1) << std::endl;

        Element current_elem(position, box);

        people_elements.push_back(current_elem);
    }

    detected_objects->AddElementsOfType(OBJECT_HUMAN, people_elements);

    for(int i=0; i<detected_vehicles.size(); i++) {

        Rect current_rec = detected_vehicles.at(i);

        std::vector<int> position;
        std::vector<int> box;

        position.push_back(current_rec.x/0.3125);
        position.push_back(current_rec.y/0.3125);

        box.push_back(current_rec.width/0.3125);
        box.push_back(current_rec.height/0.3125);

        Element current_elem(position, box);

        vehicle_elements.push_back(current_elem);
    }

    detected_objects->AddElementsOfType(OBJECT_VEHICLE, vehicle_elements);

    // display image and detections

    image_view_->ShowImageAndDetections(image, people_elements, vehicle_elements);

    return detected_objects;
}

Mat Detection::ResizeFrame(Mat *frame) {
    //resize the image to width of 400px to reduce detection time and improve detection accuracy
    //0.3125 is used because the test video is 1280 x 720, so the width resized images is 400px this has to be changed to our image size (best would be no hard coded scaling so other images sizes work too!)
    // TODO: dynamic risizeing depending on input (min width 400px)

    Mat resized_frame;
    resize(*frame, resized_frame, Size(0, 0), 0.3125, 0.3125, CV_INTER_AREA);
    return resized_frame;
}

cv::Mat adjustContrastAndBrightness(cv::Mat *frame,  double contrastValue, int brightnessValue){
    Mat adjusted_image = Mat::zeros( frame->size(), frame->type() );
        for( int x = 0; x < frame->rows; x++ ){
            for( int y = 0; y < frame->cols; y++ ){
                // c: use all colours of RGB / BGR
                for( int c = 0; c < 3; c++ ){
                    adjusted_image.at<Vec3b>(x,y)[c] = saturate_cast<uchar>(contrastValue* (frame->at<Vec3b>(x,y)[c])+ brightnessValue );
            }
        }
    }
    return adjusted_image;
}
