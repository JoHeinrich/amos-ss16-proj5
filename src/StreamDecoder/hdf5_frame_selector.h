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

#ifndef HDF5FRAME_SELECTOR_H
#define HDF5FRAME_SELECTOR_H

// HDFReader
#include "hdf_reader.h"

//Protobuf Deserializer
#include "protobuf_image_wrapper.h"

// Image
#include "image.h"

#include <vector>


class HDF5FrameSelector{
    
public:
    
    /**
     * Constructor
     *
     * @param file  The filename of the hdf5 file to read
     */
    HDF5FrameSelector(std::string file);

    /**
     * Destructor
     */
    ~HDF5FrameSelector();
    
    /**
     * Reads one image at the given index from hdf5 file
     *
     * @param frame_index The frame index of the image
     *
     * @return The image object at the given frame index
     */
     Image ReadImage(unsigned int frame_index);

    
     /**
      * Returns number of containing images
      *
      * @return Count of images
      */
     int GetImageCount();
    
    
     /**
      * Reads all images 
      *
      * @return A vector with all image objects
      */
      std::vector<Image> ReadAllImages();

private:

      std::string file_name_;   ///< The full path file name of the hdf5 file
      HDFReader  *hdf_reader_;    ///< The dhf5 file reader

      /**
       * Converts a protobuf file from hdf reader to an array (needed for parsing it and for creating a msgCameraImage object)
       *
       * @param image The vector with the protobuf file buffer
       *
       * @return The array with the protobuf file buffer
       */
      unsigned char* ConvertProtobufFileToArray(std::vector<int64_t> file);
};

#endif // HDF5FRAME_SELECTOR_H
