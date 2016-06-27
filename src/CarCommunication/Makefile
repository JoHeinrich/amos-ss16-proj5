.PHONY: all cpp

all: cpp

cpp:    pbbroker_cpp

pbbroker_cpp: protoagent.cpp protoc_middleman
	pkg-config --cflags protobuf  # fails if protobuf is not installed
	c++ protoagent.cpp protoagent.h message.pb.cc -o pbbroker -lcaf_io -lcaf_core -std=c++11 `pkg-config --cflags --libs protobuf`
	

protoc_middleman: message.proto
	protoc --cpp_out=. message.proto
