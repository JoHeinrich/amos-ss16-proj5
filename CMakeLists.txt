cmake_minimum_required (VERSION 2.8)
project(AutoDrive)
set (OUTPUT_NAME AutoDrive)

add_subdirectory(protofiles)


file(GLOB_RECURSE sources "./src/*.cpp")
file(GLOB_RECURSE headers "./src/*.h")


find_package (HDF5)
if(HDF5_FOUND)
set(LINK_LIBS ${LINK_LIBS} ${HDF5_C_STATIC_LIBRARY} ${HDF5_C_LIBRARIES})
include_directories(${HDF5_INCLUDE_DIR})
else(HDF5_FOUND)
message(SEND_ERROR "HDF5 was not Found")
endif(HDF5_FOUND)

add_executable(${OUTPUT_NAME} ${sources} ${headers})
target_link_libraries(${OUTPUT_NAME} ${LINK_LIBS} -lhdf5_cpp -lhdf5)
target_link_libraries(${OUTPUT_NAME} proto ${PROTOBUF_LIBRARY})

