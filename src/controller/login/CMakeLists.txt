add_library(controller_login
        login_controller.cc login_controller.h)

target_include_directories(controller_login PUBLIC .)
target_link_libraries(controller_login
        PUBLIC
        model_login
        session
        )