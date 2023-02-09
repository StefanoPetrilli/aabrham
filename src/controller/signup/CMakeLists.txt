add_library(controller_signup
        signup_controller.cc signup_controller.h)

target_include_directories(controller_signup PUBLIC .)
target_link_libraries(controller_signup
        PUBLIC
        model_signup
        session
        )