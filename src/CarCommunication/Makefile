.PHONY: all cpp

all: cpp

cpp:    client_cpp    server_cpp

client_cpp: client.cpp protoc_middleman
	pkg-config --cflags protobuf  # fails if protobuf is not installed
	c++ client.cpp csCommunication.pb.cc -o client_cpp `pkg-config --cflags --libs protobuf`

server_cpp: server.cpp protoc_middleman
	pkg-config --cflags protobuf  # fails if protobuf is not installed
	c++ server.cpp csCommunication.pb.cc -o server_cpp `pkg-config --cflags --libs protobuf`

protoc_middleman: csCommunication.proto
	protoc --cpp_out=. csCommunication.proto
