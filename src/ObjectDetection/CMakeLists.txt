cmake_minimum_required(VERSION 2.8)
project( detection )
set (OUTPUT_NAME detection)

# Provide the include directories to the caller
find_package( OpenCV )
if(OpenCV_FOUND)
	include_directories( ${OpenCV_INCLUDE_DIRS} )
else(OpenCV_FOUND)
	message(SEND_ERROR "OpenCV not found")
endif(OpenCV_FOUND)

set(sources
	detectionMain.cpp
	detection.cpp
	element.cpp
	frame_detection_data.cpp
	humandetector.cpp
	people_detector.cpp
	vehicle_detector.cpp
)

set(headers
	detection.h
	detector.h
	element.h
	frame_detection_data.h
	people_detector.h
	vehicle_detector.h
)

add_executable( ${OUTPUT_NAME} ${sources} ${header} )
target_link_libraries(${OUTPUT_NAME} ${OpenCV_LIBS} )
