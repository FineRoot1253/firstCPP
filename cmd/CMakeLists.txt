add_executable(enthusiasm_racing_car_run enthusiasm/struct/RacingCar.cpp)
add_executable(enthusiasm_fruit_1_run ../cmd/enthusiasm/class/FruitSim_1.cpp)
add_executable(enthusiasm_car_run enthusiasm/class/car.cpp)
add_executable(enthusiasm_point_run enthusiasm/class/Point.cpp)
add_executable(enthusiasm_Encaps_1_run enthusiasm/class/Encaps_1.cpp)
add_executable(enthusiasm_Encaps_2_run enthusiasm/class/Encaps_2.cpp)

target_link_libraries(
        enthusiasm_racing_car_run
        RacingCar
)
target_link_libraries(
        enthusiasm_car_run
        Car
)
target_link_libraries(
        enthusiasm_fruit_1_run
        FruitSeller
        FruitBuyer
)

target_link_libraries(
        enthusiasm_point_run
        Rectangle
        Enthusiasm_Point
)

target_link_libraries(
        enthusiasm_Encaps_1_run
        Encaps_1
)

target_link_libraries(
        enthusiasm_Encaps_2_run
        Encaps_2
)