
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

//std
#include <string>

//local
#include "../ObjectDetection/frame_detection_data.h"
#include "../ObjectDetection/element.h"

class Scenario {
    
public:

    /**
    * Detects a certain scenario. Must be overriden in subclasses.
    *
    * @param detected_objects The frame data with detected objects
    *
    * @return True when the circumstances for a certain scenario are met, false if not
    */
    virtual bool Detect(FrameDetectionData detected_objects) = 0;
    

    /**
    * Describes the detectable scenario with a human-readable string. Must be overriden in subclasses.
    *
    * @return A String that describes the detected scenario
    */
    virtual std::string GetScenarioInformation() = 0;


    /**
    * Computes the distance between two elements. Uses the distance between the position of the elements as default. Can be overriden in subclasses.
    *
    * @param first_element The first element
    * @param second_element The second element
    *
    * @return The distance between the elements
    */
    static float ComputeDistance(Element first_element, Element second_element);
    
    /**
     * Computes the distance between two elements' centers. Can be overriden in subclasses.
     *
     * @param first_element The first element
     * @param second_element The second element
     *
     * @return The distance between the center of the elements.
     */
    static float ComputeCenterDistance(Element first_element, Element second_element);

    /**
     * Computes whether the two elements overlap. As default, overlapping of one pixel in the bounding boxes of the elements is enough to return true. Can be overriden in subclasses.
     *
     * @param first_element The first element
     * @param second_element The second element
     *
     * @return True if elements overlap, false if not
     */
    static bool DoOverlap(Element first_element, Element second_element);

    /**
     * Computes whether the big element contains the small one 
     *
     * @param big_element The surrounding element
     * @param small_element The contained element
     *
     * @return True whether the big element contains the small one, false if not (equal size and position will be true)
     */
    static bool DoContain(Element big_element, Element small_element);


private:
    
    /**
     * Computes the distance between two points. Helper function for all distance functions. Can be overriden in subclasses.
     *
     * @param first_point The first point vector (x,y position)
     * @param second_point The second point vector (x,y position)
     *
     * @return The distance between the two points.
     */
    static float ComputePointDistance(std::vector<int> first_point, std::vector<int> second_point);
    

};


#endif // SCENARIO_H
