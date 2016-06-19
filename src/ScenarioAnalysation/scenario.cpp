
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

//std
#include <iostream>
#include <math.h>

#include "scenario.h"

float Scenario::ComputeDistance(Element first, Element second){

    std::vector<int> first_position = first.GetPosition();
    std::vector<int> second_position = second.GetPosition();
    
    return ComputePointDistance(first_position, second_position);

}

bool Scenario::DoOverlap(Element first, Element second){

    //determine whether the bounding box of the first element overlaps with the second one


   // std::cout << "SCENARIO::OVERLAP: first min, max x;y : " << first_min_x << " " << first_max_x << " " << first_min_y << " " << first_max_y <<std::endl;
   // std::cout << "SCENARIO::OVERLAP: second min, max x;y : " << second_min_x << " " << second_max_x << " " << second_min_y << " " << second_max_y <<std::endl;


    if( (first.GetMinX() <= second.GetMinX()) || (first.GetMaxX() >= second.GetMaxX()) || ( (first.GetMinX() >= second.GetMinX()) && (first.GetMaxX() <= second.GetMaxX()) ) ){


        if( ( (second.GetMinY() >= first.GetMinY()) && (second.GetMinY() <= first.GetMaxY()) )
                ||  ( (second.GetMaxY() <= first.GetMaxY()) && (second.GetMaxY() >= first.GetMinY()) ) ){


            std::cout << "Scenario: There are overlapping elements in the frame! " << std::endl;
            return true;
        }

        return false;
    }

    return false;

}

bool Scenario::DoContain(Element big, Element small)
{
    // checks if the small one is within the big one
    return big.GetMinX()<=small.GetMinX() && big.GetMinY()<=small.GetMinY() && big.GetMaxX()>=small.GetMaxX() && big.GetMaxY()>=small.GetMaxY();
}

float Scenario::ComputeCenterDistance(Element first, Element second){
    
    // get the center points of the objects
    
    
    std::vector<int> first_center;
    first_center.push_back(first.GetCenterX());
    first_center.push_back(first.GetCenterY());
    

    std::vector<int> second_center;
    second_center.push_back(second.GetCenterX());
    second_center.push_back(second.GetCenterY());
    return ComputePointDistance(first_center, second_center);
    
}

float Scenario::ComputePointDistance(std::vector<int> first, std::vector<int> second){
    
    //compute distance with pythagorean theorem

    float first_sum = pow( (static_cast<float>(second.at(0)) - static_cast<float>(first.at(0))), 2.0);
    float second_sum = pow( (static_cast<float>(second.at(1)) - static_cast<float>(first.at(1))), 2.0);
    
    float distance = sqrt(first_sum + second_sum);
    
    return distance;

}
