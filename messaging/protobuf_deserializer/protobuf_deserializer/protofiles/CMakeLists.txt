#minium cmake version
cmake_minimum_required (VERSION 2.8)

#protobuf
include(FindProtobuf)
find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIR})

#generate the h and cc files
PROTOBUF_GENERATE_CPP(PROTO_SRC PROTO_HEADER "header.proto" "MsgCameraImage.proto")
ADD_LIBRARY(proto ${PROTO_HEADER} ${PROTO_SRC})