cmake_minimum_required (VERSION 2.8)
project(ProtobufDecoder)
set (OUTPUT_NAME ProtobufDecoder)

#protobuf
include(FindProtobuf)
find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIR})

set(protobufsources
  protofiles/header.pb.cc
  protofiles/MsgCameraImage.pb.cc
  
)
set(protobufheaders
  protofiles/header.pb.h
  protofiles/MsgCameraImage.pb.h
)

add_library(proto ${protobufsources} ${protobufheaders})

set(sources
  protobufMain.cpp
  msg_cameraimage_reader.cpp
)

set(headers
  msg_cameraimage_reader.h
)

add_executable(${OUTPUT_NAME} ${sources} ${headers})
target_link_libraries(${OUTPUT_NAME} proto ${PROTOBUF_LIBRARY})

