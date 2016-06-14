// 
// simple_broker.h 
// Projectname: amos-ss16-proj5 
// 
// Created on 14.06.2016. 
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


#ifndef SIMPLE_BROKER_H
#define SIMPLE_BROKER_H

#ifdef WIN32 
#define _WIN32_WINNT 0x0600 
#include <Winsock2.h> 
#else 
#include <arpa/inet.h> // htonl 
#endif 
 
#include <vector> 
#include <string> 
#include <limits> 
#include <memory> 
#include <cstdint> 
#include <cassert> 
#include <iostream> 

/** 
* utility function to print an exit message with custom name. 
* 
* @param hdl Actor which shuts down
* @param name Actor name 
*/ 
void print_on_exit(const actor& hdl, const std::string& name);

/** 
* utility function for sending an integer type. 
* 
* @param self Writing broker
* @param hdl Connection handler
* @param value Container value 
*/ 
void write_int(broker* self, connection_handle hdl, T value);

/** 
* write two uint32 values instead . 
* 
* @param self Writing broker
* @param hdl Connection handler
* @param value uint64_t value which gets converted
*/ 
void write_int(broker* self, connection_handle hdl, uint64_t value);

/** 
* utility function for reading an ingeger from incoming data . 
* 
* @param data incoming data
* @param storage Container
*/ 
void read_int(const void* data, T& storage);

/** 
* reads two uint32 values instead . 
* 
* @param data incoming data
* @param storage uint64_t value which gets converted
*/ 
void read_int(const void* data, uint64_t& storage);

/** 
* client behavior . 
* 
* @param self incoming actor
* @param num_pings Number of messages which should be send
*/ 
behavior ping(event_based_actor* self, size_t num_pings); 

/** 
* server behavior . 
* 
* @param self incoming actor
*/ 
behavior pong(event_based_actor* self);

/** 
* implementation of the broker. 
* 
* @param self incoming actor
* @param hdl connection handler
* @param buddy communication actor
*/ 
behavior broker_impl(broker* self, connection_handle hdl, const actor& buddy);

/** 
* Behavior for server . 
* 
* @param self incoming actor
* @param buddy communication actor
*/ 
behavior server(broker* self, const actor& buddy);


#endif // SIMPLE_BROKER_H
