//
// Projectname: amos-ss16-proj5
//
// Created on 21-05-2016.
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


#ifndef __amos_ss16_proj5__frame_selector_factory__
#define __amos_ss16_proj5__frame_selector_factory__

#include <stdio.h>
#include "frame_selector.h"
class FrameSelectorFactory {
    
public:
    
    /**
     * Constructor
     *
     * @param file  The filename of the file to read
     */
    FrameSelectorFactory(std::string file);
    
    /**
     * Creates and returns the FrameSelector
     *
     *  @return the FrameSelector
     */
    FrameSelector* getFrameSelector();
    
    
private:
    /**
     * Checks if a filename ends wirh a given suffix
     *
     *@return true if filename ends with suffix, false if not
     */
    bool HasSuffix(const std::string &filename, const std::string &suffix);
    std::string file_name_;   ///< The full path file of the video file
    
};

#endif /* defined(__amos_ss16_proj5__frame_selector_factory__) */
