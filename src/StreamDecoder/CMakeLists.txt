cmake_minimum_required (VERSION 2.8)
project(FrameSelector)
set (OUTPUT_NAME FrameSelector)


#hdf5
find_package (HDF5)
if(HDF5_FOUND)
set(LINK_LIBS ${LINK_LIBS} ${HDF5_C_STATIC_LIBRARY} ${HDF5_C_LIBRARIES})
include_directories(${HDF5_INCLUDE_DIR})
else(HDF5_FOUND)
message(SEND_ERROR "HDF5 was not Found")
endif(HDF5_FOUND)

#protobuf
include(FindProtobuf)
find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIR})

set(protobufheaders
	ProtobufDeserializer/msg_cameraimage_reader.h
	ProtobufDeserializer/header.pb.h
	ProtobufDeserializer/MsgCameraImage.pb.h
	
)

set(protobufsources
	ProtobufDeserializer/msg_cameraimage_reader.cpp	
	ProtobufDeserializer/header.pb.cc
	ProtobufDeserializer/MsgCameraImage.pb.cc
)

set(hdfheader
	HDFDecoder/hdf_reader.h
)

set(hdfsource
	HDFDecoder/hdf_reader.cpp
)

set(header
	frame_selector.h
)

set(sources
	frame_selector.cpp
	main.cpp
)

add_executable(${OUTPUT_NAME} ${sources} ${header} ${protobufsources} ${protobufheaders} ${hdfsource} ${hdfheader})
target_link_libraries(${OUTPUT_NAME} ${PROTOBUF_LIBRARY} ${LINK_LIBS} -lhdf5_cpp -lhdf5)


