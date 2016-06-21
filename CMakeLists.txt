cmake_minimum_required (VERSION 2.8)
project(AutoDrive)
set (OUTPUT_NAME AutoDrive)
add_definitions(-std=c++11)
SET(CAF_COMPILE_FLAGS "-lcaf_io -lcaf_core")
add_definitions(${CAF_COMPILE_FLAGS})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
add_subdirectory(src/ScenarioAnalysation)
add_subdirectory(src/ObjectDetection)
add_subdirectory(src/caf)
add_subdirectory(src/StreamDecoder)



file(GLOB_RECURSE sources0 "./src/ScenarioAnalysation/*.cpp")
file(GLOB_RECURSE headers0 "./src/ScenarioAnalysation/*.h")

file(GLOB_RECURSE sources1 "./src/ObjectDetection/*.cpp")
file(GLOB_RECURSE headers1 "./src/ObjectDetection/*.h")

file(GLOB_RECURSE sources2 "./src/StreamDecoder/*.cpp")
file(GLOB_RECURSE sourcesc2 "./src/StreamDecoder/*.cc")
file(GLOB_RECURSE headers2 "./src/StreamDecoder/*.h")

file(GLOB_RECURSE sources3 "./src/caf/*.cpp")
file(GLOB_RECURSE sourcesc3 "./src/caf/*.cc")
file(GLOB_RECURSE headers3 "./src/caf/*.h")

LIST(APPEND sources ${sources0} ${sources1} ${sources2} ${sourcesc2} ${sources3} ${sourcesc3}
    #src/ObjectDetection/element.cpp
    #src/ObjectDetection/frame_detection_data.cpp
	#src/StreamDecoder/image.cpp
	#src/StreamDecoder/image_view.cpp

)

LIST(APPEND headers ${headers0} ${headers1} ${header2} ${headers3}
    #src/ObjectDetection/element.h
    #src/ObjectDetection/frame_detection_data.h
	#src/StreamDecoder/image.h
	#src/StreamDecoder/image_view.h


)
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

add_definitions(-D COMBINE) 

add_executable(${OUTPUT_NAME} ${sources} ${headers} ${sourcesc})
target_link_libraries(${OUTPUT_NAME} ${LINK_LIBS} -lhdf5_cpp -lhdf5)
target_link_libraries(${OUTPUT_NAME} ${PROTOBUF_LIBRARY})
target_link_libraries(${OUTPUT_NAME} ${PROTOBUF_LIBRARY} ${CMAKE_THREAD_LIBS_INIT} -lcaf_io -lcaf_core)
