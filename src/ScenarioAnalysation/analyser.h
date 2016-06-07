
//
// analyser.h
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

#ifndef ANALYSER_H
#define ANALYSER_H

//std
#include <vector>

#include "../ObjectDetection/frame_detection_data.h"
#include "scenario.h"
#include "humans_in_front_of_bus_scenario.h"

class Analyser {
    
public:
    
    /**
    * Constructor.
    *
    * @param scenarios    The vector with the possible scenarios
    */
    Analyser(std::vector<Scenario*> scenarios);

    /**
    * Adds a scenario to the vector with analysed scenarios.
    *
    * @param scenario   The scenario to add.
    */
    void AddScenario(Scenario* scenario);

    /**
     * Analyses the frame detection data and detetermines which scenario is there
     *
     * @param detected_objects    The frame data with detected objects
     * @return The detected scenario
     */
    Scenario* Analyse(FrameDetectionData detected_objects);
    
private:
    
    std::vector<Scenario*> all_scenarios_;  ///< Vector with all possible scenarios
    
};


#endif // ANALYSER_H
