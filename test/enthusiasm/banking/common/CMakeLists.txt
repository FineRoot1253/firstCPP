add_executable(
        HList_test
        HList_test.cc
)

add_executable(
        Utils_test
        utils_test.cc
)

#
#target_link_libraries(
#        HList_test
#        BankService
#        AccountRepository
#        Account_Entity
#)

target_link_libraries(
        HList_test
        gtest
        gtest_main
)

target_link_libraries(
        Utils_test
        gtest
        gtest_main
)


include(GoogleTest)
gtest_discover_tests(HList_test)
gtest_discover_tests(Utils_test)