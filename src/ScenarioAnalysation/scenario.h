
// Projectname: amos-ss16-proj5
//
// Created on 03.06.2016.
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

#ifndef SCENARIO_H
#define SCENARIO_H

#include "../ObjectDetection/frame_detection_data.h"
#include "../ObjectDetection/element.h"

class Scenario {
    
public:

    /**
    * Detects a certain scenario. Must be overriden in subclasses.
    *
    * @param detected_objects The frame data with detected objects
    *
    * @return true whether the circumstances for a certain scenario are met, false if not
    */
    virtual bool Detect(FrameDetectionData detected_objects) = 0;
    
    /**
    * Computes the distance between two objects. Uses the distance between the position of the objects as default. Can be overriden in subclasses.
    *
    * @param first The first object
    * @param second The second object
    *
    * @return The distance between the objects
    */
    virtual float Distance(Element first, Element second);

    /**
    * Computes whether the two objects overlap. As default, overlapping of one pixel in the bounding boxes of the elements is enough to return true. Can be overriden in subclasses.
    *
    * @param first The first object
    * @param second The second object
    *
    * @return true whether there is an overlapping, false if not
    */
    virtual bool Overlap(Element first, Element second);

private:

};


#endif // SCENARIO_H
