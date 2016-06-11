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

void print_on_exit(const actor& hdl, const std::string& name) {
  hdl->attach_functor([=](abstract_actor* ptr, uint32_t reason) {
    aout(ptr) << name << " exited with reason " << reason << endl;
  });
}

behavior sendWarning(event_based_actor* self, size_t num_pings) {
  auto count = make_shared<size_t>(0);
  return {
    on(atom("kickoff"), arg_match) >> [=](const actor& pong) {
//	  aout(self) << "client: send {" << to_string(atom("warning")::value) << ", " <<  1 << "}" << endl;    
      self->send(pong, atom("warning"), 1);
      self->become (
        on(atom("ack"), arg_match) >> [=](int value) -> void {
          self->quit();
          return;
//          return make_message(atom("ping"), value + 1);
        }
      );
    }
  };
}

behavior ackMessage() {
  return {
    on(atom("warning"), arg_match) >> [](int value) {
      return make_message(atom("ack"), value);
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
void protobuf_io(broker* self, connection_handle hdl, const actor& buddy) {
  // monitor buddy to quit broker if buddy is done
  self->monitor(buddy);
  auto write = [=](const org::libcppa::WarnOrAck& p) {
    string buf = p.SerializeAsString();
    int32_t s = htonl(static_cast<int32_t>(buf.size()));
    self->write(hdl, sizeof(int32_t), &s);
    self->write(hdl, buf.size(), buf.data());
    self->flush(hdl);
  };
  message_handler default_bhvr = {
    [=](const connection_closed_msg&) {
      aout(self) << "connection closed" << endl;
      self->send_exit(buddy, exit_reason::remote_link_unreachable);
      self->quit(exit_reason::remote_link_unreachable);
    },
    on(atom("warning"), arg_match) >> [=](int i) {
      aout(self) << "'warning' " << i << endl;
      org::libcppa::WarnOrAck p;
      p.mutable_warn()->set_id(i);
      write(p);
    },
    on(atom("ack"), arg_match) >> [=](int i) {
      aout(self) << "'ack' " << i << endl;
      org::libcppa::WarnOrAck p;
      p.mutable_ack()->set_id(i);
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
        self->send(buddy, atom("warning"), p.warn().id());
      }
      else if (p.has_ack()) {
        self->send(buddy, atom("ack"), p.ack().id());
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
behavior server(broker* self, actor buddy) {
  aout(self) << "server is running" << endl;
  return {
    [=](const new_connection_msg& msg) {
      aout(self) << "server accepted new connection" << endl;
      auto io_actor = self->fork(protobuf_io, msg.handle, buddy);
      print_on_exit(io_actor, "protobuf_io");
      // only accept 1 connection in our example
      self->quit();
    },
    others >> [=] {
      cout << "unexpected: " << to_string(self->current_message()) << endl;
    }
  };
}

optional<uint16_t> as_u16(const std::string& str) {
  return static_cast<uint16_t>(stoul(str));
}

int main(int argc, char** argv) {
// Parsing arguments
  message_builder{argv + 1, argv + argc}.apply({
    on("-s", as_u16) >> [&](uint16_t port) {
    // We are a server
      cout << "run in server mode" << endl;
      // spawn the actor that acks messages
      auto serv_actor = spawn(ackMessage);
      // spawn an IO server to handle communication and work with the broker later (uses the behavior server helper)
      auto sever_actor = spawn_io_server(server, port, serv_actor);
      print_on_exit(sever_actor, "server");
      print_on_exit(serv_actor, "exit ack");
    },
    on("-c", val<string>, as_u16) >> [&](const string& host, uint16_t port) {
      // spawn the actor that sends warnings
      auto client_actor = spawn(sendWarning, 20);
      // spawn a broker to serialize and recognize messages
      auto io_actor = spawn_io_client(protobuf_io, host, port, client_actor);
      print_on_exit(io_actor, "protobuf_io");
      print_on_exit(client_actor, "exit warning");
      // Start the warning message actor by using a kickoff message event sent directly from main
      send_as(io_actor, client_actor, atom("kickoff"), io_actor);
    },
    others >> [] {
      cerr << "use with eihter '-s PORT' as server or "
          "'-c HOST PORT' as client"
           << endl;
    }
  });
  await_all_actors_done();
  shutdown();
}
