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


/*
* This is the global main for our project
*/
#include "caf/all.hpp"
#include "caf/io/all.hpp"

#include <iostream>
#include "controller.h"
#include "multithreadedcontroller.h"
#include "../CarCommunication/protoagent.h"
using namespace std;

static bool
str_to_uint16(const char *str, uint16_t *res)
{
  char *end;
  errno = 0;
  intmax_t val = strtoimax(str, &end, 10);
  if (errno == ERANGE || val < 0 || val > UINT16_MAX || end == str || *end != '\0')
    return false;
  *res = (uint16_t) val;
  return true;
}

int main(int argc, const char * argv[]) {

    if(argc == 2){
        uint16_t port;
        if(str_to_uint16(argv[1],&port))
        {
            ProtoAgent::startServer(port);
        }
        else
        {
            cerr << "Could not read port" << endl;
        }
    }else if(argc == 4)
    {
        uint16_t port;
        if(str_to_uint16(argv[1],&port))
        {
            MultithreadedController controller(argv[3],port,argv[2]);
            //controller.AnalyseVideo(argv[3],port,argv[2]);
        }
        else
        {
            cerr << "Could not read port" << endl;
        }

    }
    else
    {
        cerr << "Usage:  " << " PORT (SERVER_IP_ADRESS FULL_PATH_TO_HDF5_FILE)" << endl;
        return -1;
    }


    return 0;
}
