//
// main.cpp
// Projectname: amos-ss16-proj5
//
// Created on 10-05-2016.
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

#include <iostream>

#include "HDFReader.h"

using namespace std;


int main(int argc, const char* argv[]) {

    if (argc != 2) {
        cerr << "Usage:  " << argv[0] << " FULL_PATH_TO_HDF5_FILE" << endl;
        return -1;
    }

    HDFReader hdfReader(argv[1]);

    int result = hdfReader.readFile();

    std::cout << "Result: " << result << std::endl;

    return result;
}
