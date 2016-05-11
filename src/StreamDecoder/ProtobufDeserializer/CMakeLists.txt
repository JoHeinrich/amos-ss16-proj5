cmake_minimum_required (VERSION 2.8)
project(ProtobufDecoder)
set (OUTPUT_NAME ProtobufDecoder)

add_subdirectory(protofiles)


file(GLOB_RECURSE sources "./src/*.cpp")
file(GLOB_RECURSE headers "./src/*.h")


add_executable(${OUTPUT_NAME} ${sources} ${headers})
target_link_libraries(${OUTPUT_NAME} proto ${PROTOBUF_LIBRARY})

