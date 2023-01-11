#file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(firstCPP_ch1 ch1/hello_world.cpp)
add_executable(pointer_run ch1/pointer.cpp)
add_executable(heap_run ch1/heap.cpp)
add_executable(mypet_run ch1/mypet.cpp)
add_executable(animal_run ch2/animal.cpp)
add_executable(overloading_ex_run ch2/overloading.cpp)

add_library(Geometry STATIC ch2/Geometry.cpp)
target_include_directories(Geometry PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(Geometry PUBLIC Point Line)
#add_dependencies(Geometry DynamicArray Line Point)