cmake_minimum_required (VERSION 2.8)
project(AutoDrive)
set (OUTPUT_NAME AutoDrive)


#hdf5
#find_package (HDF5)
#if(HDF5_FOUND)
#set(LINK_LIBS ${LINK_LIBS} ${HDF5_C_STATIC_LIBRARY} ${HDF5_C_LIBRARIES})
#include_directories(${HDF5_INCLUDE_DIR})
#else(HDF5_FOUND)
#message(SEND_ERROR "HDF5 was not Found")
#endif(HDF5_FOUND)



#protobuf
include(FindProtobuf)
find_package(Protobuf REQUIRED)
if(PROTOBUF_FOUND)
	include_directories(${PROTOBUF_INCLUDE_DIR})
	#generate the h and cc files
	PROTOBUF_GENERATE_CPP(PROTO_SRC PROTO_HEADER "csCommunication.proto")
else(PROTOBUF_FOUND)
message(SEND_ERROR "Protobuff NOT found")
endif(PROTOBUF_FOUND)

find_package (Threads)

ADD_EXECUTABLE(server server.cpp ${PROTO_HEADER} ${PROTO_SRC})
ADD_EXECUTABLE(client client.cpp ${PROTO_HEADER} ${PROTO_SRC})
target_link_libraries(server ${PROTOBUF_LIBRARY} ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(client ${PROTOBUF_LIBRARY} ${CMAKE_THREAD_LIBS_INIT})
