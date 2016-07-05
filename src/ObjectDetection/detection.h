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

#ifndef DETECTION_H
#define DETECTION_H

// opencv
#include <opencv2/opencv.hpp>

//local
#include "../StreamDecoder/image.h"
#include "../StreamDecoder/image_view.h"
#include "detector.h"
#include "frame_detection_data.h"

const double default_contrast_value = 3.0;
const int default_brightness_value = 50;
const int default_resized_frame_width = 600;

class Detection {

public:

    /**
    * Default constructor.
    *
    * @param peopleDetector The people detector
    * @param vehicleDetector The vehicle detector
    **/
    Detection(Detector * peopleDetector, Detector * vehicleDetector);

    /**
    * Default destructor.
    *
    **/
    ~Detection();

    /**
    * Resizes the given frame and than performs the detection
    * (people and vehicle for now) on the resized frame.
    *
    * @param image The current image of the stream
    *
    * @return A FrameDetectionData object that holds the detected data
    **/
    FrameDetectionData* ProcessFrame(Image * image);

private:

    Detector * people_detector_; ///< Detector for the pople on the street
    Detector * vehicle_detector_; ///< Detector for the vehicles (Bus)
    ImageView * image_view_;    ///< The image view for showing frames and detections
    float resize_factor_;   ///< The resize factor for resizing the image before execute detection

    /**
    * Resizes an image for better accuracy and better detection
    *
    * @param frame The current image of the stream
    *
    * @return The resized image
    **/
    cv::Mat ResizeFrame(cv::Mat *frame);

    /**
     * Adjust the image for better contrast and better brightness
     *
     * @param frame The current image of the stream
     * @param contrastValue  The contrast value (set a value between 1.0-3.0)
     * @param brightnessValue The brightness value (set a value between 0-100)
     *
     * @return The changed image (= contrastValue * image + brightnessValue)
     **/
    cv::Mat AdjustContrastAndBrightness(cv::Mat *frame, double contrastValue, int brightnessValue);


    /**
     * Adjust the image for better contrast and better brightness with default values
     *
     * @param frame The current image of the stream
     *
     * @return The changed image
     **/
    cv::Mat AdjustContrastAndBrightness(cv::Mat *frame);

};


#endif // DETECTION_H
