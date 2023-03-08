add_executable(
        BankService_test
        BankService_test.cc
)

target_link_libraries(
        BankService_test
        BankService
        AccountRepository
        Account_Entity
)

target_link_libraries(
        BankService_test
        gtest
        gtest_main
)


include(GoogleTest)
gtest_discover_tests(BankService_test)