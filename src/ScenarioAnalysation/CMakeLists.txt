cmake_minimum_required(VERSION 2.8)
project( analyser )
set (OUTPUT_NAME analyser)



set(sources
	analyser.cpp
	scenario.cpp
	humans_in_front_of_bus_scenario.cpp
	main.cpp
	../ObjectDetection/element.cpp
	../ObjectDetection/frame_detection_data.cpp

)

set(headers
	analyser.h
	scenario.h
	humans_in_front_of_bus_scenario.h
	../ObjectDetection/element.h
	../ObjectDetection/frame_detection_data.h


)
add_executable( ${OUTPUT_NAME} ${sources} ${header} )
