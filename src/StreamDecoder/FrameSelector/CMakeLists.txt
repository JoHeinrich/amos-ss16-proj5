cmake_minimum_required (VERSION 2.8)
project(FrameSelector)
set (OUTPUT_NAME FrameSelector)

include_directories("../ProtobufDeserializer" "../HDFDecoder")
#add_subdirectory(HDFDecoder)

file(GLOB_RECURSE sources "./*.cpp")
file(GLOB_RECURSE headers "./*.h")

add_executable(${OUTPUT_NAME} ${sources} ${headers})
#target_link_libraries(${OUTPUT_NAME} ${LINK_LIBS} -lhdf5_cpp -lhdf5)


