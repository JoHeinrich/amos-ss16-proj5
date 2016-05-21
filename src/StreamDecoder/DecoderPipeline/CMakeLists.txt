cmake_minimum_required (VERSION 2.8)
project(DecoderPipeline)
set (OUTPUT_NAME DecoderPipeline)



file(GLOB_RECURSE sources "./*.cpp")
file(GLOB_RECURSE headers "./*.h")

add_executable(${OUTPUT_NAME} ${sources} ${headers})
#target_link_libraries(${OUTPUT_NAME} ${LINK_LIBS} -lhdf5_cpp -lhdf5)


