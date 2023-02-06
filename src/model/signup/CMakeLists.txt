add_library(model_signup
        signup_model.cc signup_model.h)

target_include_directories(model_signup PUBLIC .)
target_link_libraries(model_signup
        PUBLIC
        redis_repository
        hashing
        )
