add_library(model_login
        login_model.cc login_model.h)

target_include_directories(model_login PUBLIC .)
target_link_libraries(model_login
        PUBLIC
        redis_repository
        hashing
        )
