
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

#ifndef ELEMENT_H
#define ELEMENT_H

#include <vector>

class Element {
    
public:
    
    /**
     * Constructor
     *
     * @param  position     The vector with position of the topleft corner of the element (x, y)
     * @param  box_size     The vector with the size of the bounding box of the element (width, height)
     */
    Element(std::vector<int> position, std::vector<int> box_size);


    /**
     *  Gets the position of the element
     *
     *  @return The vector with the position of the element
     */
    std::vector<int> GetPosition();

    /**
     *  Gets the size of the bounding box of the element
     *
     *  @return The vector with the size of the bounding box of the element
     */
    std::vector<int> GetBoxSize();

    /**
    * Returns the minimum x value that is contained in the Boundingbox
    */
    int MinX();

    /**
    * Returns the minimum y value that is contained in the Boundingbox
    */
    int MinY();

    /**
    * Returns the maximum x value that is contained in the Boundingbox
    */
    int MaxX();

    /**
    * Returns the maximum value that is contained in the Boundingbox
    */
    int MaxY();

    /**
    * Returns the x value of center of the Boundingbox
    */
    int CenterX();

    /**
    * Returns the y value of center of the Boundingbox
    */
    int CenterY();


private:
    
   std::vector<int> position_;  ///< The vector containing the position of the element
   std::vector<int> box_size_;  ///< The vector contatining the width and height of the bounding box of the element
    
};


#endif // ELEMENT_H
