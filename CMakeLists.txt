cmake_minimum_required (VERSION 2.8)
project(AutoDrive)
set (OUTPUT_NAME AutoDrive)

add_subdirectory(src/StreamDecoder/HDFDecoder)
add_subdirectory(src/StreamDecoder/ProtobufDeserializer)

add_subdirectory(src/CarCommunication)

add_subdirectory(src/StreamDecoder/DecompressionExample)

add_subdirectory(src/StreamDecoder/DecoderPipeline)



file(GLOB_RECURSE sources "./src/*.cpp")
file(GLOB_RECURSE headers "./src/*.h")

#opencv
#find_package( OpenCV )
#if(OpenCV_FOUND)
#include_directories( ${OpenCV_INCLUDE_DIRS} )
#set(LINK_LIBS ${LINK_LIBS} ${OpenCV_LIBS})
#else(OpenCV_FOUND)
#message(SEND_ERROR "OpenCV not found")
#endif(OpenCV_FOUND)


#hdf5
#find_package (HDF5)
#if(HDF5_FOUND)
#set(LINK_LIBS ${LINK_LIBS} ${HDF5_C_STATIC_LIBRARY} ${HDF5_C_LIBRARIES})
#include_directories(${HDF5_INCLUDE_DIR})
#else(HDF5_FOUND)
#message(SEND_ERROR "HDF5 was not Found")
#endif(HDF5_FOUND)

#add_executable(${OUTPUT_NAME} ${sources} ${headers})
#target_link_libraries(${OUTPUT_NAME} ${LINK_LIBS} -lhdf5_cpp -lhdf5)
#target_link_libraries(${OUTPUT_NAME} proto ${PROTOBUF_LIBRARY})

