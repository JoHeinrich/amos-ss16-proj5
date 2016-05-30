//
// hdf_reader.cpp
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
    data_set_name_protobuf_files_ = "MFCImageRight";
    // data_set_name_z_values_ = "DisparityOverview";
    protobuf_files_description_attribute_name_ = "Channel Description";
    protobuf_files_description_ = "";
    
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
        DataSet data_set = file->openDataSet(data_set_name_protobuf_files_);

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
            
            protobuf_file_ids_.push_back(buffer[i][1]);
            
        }

        // image ids output
        /*for(int i = 0; i<protobuf_file_ids_.size(); i++){
            
            std::cout << "image id " << buffer[i][1] << std::endl;
            
        }*/

        // get the (protobuf) channel description
        Attribute description_attribute = data_set.openAttribute(protobuf_files_description_attribute_name_);

        DataType description_type = description_attribute.getDataType();

        description_attribute.read(description_type, protobuf_files_description_);

        //std::cout << "Description: " << protobuf_files_description_ << std::endl;

        //close file
        file->close();

        std::cout << "Number of protobuf files  " << protobuf_file_ids_.size() << std::endl;

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

std::vector<int64_t> HDFReader::ReadOneProtobufFile(unsigned int index){
    
    // return value
    std::vector<int64_t> current_protobuf_file;

    // Try block to detect exceptions raised by any of the calls inside it
    try{

        // Turn off the auto-printing when failure occurs so that we can
        // handle the errors appropriately
        Exception::dontPrint();

        // create the file and open it with read-only access.
        H5File * file = new H5File( file_name_, H5F_ACC_RDONLY );

        // open the data set behind current iamge id
        if(index >= protobuf_file_ids_.size()){
            
            index = 0;
            
        }

        std::string string_id = patch::to_string(protobuf_file_ids_.at(index));
        DataSet current_protobuf_file_data_set = file->openDataSet(string_id);

        // get the class of the datatype that is used by the dataset.
        H5T_class_t protobuf_file_type_class = current_protobuf_file_data_set.getTypeClass();


        if(protobuf_file_type_class != H5T_INTEGER){
            
            std::cerr << "Wrong data type" <<std::endl;
            return current_protobuf_file;
            
        }

        // get the data space of the dataset for obtaining information about dimension, sizes, etc.
        DataSpace protobuf_file_data_space = current_protobuf_file_data_set.getSpace();

        // get dimension size of each dimension
        hsize_t protobuf_file_dimensions_output[1];
        protobuf_file_data_space.getSimpleExtentDims(protobuf_file_dimensions_output, NULL);

        int size_protobuf_file_buffer = protobuf_file_dimensions_output[0];
        // create buffer for reading the image buffer
        int64_t* protobuf_file_buffer = new int64_t[size_protobuf_file_buffer];

        // initialize image buffer
        for(int k = 0; k < size_protobuf_file_buffer; k++){
            
            protobuf_file_buffer[k] = 0;
            
        }

        // read buffer: without input for memory data space the whole data space will be read

        std::cout << "Reading protobuf file : file id:" << index << std::endl;
        current_protobuf_file_data_set.read(protobuf_file_buffer, PredType::NATIVE_INT64);


        for(int i = 0; i < size_protobuf_file_buffer; i++){
            
            current_protobuf_file.push_back(protobuf_file_buffer[i]);
            
        }

        // delete buffer
        delete []protobuf_file_buffer;


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

    return current_protobuf_file;
}

std::vector<std::vector<int64_t> > HDFReader::ReadAllProtobufFiles(){

    std::vector<std::vector<int64_t> > all_protobuf_files;

    for(int i = 0; i < this->GetNumberOfProtobufFiles(); i++){
        
        std::vector<int64_t> current_protobuf_file = this->ReadOneProtobufFile(i);

        if( !(current_protobuf_file.size() == 0) ){
            
             all_protobuf_files.push_back(current_protobuf_file);
            
        }

    }

    std::cout << "Read all protobuf files; number of read files: " << all_protobuf_files.size() << std::endl;
    return all_protobuf_files;
}

int HDFReader::GetNumberOfProtobufFiles(){
    
    return protobuf_file_ids_.size();
    
}

std::string HDFReader::GetProtobufFilesDescription(){
    
    return protobuf_files_description_;
    
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

