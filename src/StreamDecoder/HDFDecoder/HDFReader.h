
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

class HDFReader
{
public:
    
    /**
     * Constructor
     *
     * @param file  The filename of the file to read
     */
    HDFReader(std::string file);
    
    /**
    * Reads the given hdf5 file and fills the information into the members.
    */
    int readFile();
    
    /**
     *  Gets the vector with image buffers
     *
     *  @return  The vector with the protobuf image buffers
     */
    std::vector<std::vector<int64_t> > getImageFiles();
    
    /**
     *  Gets an image buffer at the specialized index position
     * 
     *  @param iIndex The index of the desired buffer
     *
     *  @return The vector with buffer at index iIndex, null when thi sindex doesn't exist
     */
    std::vector<int64_t> getImageBuffer(int iIndex);
    
    /**
     *  Gets the vector with z values of all image buffers
     *
     *  @return  The vector with the z values of image buffers
     */
    //std::vector<std::vector<int64_t> > getZValues();
    
    /**
     *  Gets an z values buffer at the specialized index position
     *
     *  @param iIndex The index of the desired buffer
     *
     *  @return The vector with z values buffer at index iIndex, null when thi sindex doesn't exist
     */
    //std::vector<int64_t> getZValueBuffer(int iIndex);

    
private:
    
    std::vector<std::vector<int64_t> > m_vecImageFiles; ///< Vector of protobuf files that represent the image buffers
    
    //std::vector<std::vector<int64_t> > m_vecZValues;  ///< z values for the protobuf files
    
    std::vector<int> m_vecImageIds;     ///< Vector with all image ids
    
    std::string m_FileName;     ///< The file name
    
    std::string m_DataSetNameImages;   ///< The data set name of images buffer
    
    //std::string m_DataSetNameZValues;  ///< The data set name of z values
    
};
