
//
// FrameDetectionData.h
// Projectname: amos-ss16-proj5
//
// Created on 02.06.2016.
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

#ifndef FRAME_DETECTION_DATA_H
#define FRAME_DETECTION_DATA_H


//std
#include <list>
#include <vector>
#include <map>
#include <string>

//element
#include "element.h"

class FrameDetectionData {
    
public:
    
    /**
     * Gets a list of elements with the given type
     *
     * @param type  The type of the elements
     *
     * @return The list with all elements of the given type
     */
    std::list<Element> GetElementsOfType(std::string type);

    /**
     * Adds a list of elements with a new type
     *
     * @param type  The type of the elements
     * @param elements  The list with elements
     *
     */
    void AddElementsOfType(std::string type, std::list<Element> elements);


private:
    
    //TODO: encapsulate type in own class?
    std::vector<std::string> types_;    ///< The vector with all existing types so far
    std::map<std::string, std::list<Element> > all_elements_;   ///< The map containing all elements of all types
};


#endif // FRAME_DETECTION_DATA_H
