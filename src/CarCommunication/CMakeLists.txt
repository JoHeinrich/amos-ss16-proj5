#general
cmake_minimum_required(VERSION 2.8)
project( cafcommunication )
set (OUTPUT_NAME cafcommunication)
add_definitions(-std=c++11)

#caf compile flags
SET(CAF_COMPILE_FLAGS "-lcaf_io -lcaf_core")
add_definitions(${CAF_COMPILE_FLAGS})

#protobuf
include(FindProtobuf)
find_package(Protobuf REQUIRED)
if(PROTOBUF_FOUND)
	include_directories(${PROTOBUF_INCLUDE_DIR})
	#generate the h and cc files
	PROTOBUF_GENERATE_CPP(PROTO_SRC PROTO_HEADER "message.proto")
else(PROTOBUF_FOUND)
message(SEND_ERROR "Protobuff NOT found")
endif(PROTOBUF_FOUND)

#ADD_EXECUTABLE(${OUTPUT_NAME} protoagent.cpp ${PROTO_HEADER} ${PROTO_SRC})
#target_link_libraries(${OUTPUT_NAME} ${PROTOBUF_LIBRARY} ${CMAKE_THREAD_LIBS_INIT} -lcaf_io -lcaf_core)

