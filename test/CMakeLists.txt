add_subdirectory(infrastructure)
add_subdirectory(model)

add_executable(aabrham_test
        main_test.cc
        infrastructure/redis/redis_test.cc
        infrastructure/redis/redis_test.h
        infrastructure/hashing/hashing_test.cc
        infrastructure/hashing/hashing_test.h
        model/signup/signup_model_test.cc
        model/signup/signup_model_test.h)

target_link_libraries(aabrham_test
        PUBLIC
        GTest::gtest_main
        Crow
        controller_homepage
        controller_login
        controller_style
        controller_index
        controller_signup
        model_signup
        redis_repository
        hashing)

include(GoogleTest)
gtest_discover_tests(aabrham_test)
