cmake_minimum_required (VERSION 2.8)
project(DecompressionExample)
set (OUTPUT_NAME DecompressionExample)




file(GLOB_RECURSE sources "./*.cpp")
file(GLOB_RECURSE headers "./*.h")


add_executable(${OUTPUT_NAME} ${sources} ${headers})
