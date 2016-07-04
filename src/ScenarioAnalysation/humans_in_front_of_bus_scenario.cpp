
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

//std
#include <iostream>
#include <vector>

//local
#include "humans_in_front_of_bus_scenario.h"

bool HumansInFrontOfBusScenario::Detect(FrameDetectionData detected_objects){

    // get the detected elements (humans and vehicles)
    std::vector<Element> humans = detected_objects.GetElementsOfType(OBJECT_HUMAN);
    std::vector<Element> vehicles = detected_objects.GetElementsOfType(OBJECT_VEHICLE);

    //std:: cout << "Humans in Front of Bus Scenario: Number of humans = " << humans.size() << " Number of vehicles = " << vehicles.size() << std::endl;
    if(humans.size() != 0){

        if(vehicles.size() != 0){

            // check whether there are human elements which overlap with vehicle elements
            std::vector<Element>::const_iterator humans_iterator;

            for(humans_iterator = humans.begin(); humans_iterator != humans.end(); ++humans_iterator){

                Element current_human = *humans_iterator;

                 std::vector<Element>::const_iterator vehicles_iterator;

                 for(vehicles_iterator = vehicles.begin(); vehicles_iterator != vehicles.end(); ++vehicles_iterator){

                     bool overlapping = DoOverlap(current_human, *vehicles_iterator);
                     // std::cout << "Humans in front of bus OVERLAPPING: " << overlapping << std::endl;
                     if(overlapping){

                         return true;

                     }

                 }
            }

        }

        return false;
    }

    return false;
}

std::string HumansInFrontOfBusScenario::GetScenarioInformation(){

    return "Humans in front of bus scenario detected!";

}

