add_executable(enthusiasm_racing_car_run enthusiasm/struct/RacingCar.cpp)
add_executable(enthusiasm_fruit_1_run ../cmd/enthusiasm/class/FruitSim_1.cpp)
add_executable(enthusiasm_car_run enthusiasm/class/car.cpp)
add_executable(enthusiasm_point_run enthusiasm/class/Point.cpp)
add_executable(enthusiasm_Encaps_1_run enthusiasm/class/Encaps_1.cpp)
add_executable(enthusiasm_Encaps_2_run enthusiasm/class/Encaps_2.cpp)
add_executable(enthusiasm_Constructor_1_run enthusiasm/class/Constructor_1.cpp)
add_executable(enthusiasm_PrivateConstructor_run enthusiasm/class/PrivateConstructor.cpp)
add_executable(enthusiasm_Destructor_run enthusiasm/class/Destructor.cpp)
add_executable(enthusiasm_ObjArr_run enthusiasm/class/ObjArr.cpp)
add_executable(enthusiasm_ObjPtrArr_run enthusiasm/class/ObjPtrArr.cpp)
add_executable(enthusiasm_SelfRef_run enthusiasm/class/SelfRef.cpp)
add_executable(enthusiasm_Banking_run enthusiasm/banking/banking.cpp)

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

target_link_libraries(
        enthusiasm_Constructor_1_run
        Constructor_1
)

target_link_libraries(
        enthusiasm_Destructor_run
        Destructor
)

target_link_libraries(
        enthusiasm_ObjArr_run
        ObjArr
)

target_link_libraries(
        enthusiasm_ObjPtrArr_run
        ObjArr
)

target_link_libraries(
        enthusiasm_SelfRef_run
        SelfRef
)

target_link_libraries(
        enthusiasm_Banking_run
        AccountRepository
        BankService
        Account_Entity
        MainMenu
        MakeAccountForm
        DepositForm
        UserListForm
        WithdrawForm
        Event_Provider
        ViewModelEventListener
        MainMenu_ViewModel
        MakeAccountForm_ViewModel
        DepositForm_ViewModel
        WithdrawForm_ViewModel
        UserListForm_ViewModel
)