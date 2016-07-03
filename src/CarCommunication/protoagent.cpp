//
// protoagent.cpp
// Projectname: amos-ss16-proj5
//
// Created on 28.05.2016.
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

#include "protoagent.h"

static actor client_actor;
static actor io_actor;
int mess_id = 1;

/*
  **************************
  Exit message - Prints warning with given reason
  **************************
*/
void ProtoAgent::print_on_exit(const actor& hdl, const std::string& name) {
  hdl->attach_functor([=](abstract_actor* ptr, uint32_t reason) {
    aout(ptr) << name << " exited with reason " << reason << endl;
  });
}

/*
  **************************
  Client's behavior -- sends a warning after he gets the "warnServer" event from the controller
  **************************
*/
behavior ProtoAgent::sendWarning(event_based_actor* self) {
  return {
    on(atom("warnSc1"), arg_match) >> [=](const actor& pong, int id) {
      self->send(pong, atom("warning1"), id);
    },
    on(atom("warnSc2"), arg_match) >> [=](const actor& pong, int id) {
      self->send(pong, atom("warning2"), id);
    },
    on(atom("warnSc3"), arg_match) >> [=](const actor& pong, int id) {
      self->send(pong, atom("warning3"), id);
    },
    on(atom("exit"), arg_match) >> [=](int value) -> void {
          self->quit();
          return;
    } 
  };
}

/*
  **************************
  Server's behavior -- gets the client's warning from the protobuf broker
  and responds with an "ack" message
  **************************
*/
behavior ProtoAgent::ackMessage() {
  return {
    on(atom("warning"), arg_match) >> [](int id, int type) {
      return make_message(atom("ack"), id, type);
    }
  };
}

/*
  **************************
  Protobuf broker implementation
  Works as a communication handling middleman for the server/client actors above
  Deserizalizes/serializes messages 
  **************************
*/
void ProtoAgent::protobuf_io(broker* self, connection_handle hdl, const actor& buddy) {
  // monitor buddy to quit broker if buddy is done
  self->monitor(buddy);
  auto write = [=](const org::libcppa::WarnOrAck& p) {
    string buf = p.SerializeAsString();
    int32_t s = htonl(static_cast<int32_t>(buf.size()));
    self->write(hdl, sizeof(int32_t), &s);
    self->write(hdl, buf.size(), buf.data());
    self->flush(hdl);
  };
  // message handler 
  message_handler default_bhvr = {
    [=](const connection_closed_msg&) {
      aout(self) << "connection closed" << endl;
      self->send_exit(buddy, exit_reason::remote_link_unreachable);
      self->quit(exit_reason::remote_link_unreachable);
    },
    on(atom("warning1"), arg_match) >> [=](int i) {
      aout(self) << "Send: 'People in front of car' warning with ID " << i << endl;
      org::libcppa::WarnOrAck p;
      p.mutable_warn()->set_id(i);
      p.mutable_warn()->set_type(1);      
      write(p);
    },
    on(atom("warning2"), arg_match) >> [=](int i) {
      aout(self) << "Send: 'People on street detected' warning with ID " << i << endl;
      org::libcppa::WarnOrAck p;
      p.mutable_warn()->set_id(i);
      p.mutable_warn()->set_type(2);
      write(p);
    },
    on(atom("warning3"), arg_match) >> [=](int i) {
      aout(self) << "Send: warning of type 3 with ID " << i << endl;
      org::libcppa::WarnOrAck p;
      p.mutable_warn()->set_id(i);
      p.mutable_warn()->set_type(3);      
      write(p);
    },
    on(atom("ack"), arg_match) >> [=](int i, int type) {
      aout(self) << "Send: ack with ID " << i << " of type " << type << endl;
      org::libcppa::WarnOrAck p;
      p.mutable_ack()->set_id(i);
      p.mutable_ack()->set_type(type);
      write(p);
    },
    [=](const down_msg& dm) {
      if (dm.source == buddy) {
        aout(self) << "our buddy is down" << endl;
        self->quit(dm.reason);
      }
    },
    others >> [=] {
      cout << "unexpected: " << to_string(self->current_message()) << endl;
    }
  };
  auto await_protobuf_data = message_handler {
    [=](const new_data_msg& msg) {
      org::libcppa::WarnOrAck p;
      p.ParseFromArray(msg.buf.data(), static_cast<int>(msg.buf.size()));
      if (p.has_warn()) {
      	if (p.warn().type() == 1)
	        aout(self) << "Received: 'People in front of car' warning with ID " << p.warn().id() << endl;
	    if (p.warn().type() == 2)
	        aout(self) << "Received: 'People on street detected' warning with ID " << p.warn().id() << endl;
	    if (p.warn().type() == 3 || p.warn().type() == 4)
	    	aout(self) << "Received: warning with ID " << p.warn().id() << " of type " << p.warn().type() << endl;
        self->send(buddy, atom("warning"), p.warn().id(), p.warn().type());
      }
      else if (p.has_ack()) {
        aout(self) << "Received: ack for ID " << p.ack().id() << " of type " << p.ack().type() << endl;
        self->send(buddy, atom("ack"), p.ack().id(), p.ack().type());
      }
      else {
        self->quit(exit_reason::user_shutdown);
        cerr << "neither Warning nor ACK!" << endl;
      }
      // receive next length prefix
      self->configure_read(hdl, receive_policy::exactly(sizeof(int32_t)));
      self->unbecome();
    }
  }.or_else(default_bhvr);
  auto await_length_prefix = message_handler {
    [=](const new_data_msg& msg) {
      int32_t num_bytes;
      memcpy(&num_bytes, msg.buf.data(), sizeof(int32_t));
      num_bytes = htonl(num_bytes);
      if (num_bytes < 0 || num_bytes > (1024 * 1024)) {
        aout(self) << "someone is trying something nasty" << endl;
        self->quit(exit_reason::user_shutdown);
        return;
      }
      // receive protobuf data
      auto nb = static_cast<size_t>(num_bytes);
      self->configure_read(hdl, receive_policy::exactly(nb));
      self->become(keep_behavior, await_protobuf_data);
    }
  }.or_else(default_bhvr);
  // initial setup
  self->configure_read(hdl, receive_policy::exactly(sizeof(int32_t)));
  self->become(await_length_prefix);
}

