//
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

#include <string>
#include "../StreamDecoder/hdf5_frame_selector.h"
#include "../StreamDecoder/frame_selector.h"
#include "../StreamDecoder/frame_selector_factory.h"
class Controller{

public:
    /**
     * Opens a HDF5Videofile and displays it
     *
     *@param videofile path to the video file
     */
    void PlayHDFAsVideo(std::string videofile);
    
    /**
     * Opens a HDF5Videofile, calls the Analyser and displays the video and the Analyser-results
     *
     *@param videofile path to the video file
     */
    void AnalyseHDF5Video(std::string videofile);

    /**
     * Saves all images as jepg to disc
     *
     *@param videofile path to the video file
     */
    void SaveAllImagesAsJPEG(std::string videofile);
};