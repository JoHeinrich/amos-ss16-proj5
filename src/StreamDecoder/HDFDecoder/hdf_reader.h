
//
// HDFReader.h
// Projectname: amos-ss16-proj5
//
// Created on 10.05.2016.
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


//std
#ifdef OLD_HEADER_FILENAME
#include <iostream.h>
#else
#include <iostream>
#endif
#include <string>
#include <vector>

//hdf5
#ifndef H5_NO_NAMESPACE
#ifndef H5_NO_STD
#endif  // H5_NO_STD
#endif

#include "H5Cpp.h"

#ifndef H5_NO_NAMESPACE
using namespace H5;
#endif

class HDFReader {
    
public:
    
    /**
     * Constructor
     *
     * @param file  The filename of the file to read
     */
    HDFReader(std::string file);
    
    /**
    * Reads the given hdf5 file and fills the image ids and description string information.
    *
    *  @return 0 if everything went good; 0 if it failed
    */
    int ReadFile();
	
    /**
     *  Reads one image buffer at the given index.
     *
     *  @param  image_index The index of the image buffer to be read. If it does not exist, the first image is read
     *  @return The vector with image buffer
     */
    std::vector<int64_t> ReadOneImage(unsigned int image_index);

    /**
     *  Gets the vector with all image buffers
     *
     *  @return  The vector with the protobuf image buffers
     */
    std::vector<std::vector<int64_t> > ReadAllImages();

    /**
     *  Gets the total number of protobuf images in the file
     *
     *  @return  The number of protobuf images
     */
    int GetNumberOfImages();


     /**
     *  Gets the (protobuf) description attribute of the images buffer.
     *
     *  @return The string with the protobuf description.
     */	
    std::string GetImageFilesDescription();
    
    /**
     *  Gets the vector with z values of all image buffers
     *
     *  @return  The vector with the z values of image buffers
     */
    //std::vector<std::vector<int64_t> > GetZValues();
    
    /**
     *  Gets an z values buffer at the specialized index position
     *
     *  @param iIndex The index of the desired buffer
     *
     *  @return The vector with z values buffer at index iIndex, the first buffer when the index doesn't exist
     */
    //std::vector<int64_t> GetZValueBuffer(unsigned int index);

    
private:
    
    //std::vector<std::vector<int64_t> > z_values_;  ///< z values for the protobuf files

    std::string images_description_;       ///< The (protobuf) description string of the images
    
    std::vector<int> image_ids_;     ///< Vector with all image ids
    
    std::string file_name_;     ///< The file name
    
    std::string data_set_name_images_;   ///< The data set name of images buffer

    std::string images_description_attribute_name_;   ///< The name of the attribute which contains the (protobuf) description string
    
    //std::string data_set_name_z_values_;  ///< The data set name of z values
    
};
