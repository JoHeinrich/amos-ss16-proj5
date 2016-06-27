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
#include "queue.h"
#include <stdlib.h>

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
#ifndef BLOCKINGQUEUE
#define BLOCKINGQUEUE
#include "queue.h"
#include <stdlib.h>
#include <omp.h>
template <class c> class BlockingQueue: public Queue<c>
{
    c* buffer;
    omp_lock_t addlock;
    omp_lock_t removelock;
public:
    //if end is set to true the blocking will end and every function will return NULL
    BlockingQueue(bool& end):Queue<c>(end),buffer(NULL)
    {
        omp_init_lock(&addlock);
        omp_init_lock(&removelock);
        omp_set_lock(&removelock);
    }


    /*
    * Stores the object and returns the old one if there are to many
    * depending on subclass implementation this function can be blocking or not
    */
    c* Add(c* object)
    {
        omp_set_lock(&addlock);
        
        if(buffer!=NULL)
        {
            delete buffer;
        }
        buffer = object;
        omp_unset_lock(&removelock);
    }

    /* 
    * returns the next object in line
    * depending on subclass implementation this function can be blocking or not
    */
    c* Remove()
    {
        omp_set_lock(&removelock);
        c* b = buffer;
        buffer = NULL;
        omp_unset_lock(&addlock);
        
        return b;
    }

    void Unlock()
    {
        omp_unset_lock(&addlock);
        omp_unset_lock(&removelock);
    }
};
#endif 