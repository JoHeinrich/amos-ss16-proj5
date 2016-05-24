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

    m_hdfReader = new HDFReader(file);

    m_ImageReader = new MsgCameraImageReader();

    // read hdf5 file
    m_hdfReader->readFile();


}

FrameSelector::~FrameSelector()
{
    delete m_hdfReader;
    delete m_ImageReader;
}

void FrameSelector::readImage(unsigned int frameIndex)
{
    // get the protobuf payload from hdf5 reader
    std::vector<int64_t> imageBuffer = m_hdfReader->readOneImage(frameIndex);
    int imageSize = imageBuffer.size();

    // convert to char array
    unsigned char* image = convertImageToArray(imageBuffer);

    //convert imageBuffer to msgCameraImage and read image from protobuf
    pb::Grid::MsgCameraImage protobufImage;
    protobufImage.ParseFromArray(image,imageSize);
    m_ImageReader->listInfosAboutMsgImage(protobufImage);

}

void FrameSelector::readAllImages()
{
    std::vector<std::vector<int64_t> > allImages = m_hdfReader->readAllImages();

    //all result images
    std::vector<pb::Grid::MsgCameraImage> resultImages;

    for(int i = 0; i < allImages.size(); i++)
    {
        // convert current image
        unsigned char* image = convertImageToArray(allImages.at(i));

        pb::Grid::MsgCameraImage protobufImage;
        protobufImage.ParseFromArray(image, allImages.at(i).size());
        resultImages.push_back(protobufImage);
    }

    for(int k = 0; k < resultImages.size(); k++)
    {
        m_ImageReader->listInfosAboutMsgImage(resultImages.at(k));
    }

}

unsigned char* FrameSelector::convertImageToArray(std::vector<int64_t> image)
{

    int size = image.size();
    unsigned char *imageArray = new unsigned char[size];

    for(int i = 0; i < size; i++)
    {
        imageArray[i] = static_cast<unsigned char>(image.at(i));
    }

    return imageArray;
}
