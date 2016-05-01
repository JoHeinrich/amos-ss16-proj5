//
// HDFFileReaderExample.cpp
// Projectname: amos-ss16-proj5
//
// Created by Elisabeth Hoppe on 24.04.16.
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

#include "MainHeader.h"

#ifdef OLD_HEADER_FILENAME
#include <iostream.h>
#else
#include <iostream>
#endif
#include <string>
#include <vector>

#ifndef H5_NO_NAMESPACE
#ifndef H5_NO_STD
    using std::cout;
    using std::endl;
#endif  // H5_NO_STD
#endif

#include "H5Cpp.h"

#ifndef H5_NO_NAMESPACE
    using namespace H5;
#endif

const H5std_string FILE_NAME( "measurement_2016-04-08-13-27-15-507.hdf5" );
const H5std_string DATASET_NAME( "MFCImageRight" );

#include <sstream>

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}



int main0(void)
{

   // Try block to detect exceptions raised by any of the calls inside it
   try
   {

      // Turn off the auto-printing when failure occurs so that we can
      // handle the errors appropriately
      Exception::dontPrint();

      // create the file and open it with read-only access.
      H5File * file = new H5File( FILE_NAME, H5F_ACC_RDONLY );
      DataSet dataSet = file->openDataSet(DATASET_NAME);

	   // get the class of the datatype that is used by the dataset.
       H5T_class_t typeClass = dataSet.getTypeClass();


       // get the data space of the dataset for obtaining information about dimension, sizes, etc.
       DataSpace dataSpace = dataSet.getSpace();

       // get info about dataspace
       int dimNumber = dataSpace.getSimpleExtentNdims();
       hssize_t elemsNumber = dataSpace.getSimpleExtentNpoints();
       bool isSimple = dataSpace.isSimple();

       // get dimension size of each dimension
       hsize_t dimsOut[2];
       int nDims = dataSpace.getSimpleExtentDims(dimsOut, NULL);

       if(dimsOut[1] != 2)
       {
    	   //TODO exception handling
       }

       if(typeClass == H5T_INTEGER)
       {
    	   IntType intType = dataSet.getIntType();

    	   // get order of the int type
    	   H5std_string order_string;
    	   H5T_order_t order = intType.getOrder(order_string);

    	   // get size of int type
    	   size_t size = intType.getSize();

       }

       // read raw data (timestamp + imageid)
       // go to dataset with the imageid
       // read the dataset behind image id
       // = protobuf file

       // create buffer for reading the data
       int64_t buffer[dimsOut[0]][dimsOut[1]];

       // initialize
       for(int i = 0; i<dimsOut[0]; i++)
       {
    	   for(int j = 0; j<dimsOut[1]; j++)
    	   {
    		   buffer[i][j] = 0;
    	   }
       }


       // read buffer -> without input for memory data space the whole data space will be read

       dataSet.read(buffer, PredType::NATIVE_INT64);

       // read the image ids from the buffer

       // vector which holds all the image ids
       std::vector<int> vecImages;
       for(int i = 0; i<dimsOut[0]; i++)
       {
    	   vecImages.push_back(buffer[i][1]);
       }

       // open dataset for every image id; read it
       for(int i = 0; i < vecImages.size(); i++)
       {
    	   int currentId = vecImages.at(i);
    	   std::string sId = patch::to_string(currentId);
    	   DataSet currentImage = file->openDataSet(sId);

    	  // get the class of the datatype that is used by the dataset.
		  H5T_class_t typeClass = dataSet.getTypeClass();

		  // get the data space of the dataset for obtaining information about dimension, sizes, etc.
		  DataSpace dataSpace = dataSet.getSpace();

		  // get info about dataspace
		  int dimNumber = dataSpace.getSimpleExtentNdims();
		  hssize_t elemsNumber = dataSpace.getSimpleExtentNpoints();
		  bool isSimple = dataSpace.isSimple();

		  // get dimension size of each dimension
		  hsize_t dimsOut[1];
		  int nDims = dataSpace.getSimpleExtentDims(dimsOut, NULL);

		  if(typeClass != H5T_INTEGER)
		  {
			   // TODO exception handling
		  }


		  // create buffer for reading the image data
		  int64_t imageBuffer[dimsOut[0]];

		  // initialize
		  for(int i = 0; i<dimsOut[0]; i++)
		  {
			  imageBuffer[i] = 0;
		  }


		  // read buffer -> without input for memory data space the whole data space will be read

		  dataSet.read(imageBuffer, PredType::NATIVE_INT64);

		  // TODO give this data to protobuf deserializer

       }

       //close file
       file->close();

   }  // end of try block

   // catch failure caused by the H5File operations
   catch( FileIException error )
   {
      error.printError();
      return -1;
   }

   // catch failure caused by the DataSet operations
   catch( DataSetIException error )
   {
      error.printError();
      return -1;
   }

   // catch failure caused by the DataSpace operations
   catch( DataSpaceIException error )
   {
      error.printError();
      return -1;
   }

   // catch failure caused by the DataSpace operations
   catch( DataTypeIException error )
   {
      error.printError();
      return -1;
   }

   return 0;
}
