add_executable(
        Account_test
        Account_test.cc
)

target_link_libraries(
        Account_test
        Account_Entity
        GTest::gtest_main
)


include(GoogleTest)
gtest_discover_tests(Account_test)