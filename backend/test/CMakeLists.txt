add_executable(aabrham_test main_test.cc)

target_link_libraries(aabrham_test PUBLIC GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(aabrham_test)
