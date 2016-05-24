
//
// FrameSelector.h
// Projectname: amos-ss16-proj5
//
// Created on 21.05.2016.
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

//HDFReader
#include "HDFReader.h"

//Protobuf Deserializer
#include "msg_cameraimage_reader.h"


class FrameSelector
{
public:
    
    /**
     * Constructor
     *
     * @param file  The filename of the hdf5 file to read
     */
    FrameSelector(std::string file);

    /**
     * Destructor
     */
    ~FrameSelector();
    
    /**
     * Reads one image at the given index from hdf5 file
     *
     * @param frameIndex The frame index of the image
     */
     void readImage(unsigned int frameIndex);

     /**
      * Reads all images 
      */
      void readAllImages();

private:
      std::string m_FileName;   ///< The full path file name of the hdf5 file
      HDFReader  *m_hdfReader;    ///< The dhf5 file reader
      MsgCameraImageReader  *m_ImageReader;   ///< The protobuf file reader

      /**
       * Converts an image from hdf reader to an array (needed for parsing it with protobuf reader)
       *
       * @param image The vector with the image buffer
       *
       * @return The array with the image buffer
       */
      unsigned char* convertImageToArray(std::vector<int64_t> image);
     
  
};
