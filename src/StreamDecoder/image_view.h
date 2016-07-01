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

#ifndef IMAGE_VIEW_H
#define IMAGE_VIEW_H

// local
#include "image.h"
#include "image_view.h"
#include "../ObjectDetection/element.h"

class ImageView{
	
public:

    /**
     * Shows the image with help of OpenCV.
     *
     * @param image The image object that will be shown
     *
     */
	void ShowImage(Image * image);
	
    /**
     * Shows the image with help of OpenCV a given time
     *
     * @param image The image object that will be shown
     * @param sleep_time in ms. The view sleeps for this milliseconds and waits for any key to be pressed.  0 is for waiting infinitely
     */
    void ShowImage(Image * image, int sleep_time);

    /**
     * Shows the image with help of OpenCV and the detections in this image.
     *
     * @param image The image object that will be shown
     * @param people_detections    The vector with detected people elements in this image
     * @param vehicle_detections    The vector with detected vehicle elements in this image
     */
    void ShowImageAndDetections(Image * image, std::vector<Element> people_detections, std::vector<Element> vehicle_detections);
  
};

#endif // IMAGE_VIEW_H
