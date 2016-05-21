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

#include "HDFReader.h"

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

HDFReader::HDFReader(std::string file)
{
    m_FileName = file;
    m_DataSetNameImages = "MFCImageRight";
    // m_DataSetNameZValues = "DisparityOverview";
    m_ImagesDescriptionAttributeName = "Channel Description";
    m_ImagesDescription = "";
}

int HDFReader::readFile()
{
    // Try block to detect exceptions raised by any of the calls inside it
    try
    {

        // Turn off the auto-printing when failure occurs so that we can
        // handle the errors appropriately
        Exception::dontPrint();

        // create the file and open it with read-only access.
        H5File * pFile = new H5File( m_FileName, H5F_ACC_RDONLY );

        // get dataset with protobuf images
        DataSet dataSet = pFile->openDataSet(m_DataSetNameImages);

        // get the class of the datatype that is used by the dataset.
        H5T_class_t typeClass = dataSet.getTypeClass();

        // get the data space of the dataset for obtaining information about dimension, sizes, etc.
        DataSpace dataSpace = dataSet.getSpace();

        // get info about dataspace

        // number of dimensions
        int dimNumber = dataSpace.getSimpleExtentNdims();

        // number of elements
        hssize_t elemsNumber = dataSpace.getSimpleExtentNpoints();

        // determine whether data space is a simple one ( = regular N-dimensional array of data points)
        bool isSimple = dataSpace.isSimple();

        // get dimension size of each dimension
        hsize_t dimsOut[2];
        int nDims = dataSpace.getSimpleExtentDims(dimsOut, NULL);


        std::cout << " Number of dimensions : " << dimNumber <<  " isSimple: " << isSimple <<
                     " Number of elements " << elemsNumber << " Dimensions extent" << dimsOut[0] << " " << dimsOut[1] << std::endl;

        if(dimsOut[1] != 2)
        {
            std::cerr << "Wrong dimension " <<std::endl;
            return -1;
        }

        /*if(typeClass == H5T_INTEGER)
        {
            //IntType intType = dataSet.getIntType();

            // get order of the int type
            //H5std_string order_string;
            //std::string order_string;
            //H5T_order_t order = intType.getOrder(order_string);

            // get size of int type
            //size_t size = intType.getSize();


            //std::cout << "order-string: " << order_string << "int type size: "<< size << std::endl;

        }*/

        if(typeClass != H5T_INTEGER)
        {
            std::cerr << "Wrong data type" <<std::endl;
            return -1;
        }

        // read raw data (timestamp + imageid)

        // create buffer for reading the data
        int64_t buffer[dimsOut[0]][dimsOut[1]];

        /*int64_t ** buffer = new int64_t * [dimsOut[0]];

        for(int i = 0; i < dimsOut[0]; i++)
        {
            buffer[i] = new int64_t[dimsOut[1]];
        }*/

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

        for(int i = 0; i<dimsOut[0]; i++)
        {
            m_vecImageIds.push_back(buffer[i][1]);
        }

        // image ids output
        for(int i = 0; i<m_vecImageIds.size(); i++)
        {
            std::cout << "image id " << buffer[i][1] << std::endl;
        }

        // get the (protobuf) channel description
        Attribute descriptionAttr = dataSet.openAttribute(m_ImagesDescriptionAttributeName);

        DataType descriptionType = descriptionAttr.getDataType();

        descriptionAttr.read(descriptionType, m_ImagesDescription);

        std::cout << "Description: " << m_ImagesDescription << std::endl;


        // open dataset for every image id and read it
        for(int i = 0; i < m_vecImageIds.size(); i++)
        {
            int currentId = m_vecImageIds.at(i);
            std::string sId = patch::to_string(currentId);
            DataSet currentImage = pFile->openDataSet(sId);

            // get the class of the datatype that is used by the dataset.
            H5T_class_t imageTypeClass = currentImage.getTypeClass();

            if(imageTypeClass != H5T_INTEGER)
            {
                std::cerr << "Wrong data type" <<std::endl;
                return -1;
            }

            // get the data space of the dataset for obtaining information about dimension, sizes, etc.
            DataSpace imageDataSpace = currentImage.getSpace();

            // get info about dataspace
            //int dimNumber = dataSpace.getSimpleExtentNdims();
            // hssize_t elemsNumber = dataSpace.getSimpleExtentNpoints();
            //bool isSimple = dataSpace.isSimple();

            // get dimension size of each dimension
            hsize_t imageDimsOut[1];
            int nDims = imageDataSpace.getSimpleExtentDims(imageDimsOut, NULL);

            //std::cout << "dimsOut: " << imageDimsOut[0] <<  " nDims: " << nDims << std::endl;

            int sizeImageBuffer = imageDimsOut[0];
            // create buffer for reading the image buffer
            int64_t* imageBuffer = new int64_t[sizeImageBuffer];
            //int64_t imageBuffer[imageDimsOut[0]];

            // initialize
            for(int k = 0; k<sizeImageBuffer; k++)
            {
                imageBuffer[k] = 0;
                 //std::cout << " i: " << i << imageBuffer[i] << "      ";
            }



            // read buffer -> without input for memory data space the whole data space will be read

            std::cout << "Reading image buffer: " << i << " image id:" << m_vecImageIds.at(i) << std::endl;
            currentImage.read(imageBuffer, PredType::NATIVE_INT64);


            std::vector<int64_t> vecCurrentImage;
            for(int i = 0; i < sizeImageBuffer; i++)
            {
                vecCurrentImage.push_back(imageBuffer[i]);
            }

            // delete buffer
            delete []imageBuffer;

            m_vecImageFiles.push_back(vecCurrentImage);

        }

        //close file
        pFile->close();

        std::cout << "Number of protobuf files  " << m_vecImageFiles.size() << std::endl;

    }  // end of try block

    // catch failure caused by the H5File operations
    catch( FileIException error )
    {
         error.printError() ;
        return -1;
    }

    // catch failure caused by the DataSet operations
    catch( DataSetIException error )
    {
        error.printError() ;
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
        error.printError() ;
        return -1;
    }

    return 0;
}

std::vector<std::vector<int64_t> > HDFReader::getImageFiles()
{
    return m_vecImageFiles;
}

std::vector<int64_t> HDFReader::getImageBuffer(unsigned int iIndex)
{
    if(iIndex >= m_vecImageFiles.size())
    {
        // default value
        return m_vecImageFiles.at(0);
    }

    return m_vecImageFiles.at(iIndex);
}

 std::string HDFReader::getImageFilesDescription()
 {
     return m_ImagesDescription;
 }

/*std::vector<std::vector<int64_t> > getZValues()
{
    return m_vecZValues;
}*/

/*std::vector<int64_t> getZValueBuffer(unsigned int iIndex)
{
    if(iIndex >= m_vecZValues.size())
    {
        // default value
        return m_vecZValues.at(0);
    }

    return m_vecZValues.at(index);
}*/

