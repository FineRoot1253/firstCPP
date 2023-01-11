add_executable(
        date_test
        date_test.cc
)
add_executable(
        geometry_test
        geometry_test.cc
)

target_link_libraries(
        date_test
        GTest::gtest_main
)
target_link_libraries(
        geometry_test
        Geometry
        GTest::gtest_main
)


include(GoogleTest)
gtest_discover_tests(date_test)
gtest_discover_tests(geometry_test)