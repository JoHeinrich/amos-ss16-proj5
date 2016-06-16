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

#ifndef IMAGE_H
#define IMAGE_H


#include <opencv2/opencv.hpp>

using namespace cv;

class Image{
    
public:
    
    /**
     * Constructor
     *
     * @param payload  The payload of the image
     * @param width  The width of the image
     * @param height  The height of the image
     */
     Image(const std::string payload, int width, int height);

    /**
     * Destructor
     */
    ~Image();
    
     /**
      * Gets the payload
      *
      * @return The image payload
      */
      std::string GetImagePayload();

     /**
      * Gets the image width
      *
      * @return The image width
      */
      int GetImageWidth();

     /**
      * Gets the image height
      *
      * @return The image height
      */
      int GetImageHeight();

     /**
      * Gets the bayer image
      *
      * @return The bayer image as opencv::Mat object
      */
      Mat GetBGGRImage();

      /**
      * Gets the bgr image 
      *
      * @return The bgr image as opencv::Mat object
      */
      Mat GetBGRImage();

     /**
      * Returns the payload as RGB image
      *
      */
      Mat GetRGBImage();
    

private:
      std::string image_payload_;   ///< The string containing the payload of the image
      unsigned char* image_payload_array_;  ///< The image payload as char array
      int image_width_;		///< The image width
      int image_height_;	///< The image height
    
      /**
      * Converts the image payload to a char array (needed for conversion to Mat objects).
      */
      void ConvertToArray();

  
};

#endif //IMAGE_H
