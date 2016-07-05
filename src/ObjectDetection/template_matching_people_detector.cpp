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

//opencv
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

//local
#include "template_matching_people_detector.h"

using namespace cv;


TemplateMatchingPeopleDetector::TemplateMatchingPeopleDetector(std::string image_file) {
    //default value of match method
    match_method_ = 4;

    //read template image
    template_image_ = imread(image_file, CV_LOAD_IMAGE_COLOR);
}

std::vector<cv::Rect> TemplateMatchingPeopleDetector::Detect(cv::Mat *frame) {

     std::vector<cv::Rect> detected_people;
     cv::Mat image_result;

     // source image to display -> for debug issues only
     //cv::Mat image_display;
     //frame->copyTo( image_display );

     // create the result matrix
     int result_cols = frame->cols - template_image_.cols + 1;
     int result_rows = frame->rows - template_image_.rows + 1;

     image_result.create( result_rows, result_cols, CV_32FC1 );

     // do the matching and normalize
     matchTemplate( *frame, template_image_, image_result, match_method_ );
     normalize( image_result, image_result, 0, 1, cv::NORM_MINMAX, -1, Mat() );

     // localizing the best match with minMaxLoc
     double min_value; double max_value; cv::Point min_location; cv::Point max_location;
     cv::Point match_location;

     minMaxLoc( image_result, &min_value, &max_value, &min_location, &max_location, Mat() );


     // for SQDIFF and SQDIFF_NORMED, the best matches are lower values. For all the other methods, the higher the better
     if( match_method_  == CV_TM_SQDIFF || match_method_ == CV_TM_SQDIFF_NORMED )
       { match_location = min_location; }
     else
       { match_location = max_location; }

     // debug output
     //rectangle( image_display, match_location, cv::Point( match_location.x + template_image_.cols , match_location.y + template_image_.rows ), cv::Scalar::all(0), 2, 8, 0 );
     //rectangle( image_result, match_location, cv::Point( match_location.x + template_image_.cols , match_location.y + template_image_.rows ), cv::Scalar::all(0), 2, 8, 0 );

     //imshow( "Source image", image_display );
     //imshow( "Result image", image_result );

     // create the found rectangle
     cv::Rect detected_human(match_location.x, match_location.y, template_image_.cols, template_image_.rows);
     detected_people.push_back(detected_human);

    return detected_people;
}

std::vector<cv::Rect> TemplateMatchingPeopleDetector::DetectInROI(cv::Mat *frame, std::vector<cv::Rect> *rois) {

    std::vector<cv::Rect> detected_people;

    for( size_t i = 0; i < rois->size(); i++ ) {

        /*if(ROI.cols < template_image_.cols || ROI.rows < template_image_.rows) {

            continue;

        }*/

        cv::Rect* rescaled_roi = RescaleROI(&(rois->at(i)), template_image_.rows, template_image_.cols, frame->rows, frame->cols);
        cv::Mat ROI = frame->operator()( *rescaled_roi );


        std::vector<cv::Rect> detected_in_roi = Detect(&ROI);

        for (int k = 0; k < detected_in_roi.size(); k++) {
            detected_in_roi.at(k).x += rois->operator[](i).x;
            detected_in_roi.at(k).y += rois->operator[](i).y;

            detected_people.push_back(detected_in_roi.at(k));
        }

        detected_in_roi.clear();
    }

    return detected_people;
}
