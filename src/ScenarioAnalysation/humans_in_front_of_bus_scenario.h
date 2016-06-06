
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

#ifndef HUMANS_IN_FRONT_OF_BUS_SCENARIO_H
#define HUMANS_IN_FRONT_OF_BUS_SCENARIO_H


#include "scenario.h"

class HumansInFrontOfBusScenario : public Scenario {
    
public:

    /**
    * Overrides the Detect function from Scenario. Deetects whether there are humans in front of the bus.
    *
    * @return true whether the are humans in front of the bus, false if not
    */
    virtual bool Detect(FrameDetectionData detected_objects) override;

private:

};


#endif // HUMANS_IN_FRONT_OF_SCENARIO_H
