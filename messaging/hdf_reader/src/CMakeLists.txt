cmake_minimum_required (VERSION 3.1.0)
project (HDF5FileReaderExample)

find_package (HDF5 NAMES hdf5 COMPONENTS CXX static)
#find_package (HDF5) 
#include_directories(${HDF5_INCLUDE_DIR})

set (LINK_LIBS ${LINK_LIBS} ${HDF5_C_STATIC_LIBRARY})

set (example HDFFileReaderExample)

add_executable (${example} ${PROJECT_SOURCE_DIR}/${example}.cpp)

target_link_libraries (${example} ${LINK_LIBS})
