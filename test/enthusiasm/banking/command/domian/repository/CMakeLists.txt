add_executable(
        AccountRepository_test
        AccountRepository_test.cc
)

target_link_libraries(
        AccountRepository_test
        AccountRepository
        Account_Entity
        NormalAccount_Entity
        HighCreditAccount_Entity
        GTest::gtest_main
)


include(GoogleTest)
gtest_discover_tests(AccountRepository_test)