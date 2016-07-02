//
// hdf_reader.cpp
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
#include <list>

//local
#include "analyser.h"
#include "../ObjectDetection/element.h"

Analyser::Analyser(std::vector<Scenario *> scenarios){

    all_scenarios_ = scenarios;

}

void Analyser::AddScenario(Scenario* scenario){

    all_scenarios_.push_back(scenario);

}

Scenario* Analyser::Analyse(FrameDetectionData detected_objects){

    // iterate over all scenarios and return the first detected scenario
    for(int i = 0; i < all_scenarios_.size(); i++){

        Scenario* current_scenario = all_scenarios_.at(i);

        if(!current_scenario){
            continue;
        }

        bool detected = current_scenario->Detect(detected_objects);

        if(detected){
            std::cout << "Analyser: A scenario was detected! " <<std::endl;
            return current_scenario;
        }
    }

    return NULL;

}
