//
// HDFReader.cpp
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

#include "hdf_reader.h"

#include <sstream>
#include <iostream>
#include <fstream>

namespace patch{
    
    template < typename T > std::string to_string( const T& n ){
        
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
        
    }
    
}

HDFReader::HDFReader(std::string file){
    
    file_name_ = file;
    data_set_name_images_ = "MFCImageRight";
    // data_set_name_z_values_ = "DisparityOverview";
    images_description_attribute_name_ = "Channel Description";
    images_description_ = "";
    
}

int HDFReader::ReadFile(){
    
    // Try block to detect exceptions raised by any of the calls inside it
    try{

        // Turn off the auto-printing when failure occurs so that we can
        // handle the errors appropriately
        Exception::dontPrint();

        // create the file and open it with read-only access.
        H5File * file = new H5File( file_name_, H5F_ACC_RDONLY );

        // get dataset with protobuf images
        DataSet data_set = file->openDataSet(data_set_name_images_);

        // get the class of the datatype that is used by the dataset.
        H5T_class_t type_class = data_set.getTypeClass();

        // get the data space of the dataset for obtaining information about dimension, sizes, etc.
        DataSpace data_space = data_set.getSpace();

        // get info about dataspace

        // number of dimensions
        int dimensions_number = data_space.getSimpleExtentNdims();

        // number of elements
        hssize_t elements_number = data_space.getSimpleExtentNpoints();

        // determine whether data space is a simple one ( = regular N-dimensional array of data points)
        bool is_simple = data_space.isSimple();

        // get dimension size of each dimension
        hsize_t dimensions_output[2];
        data_space.getSimpleExtentDims(dimensions_output, NULL);


        std::cout << " Number of dimensions : " << dimensions_number <<  " isSimple: " << is_simple <<
                     " Number of elements " << elements_number  << " Dimensions extent" << dimensions_output[0] << " " << dimensions_output[1] << std::endl;

        if(dimensions_output[1] != 2){
            
            std::cerr << "Wrong dimension " <<std::endl;
            return -1;
            
        }

        if(type_class != H5T_INTEGER){
            
            std::cerr << "Wrong data type" <<std::endl;
            return -1;
            
        }

        // read raw data (timestamp + imageid)

        // create buffer for reading the data
        int64_t buffer[dimensions_output[0]][dimensions_output[1]];

        // initialize
        for(int i = 0; i<dimensions_output[0]; i++){
            
            for(int j = 0; j<dimensions_output[1]; j++){
                
                buffer[i][j] = 0;
                
            }
            
        }


        // read buffer: without input for memory data space the whole data space will be read

        data_set.read(buffer, PredType::NATIVE_INT64);

        // read the image ids from the buffer

        for(int i = 0; i<dimensions_output[0]; i++){
            
            image_ids_.push_back(buffer[i][1]);
            
        }

        // image ids output
        for(int i = 0; i<image_ids_.size(); i++){
            
            std::cout << "image id " << buffer[i][1] << std::endl;
            
        }

        // get the (protobuf) channel description
        Attribute description_attribute = data_set.openAttribute(images_description_attribute_name_);

        DataType description_type = description_attribute.getDataType();

        description_attribute.read(description_type, images_description_);

        std::cout << "Description: " << images_description_ << std::endl;

        //close file
        file->close();

        std::cout << "Number of protobuf files  " << image_ids_.size() << std::endl;

    }  // end of try block

    // catch failure caused by the H5File operations
    catch( FileIException error ){
        
        error.printError() ;
        return -1;
        
    }

    // catch failure caused by the DataSet operations
    catch( DataSetIException error ){
        
        error.printError() ;
        return -1;
        
    }

    // catch failure caused by the DataSpace operations
    catch( DataSpaceIException error ){
        
        error.printError();
        return -1;
        
    }

    // catch failure caused by the DataSpace operations
    catch( DataTypeIException error ){
        
        error.printError() ;
        return -1;
        
    }

    return 0;
}

