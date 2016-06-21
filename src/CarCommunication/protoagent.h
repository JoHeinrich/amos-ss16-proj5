// 
// protobuf_broker.h 
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


#ifndef PROTOBUF_BROKER_H
#define PROTOBUF_BROKER_H

#include <vector>
#include <string>
#include <limits>
#include <memory>
#include <iostream>

#include <arpa/inet.h>

#include "caf/all.hpp"
#include "caf/io/all.hpp"


CAF_PUSH_WARNINGS
#include "message.pb.h"
CAF_POP_WARNINGS

using namespace std;
using namespace caf;
using namespace caf::io; 


class ProtoAgent {
	
public:
	/** 
	* starts the client. 
	* 
	* @param port Specified port for communication
	* @param hsot Hostname for connection to server 
	*/ 
	static void startClient (uint16_t port, const string& host);

	/** 
	* starts the server. 
	* 
	* @param port Specified port for communication 
	*/ 
	static void startServer (uint16_t port);

	/** 
	* utility function to print an exit message with custom name. 
	* 
	* @param hdl Actor which shuts down
	* @param name Actor name 
	*/ 

	static void print_on_exit(const actor& hdl, const std::string& name);


	/** 
	* Client's behavior -- sends a warning after kickoff and quits after the warning has been acknowledged by the server. 
	* 
	* @param self incoming actor
	*/ 
	static behavior sendWarning(event_based_actor* self);


	/** 
	* Server's behavior -- gets the client's warning from the protobuf broker and responds with an "ack" message
	* 
	*/ 
	static behavior ackMessage();


	/** 
	* implementation of the protobuf broker. 
	* 
	* @param self incoming actor
	* @param hdl connection handler
	* @param buddy communication actor
	*/ 
	static void protobuf_io(broker* self, connection_handle hdl, const actor& buddy);

	/** 
	* Behavior for server . 
	* 
	* @param self incoming actor
	* @param buddy communication actor
	*/ 
	static behavior server(broker* self, actor buddy);
};

#endif // PROTOBUF_BROKER_H
