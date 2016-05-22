//
// FrameSelector.cpp
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


#include <sstream>

#include "FrameSelector.h"

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

FrameSelector::FrameSelector(std::string file)
{
    m_FileName = file;
    // create members
    m_hdfReader = new HDFReader(file);

    //TODO create protobuf reader

    // read hdf5 file
    m_hdfReader->readFile();


}

FrameSelector::~FrameSelector()
{
    delete m_hdfReader;
    //delete m_protobufReader;
}

void FrameSelector::readImage(unsigned int frameIndex)
{
    // get the protobuf payload from hdf5 reader
    std::vector<int64_t> imageBuffer = m_hdfReader->getImageBuffer(frameIndex);

    //TODO convert imageBuffer to msgCameraImage and read image from protobuf

}

void FrameSelector::readAllImages()
{
    // for every image buffer from the hdf5 decoder: read the image from protobuf and add it to the return vector

    int numberFiles = m_hdfReader->getImageFiles().size();

    for(int i = 0; i < numberFiles; i++)
    {
        std::vector<int64_t> currentImageBuffer = m_hdfReader->getImageBuffer(i);

        //TODO read from protobuf...
    }

}
