//
// frame_selector.cpp
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

    // read hdf5 file
    hdf_reader_->ReadFile();
    
}

FrameSelector::~FrameSelector(){
    
    delete hdf_reader_;

}

Image FrameSelector::ReadImage(unsigned int frame_index){
    
    // get the protobuf payload from hdf5 reader
    std::vector<int64_t> protobuf_file_buffer = hdf_reader_->ReadOneProtobufFile(frame_index);
    int protobuf_file_size = static_cast<int>(protobuf_file_buffer.size());

    // convert to char array
    unsigned char* file = ConvertProtobufFileToArray(protobuf_file_buffer);

    //convert protobuf file buffer to msgCameraImage and read image from protobuf file
    ProtobufImageWrapper protobuf_image;
    protobuf_image.ParseFromArray(file, protobuf_file_size);

    // create an Image from msgCameraImage
    Image result_image(protobuf_image.GetImagePayload(), protobuf_image.GetImageWidth(), protobuf_image.GetImageHeight());

    std::cout << "Protobuf file: WIDTH: " << result_image.GetImageWidth() << " HEIGHT: " << result_image.GetImageHeight() << std::endl;
    std::cout << " Size of payload: " << result_image.GetImagePayload().size() << std::endl;

    return result_image;

}

int FrameSelector::GetImageCount(){
    return hdf_reader_->GetNumberOfProtobufFiles();
}

std::vector<Image> FrameSelector::ReadAllImages(){
    
    std::vector<std::vector<int64_t> > all_protobuf_files = hdf_reader_->ReadAllProtobufFiles();

    //all result images
    std::vector<Image> result_images;

    for(int i = 0; i < all_protobuf_files.size(); i++){
        
        // convert current image
        unsigned char* file = ConvertProtobufFileToArray(all_protobuf_files.at(i));
        
        ProtobufImageWrapper protobuf_image;
        protobuf_image.ParseFromArray(file, static_cast<int>(all_protobuf_files.at(i).size()));

        Image current_image(protobuf_image.GetImagePayload(), protobuf_image.GetImageWidth(), protobuf_image.GetImageHeight());

        result_images.push_back(current_image);
        
    }

    return result_images;
}

unsigned char* FrameSelector::ConvertProtobufFileToArray(std::vector<int64_t> file){

    long size = file.size();
    unsigned char *file_array = new unsigned char[size];

    for(long i = 0; i < size; i++){
        
        file_array[i] = static_cast<unsigned char>(file.at(i));
        
    }
    return file_array;
}

bool HasSuffix(std::string &filename, std::string &suffix){
    return filename.compare(filename.size() - suffix.size(), suffix.size(), suffix) == 0;
}
