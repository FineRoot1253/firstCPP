cmake_minimum_required(VERSION 3.23)
project(firstCPP)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)
include_directories(lib)

add_subdirectory(cmd)
add_subdirectory(src)
add_subdirectory(lib)
add_subdirectory(test)
add_subdirectory(lib/googletest)


