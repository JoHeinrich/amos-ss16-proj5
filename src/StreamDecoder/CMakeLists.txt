cmake_minimum_required (VERSION 2.8)
project(FrameSelector)
set (OUTPUT_NAME FrameSelector)

add_subdirectory(ProtobufDeserializer/protofiles)

#hdf5
find_package (HDF5)
if(HDF5_FOUND)
set(LINK_LIBS ${LINK_LIBS} ${HDF5_C_STATIC_LIBRARY} ${HDF5_C_LIBRARIES})
include_directories(${HDF5_INCLUDE_DIR})
else(HDF5_FOUND)
message(SEND_ERROR "HDF5 was not Found")
endif(HDF5_FOUND)

set(protobufheader
	ProtobufDeserializer/msg_cameraimage_reader.h
)

set(protobufsource
	ProtobufDeserializer/msg_cameraimage_reader.cpp	
)

set(hdfheader
	HDFDecoder/HDFReader.h
)

set(hdfsource
	HDFDecoder/HDFReader.cpp
)

set(header
	FrameSelector.h
)

set(sources
	FrameSelector.cpp
	main.cpp
)


#file(GLOB_RECURSE sources "./*.cpp")
#file(GLOB_RECURSE headers "./*.h")

add_executable(${OUTPUT_NAME} ${sources} ${header} ${protobufsource} ${protobufheader} ${hdfsource} ${hdfheader})
target_link_libraries(${OUTPUT_NAME} proto ${PROTOBUF_LIBRARY} ${LINK_LIBS} -lhdf5_cpp -lhdf5)