std::vector<int64_t> HDFReader::ReadOneImage(unsigned int image_index){
    
    // return value
    std::vector<int64_t> current_image;

    // Try block to detect exceptions raised by any of the calls inside it
    try{

        // Turn off the auto-printing when failure occurs so that we can
        // handle the errors appropriately
        Exception::dontPrint();

        // create the file and open it with read-only access.
        H5File * file = new H5File( file_name_, H5F_ACC_RDONLY );

        // open the data set behind current iamge id
        if(image_index >= image_ids_.size()){
            
            image_index = 0;
            
        }
        std::string string_id = patch::to_string(image_ids_.at(image_index));
        DataSet current_image_data_set = file->openDataSet(string_id);

        // get the class of the datatype that is used by the dataset.
        H5T_class_t image_type_class = current_image_data_set.getTypeClass();


        if(image_type_class != H5T_INTEGER){
            
            std::cerr << "Wrong data type" <<std::endl;
            return current_image;
            
        }

        // get the data space of the dataset for obtaining information about dimension, sizes, etc.
        DataSpace image_data_space = current_image_data_set.getSpace();

        // get dimension size of each dimension
        hsize_t image_dimensions_output[1];
        image_data_space.getSimpleExtentDims(image_dimensions_output, NULL);

        int size_image_buffer = image_dimensions_output[0];
        // create buffer for reading the image buffer
        int64_t* image_buffer = new int64_t[size_image_buffer];
/*=======
            //open file for image
            //std::ofstream file;
            //file.open("/home/anyuser/Desktop/file.txt");


            std::vector<int64_t> vecCurrentImage;
            for(int i = 0; i < sizeImageBuffer; i++)
            {
                vecCurrentImage.push_back(imageBuffer[i]);
                //file << imageBuffer[i];

            }
            //file.close();
            // delete buffer
            delete []imageBuffer;
>>>>>>> master */

        // initialize image buffer
        for(int k = 0; k < size_image_buffer; k++){
            
            image_buffer[k] = 0;
            
        }

        // read buffer: without input for memory data space the whole data space will be read

        std::cout << "Reading image buffer: image id:" << image_index << std::endl;
        current_image_data_set.read(image_buffer, PredType::NATIVE_INT64);


        for(int i = 0; i < size_image_buffer; i++){
            
            current_image.push_back(image_buffer[i]);
            
        }

        // delete buffer
        delete []image_buffer;


        //close file
        file->close();


    }  // end of try block

    // catch failure caused by the H5File operations
    catch( FileIException error ){
        
        error.printError() ;
        //return;
        
    }

    // catch failure caused by the DataSet operations
    catch( DataSetIException error ){
        
        error.printError() ;
        //return;
        
    }

    // catch failure caused by the DataSpace operations
    catch( DataSpaceIException error ){
        
        error.printError();
        //return;
        
    }

    // catch failure caused by the DataSpace operations
    catch( DataTypeIException error ){
        
        error.printError() ;
        //return;
        
    }

    return current_image;
}

std::vector<std::vector<int64_t> > HDFReader::ReadAllImages(){

    std::vector<std::vector<int64_t> > all_images;

    for(int i = 0; i < this->GetNumberOfImages(); i++){
        
        std::vector<int64_t> current_image = this->ReadOneImage(i);

        if( !(current_image.size() == 0) ){
            
             all_images.push_back(current_image);
            
        }

    }

    std::cout << "Read all images; number of read files: " << all_images.size() << std::endl;
    return all_images;
}

int HDFReader::GetNumberOfImages(){
    
    return image_ids_.size();
    
}

std::string HDFReader::GetImageFilesDescription(){
    
    return images_description_;
    
}

/*std::vector<std::vector<int64_t> > GetZValues(){
 
    return z_values_;
 
}*/

/*std::vector<int64_t> GetZValueBuffer(unsigned int index){
 
    if(index >= z_values_.size()){
 
        // default value
        return z_values_.at(0);
 
    }

    return z_values_.at(index);
 
}*/

