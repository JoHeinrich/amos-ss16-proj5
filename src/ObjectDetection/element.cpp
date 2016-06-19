//
// Projectname: amos-ss16-proj5
//
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

#include "element.h"

Element::Element(std::vector<int> position, std::vector<int> box_size){

    position_ = position;
    box_size_ = box_size;

}

std::vector<int> Element::GetPosition(){

    return position_;

}

std::vector<int> Element::GetBoxSize(){

    return box_size_;

}

int Element::GetMinX()
{
    return position_.at(0);
}

int Element::GetMaxX()
{
    return position_.at(0)+box_size_.at(0);
}

int Element::GetMinY()
{
    return position_.at(1);
}

int Element::GetMaxY()
{
    return position_.at(1)+box_size_.at(1);
}

int Element::GetCenterX()
{
    return position_.at(0)+box_size_.at(0)/2;
}

int Element::GetCenterY()
{
    return position_.at(1)+box_size_.at(1)/2;
}

