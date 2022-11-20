
cmake_minimum_required(VERSION 3.23)
project(firstCPP)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib/googletest)
add_executable(firstCPP_ch1 src/ch1/hello_world.cpp)


