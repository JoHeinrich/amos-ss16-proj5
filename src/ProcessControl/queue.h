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
#ifndef QUEUE
#define QUEUE
template <class c> class Queue
{
protected:
    bool& end;
public:
    //if end is set to true the blocking will end and every function will return NULL
    Queue(bool& end):end(end)
    {

    }

    /*
    * Unlocks the queue and allows all functions to return NULL;
    */
    virtual void Unlock()=0;
    /*
    * Stores the object and returns the old one if there are to many
    * depending on subclass implementation this function can be blocking or not
    */
    virtual c* Add(c* object)=0;

    /* 
    * returns the next object in line
    * depending on subclass implementation this function can be blocking or not
    */
    virtual c* Remove()=0;
};
#endif //QUEUE