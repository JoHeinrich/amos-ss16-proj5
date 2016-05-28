cmake_minimum_required (VERSION 2.8)
project(frameselector)
set (OUTPUT_NAME frameselector)


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

#opencv
find_package( OpenCV )
if(OpenCV_FOUND)
include_directories( ${OpenCV_INCLUDE_DIRS} )
else(OpenCV_FOUND)
message(SEND_ERROR "OpenCV not found")
endif(OpenCV_FOUND)

set(protobufheaders
	
	header.pb.h
	MsgCameraImage.pb.h
	
)

set(protobufsources
		
	header.pb.cc
	MsgCameraImage.pb.cc
)

set(hdfheader
	hdf_reader.h
)

set(hdfsource
	hdf_reader.cpp
)

set(header
	frame_selector.h
	image.h
	image_viewer.h
)

set(sources
	frame_selector.cpp
	main.cpp
	image.cpp
	image_viewer.cpp
)

add_executable(${OUTPUT_NAME} ${sources} ${header} ${protobufsources} ${protobufheaders} ${hdfsource} ${hdfheader})
target_link_libraries(${OUTPUT_NAME} ${PROTOBUF_LIBRARY} ${LINK_LIBS}  ${OpenCV_LIBS} -lhdf5_cpp -lhdf5)


