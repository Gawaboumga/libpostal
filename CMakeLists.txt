cmake_minimum_required(VERSION 3.13)
project(libpostal)

set(CMAKE_C_STANDARD 99)

SET(datadir "WHERE ARE THE LIBPOSTAL DATA STORED https://github.com/openvenues/libpostal/releases/tag/v1.0.0")
add_definitions(-DLIBPOSTAL_DATA_DIR="${datadir}")
add_definitions(-DLIBPOSTAL_EXPORTS=1)
add_definitions(-DUTF8PROC_EXPORTS=1)

add_subdirectory(src)
add_subdirectory(test)
