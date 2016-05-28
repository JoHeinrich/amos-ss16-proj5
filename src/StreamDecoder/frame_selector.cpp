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

#include "frame_selector.h"

namespace patch{
    
    template < typename T > std::string to_string( const T& n ){
        
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
        
    }
    
}

FrameSelector::FrameSelector(std::string file){
    
    file_name_ = file;

    hdf_reader_ = new HDFReader(file);

    image_reader_ = new MsgCameraImageReader();

    // read hdf5 file
    hdf_reader_->ReadFile();
    
}

FrameSelector::~FrameSelector(){
    
    delete hdf_reader_;
    delete image_reader_;
    
}

void FrameSelector::ReadImage(unsigned int frame_index){
    
    // get the protobuf payload from hdf5 reader
    std::vector<int64_t> image_buffer = hdf_reader_->ReadOneImage(frame_index);
    int image_size = image_buffer.size();

    // convert to char array
    unsigned char* image = ConvertImageToArray(image_buffer);

    //convert imageBuffer to msgCameraImage and read image from protobuf
    pb::Grid::MsgCameraImage protobuf_image;
    protobuf_image.ParseFromArray(image,image_size);
    image_reader_->listInfosAboutMsgImage(protobuf_image);
    
}

void FrameSelector::ReadAllImages(){
    
    std::vector<std::vector<int64_t> > all_images = hdf_reader_->ReadAllImages();

    //all result images
    std::vector<pb::Grid::MsgCameraImage> result_images;

    for(int i = 0; i < all_images.size(); i++){
        
        // convert current image
        unsigned char* image = ConvertImageToArray(all_images.at(i));
        
        pb::Grid::MsgCameraImage protobuf_image;
        protobuf_image.ParseFromArray(image, all_images.at(i).size());
        result_images.push_back(protobuf_image);
        
    }

    for(int k = 0; k < result_images.size(); k++){
        
        image_reader_->listInfosAboutMsgImage(result_images.at(k));
        
    }

}

unsigned char* FrameSelector::ConvertImageToArray(std::vector<int64_t> image){

    int size = image.size();
    unsigned char *image_array = new unsigned char[size];

    for(int i = 0; i < size; i++){
        
        image_array[i] = static_cast<unsigned char>(image.at(i));
        
    }

    return image_array;
    
}
