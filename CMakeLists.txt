#general
cmake_minimum_required (VERSION 2.8)
project(amos-ss16-proj5)
set (OUTPUT_NAME amos-ss16-proj5)

add_definitions(-std=c++11)

#caf compile flags
SET(CAF_COMPILE_FLAGS "-lcaf_io -lcaf_core")
add_definitions(${CAF_COMPILE_FLAGS})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB_RECURSE sourcesc "./src/*.cc")
file(GLOB_RECURSE sources "./src/*.cpp")
file(GLOB_RECURSE headers "./src/*.h")


#protobuf
include(FindProtobuf)
find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIR})

#opencv
find_package( OpenCV )
if(OpenCV_FOUND)
    include_directories( ${OpenCV_INCLUDE_DIRS} )
    set(LINK_LIBS ${LINK_LIBS} ${OpenCV_LIBS})
else(OpenCV_FOUND)
    message(SEND_ERROR "OpenCV not found")
endif(OpenCV_FOUND)


#hdf5
find_package (HDF5)
if(HDF5_FOUND)
    set(LINK_LIBS ${LINK_LIBS} ${HDF5_C_STATIC_LIBRARY} ${HDF5_C_LIBRARIES})
    include_directories(${HDF5_INCLUDE_DIR})
else(HDF5_FOUND)
    message(SEND_ERROR "HDF5 was not Found")
endif(HDF5_FOUND)


#openmp
find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()


#link libraries
add_executable(${OUTPUT_NAME} ${sources} ${headers} ${sourcesc})
target_link_libraries(${OUTPUT_NAME} ${LINK_LIBS} -lhdf5_cpp -lhdf5)
target_link_libraries(${OUTPUT_NAME} ${PROTOBUF_LIBRARY})
target_link_libraries(${OUTPUT_NAME} ${PROTOBUF_LIBRARY} ${CMAKE_THREAD_LIBS_INIT} -lcaf_io -lcaf_core)