/*
 **************************
 Helper method for the server to handle connections;
 Starts the server broker with the received message handle if a client connects
 **************************
*/
behavior ProtoAgent::server(broker* self, actor buddy) {
  aout(self) << "server is running" << endl;
  return {
    [=](const new_connection_msg& msg) {
      aout(self) << "server accepted new connection" << endl;
      auto io_actor = self->fork(protobuf_io, msg.handle, buddy);
      //print_on_exit(io_actor, "protobuf_io");
      // only accept 1 connection in our example
      self->quit();
    },
    others >> [=] {
      cout << "unexpected: " << to_string(self->current_message()) << endl;
    },
    after(std::chrono::seconds(60)) >> [=] {
      aout(self) << "received no connection within 60 seconds..." << endl;
      self->send_exit(buddy, exit_reason::remote_link_unreachable);
      self->quit();
    }
  };
}

optional<uint16_t> as_u16(const std::string& str) {
  return static_cast<uint16_t>(stoul(str));
}

/*
  **************************
  Client kickoff - spawns Client Actor with given port and host
  **************************
*/
void ProtoAgent::startClient (uint16_t port, const string& host) {
	cout << "run in client mode" << endl;	
	// spawn the actor that sends warnings
	client_actor = spawn(sendWarning);
	// spawn a broker to serialize and recognize messages
	io_actor = spawn_io_client(protobuf_io, host, port, client_actor);
	print_on_exit(io_actor, "protobuf_io");
	print_on_exit(client_actor, "exit warning");
}

/*
  **************************
  Client message - Message from Client to it's host with given Scenario
  or to shutdown the Client with EXIT
  **************************
*/
void ProtoAgent::sendMsgFromClient(Scenarios id) {	
	if ( Scenarios::WARN1 == id) {
		send_as(io_actor, client_actor, atom("warnSc1"), io_actor, mess_id);
		mess_id++;
	}
	if ( Scenarios::WARN2 == id) {
		send_as(io_actor, client_actor, atom("warnSc2"), io_actor, mess_id);
		mess_id++;
	}
	if ( Scenarios::WARN3 == id) {
		send_as(io_actor, client_actor, atom("warnSc3"), io_actor, mess_id);
		mess_id++;
	}
	if ( Scenarios::EXIT == id) {
		send_as(io_actor, client_actor, atom("exit"), 1);
	}
}

/*
  **************************
  Server kickoff - spawns server Actor
  **************************
*/
void ProtoAgent::startServer (uint16_t port) {
	cout << "run in server mode" << endl;
	// spawn the actor that acks messages
	auto serv_actor = spawn(ackMessage);
	// spawn an IO server to handle communication and work with the broker later (uses the behavior server helper)
	auto server_actor = spawn_io_server(server, port, serv_actor);
	print_on_exit(server_actor, "server");
	print_on_exit(serv_actor, "exit ack");
	await_all_actors_done();
	shutdown();
}

ProtoAgent::ProtoAgent(uint16_t port, string host)
{
  if(host == "")
  {
    this->startServer(port);
  }
  else
  {
    this->startClient(port,host);
  }
}


