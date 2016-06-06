
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

#include <math.h>

#include "scenario.h"

float Scenario::Distance(Element first, Element second){

    //compute distance with pythagorean theorem

    std::vector<int> first_position = first.GetPosition();
    std::vector<int> second_position = second.GetPosition();

    float first_sum = pow( (static_cast<float>(second_position.at(0)) - static_cast<float>(first_position.at(0))), 2.0);
    float second_sum = pow( (static_cast<float>(second_position.at(1)) - static_cast<float>(first_position.at(1))), 2.0);

    float distance = sqrt(first_sum + second_sum);

    return distance;

}

bool Scenario::Overlap(Element first, Element second){

    //determine whether the bounding box of the first element overlaps with the second one

    int first_min_x = first.GetPosition().at(0);
    int first_min_y = first.GetPosition().at(1);

    int first_max_x = first_min_x + first.GetBoxSize().at(0);
    int first_max_y = first_min_y + first.GetBoxSize().at(1);

    // TODO


}
