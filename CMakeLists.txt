cmake_minimum_required (VERSION 2.8)
project(AutoDrive)

file(GLOB_RECURSE sources "./src/*.cpp")
file(GLOB_RECURSE headers "./src/*.h")

add_executable(AutoDrive  ${sources} ${headers})
