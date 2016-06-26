
// Projectname: amos-ss16-proj5
//
// Created on 06-06-2016.
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
#include "analyser.h"
#include "humans_in_front_of_bus_scenario.h"
#include "scenario.h"
#include "../ObjectDetection/frame_detection_data.h"
#include "../ObjectDetection/element.h"


using namespace std;

/*#ifndef COMBINE
int main(int argc, const char* argv[]) {

    if (argc > 1 ){

        cerr << "Usage:  " << argv[0] << " no parameters " << endl;
        return -1;

    }

    std::vector<Scenario*> possible_scenarios;
    possible_scenarios.push_back(new HumansInFrontOfBusScenario());

    Analyser analyser(possible_scenarios);

    // create fake detected elements for test issues
    std::vector<int> human_position;
    std::vector<int> human_size;

    human_position.push_back(10);
    human_position.push_back(10);

    human_size.push_back(10);
    human_size.push_back(50);

    Element human(human_position, human_size);


    std::vector<int> vehicle_position;
    std::vector<int> vehicle_size;

    vehicle_position.push_back(5);
    vehicle_position.push_back(5);

    vehicle_size.push_back(20);
    vehicle_size.push_back(15);

    Element vehicle(vehicle_position, vehicle_size);


    FrameDetectionData frame_detection;

    std::vector<Element> all_humans;
    all_humans.push_back(human);

    std::vector<Element> all_vehicles;
    all_vehicles.push_back(vehicle);

    frame_detection.AddElementsOfType(OBJECT_HUMAN, all_humans);
    frame_detection.AddElementsOfType(OBJECT_VEHICLE, all_vehicles);

    std::cout << "vehicle MinX: " << vehicle.GetMinX() << " MinY: " << vehicle.GetMinY() << " MaxX: " << vehicle.GetMaxX() << " MaxY: " << vehicle.GetMaxY() << std::endl;
    std::cout << "human   MinX: " << human.GetMinX() << " MinY: " << human.GetMinY() << " MaxX: " << human.GetMaxX() << " MaxY: " << human.GetMaxY() << std::endl;
    // analyse the fake frame detection data
    Scenario* result_scenario = analyser.Analyse(frame_detection);

    std::cout<< "distance: " << Scenario::ComputeCenterDistance(vehicle,human) << std::endl;
    if(result_scenario != NULL)
    {
        std::cout << "Main: " << result_scenario->GetScenarioInformation() << std::endl;
    }
    
    //if( HumansInFrontOfBusScenario* result = dynamic_cast<HumansInFrontOfBusScenario*>(result_scenario) ){

    //    std::cout << "Main: Humans in front of bus scenario detected! " << std::endl;
    //}

    return 0;
}

#endif*/
