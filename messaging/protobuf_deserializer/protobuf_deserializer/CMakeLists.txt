#cmake
cmake_minimum_required (VERSION 2.8)

#project
project(protobuf_deserializer)

#compiler
set(CMAKE_CXX_FLAGS "-g -Wall -Werror -std=c++11")

#search protobuf in subdirectoryprotobuf
add_subdirectory(protofiles)


include_directories(${CMAKE_CURRENT_BINARY_DIR})

#generate executable
file(GLOB_RECURSE sources "./src/*.cpp")
file(GLOB_RECURSE headers "./include/*.h")
add_executable(protobuf_deserializer ${sources} ${headers})

target_link_libraries(protobuf_deserializer proto ${PROTOBUF_LIBRARY})

