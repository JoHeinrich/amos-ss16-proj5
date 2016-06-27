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
    match_method_ = 5;

    //read template image
    template_image_ = imread(image_file, CV_LOAD_IMAGE_COLOR);
}

std::vector<cv::Rect> TemplateMatchingPeopleDetector::Detect(cv::Mat *frame) {

    std::vector<cv::Rect> detectedPeople;
    cv::Mat image_result;

     /// Source image to display
     cv::Mat image_display;
     frame->copyTo( image_display );

     /// Create the result matrix
     int result_cols = frame->cols - template_image_.cols + 1;
     int result_rows = frame->rows - template_image_.rows + 1;

     image_result.create( result_rows, result_cols, CV_32FC1 );

     /// Do the Matching and Normalize
     matchTemplate( *frame, template_image_, image_result, match_method_ );
     normalize( image_result, image_result, 0, 1, cv::NORM_MINMAX, -1, Mat() );

     /// Localizing the best match with minMaxLoc
     double minVal; double maxVal; cv::Point minLoc; cv::Point maxLoc;
     cv::Point matchLoc;

     minMaxLoc( image_result, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );


     /// For SQDIFF and SQDIFF_NORMED, the best matches are lower values. For all the other methods, the higher the better
     if( match_method_  == CV_TM_SQDIFF || match_method_ == CV_TM_SQDIFF_NORMED )
       { matchLoc = minLoc; }
     else
       { matchLoc = maxLoc; }

     /// Show me what you got
     rectangle( image_display, matchLoc, cv::Point( matchLoc.x + template_image_.cols , matchLoc.y + template_image_.rows ), cv::Scalar::all(0), 2, 8, 0 );
     rectangle( image_result, matchLoc, cv::Point( matchLoc.x + template_image_.cols , matchLoc.y + template_image_.rows ), cv::Scalar::all(0), 2, 8, 0 );

     imshow( "Source image", image_display );
     imshow( "Result image", image_result );


    return detectedPeople;
}
