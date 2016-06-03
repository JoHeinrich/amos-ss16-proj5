
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

#include "../ObjectDetection/frame_detection_data.h"
#include "scenario.h"

class Analyser {
    
public:
    
    /**
     * Analyses the frame detection data and detetermines which scenario is there
     *
     * @param frame_data    The frame data with detected obejects
     */
    Scenario Analyse(FrameDetectionData frame_data);
    
private:
    

    
};


#endif // ANALYSER_H
