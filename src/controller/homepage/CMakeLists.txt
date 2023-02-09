add_library(controller_homepage
        homepage_controller.cc homepage_controller.h)

target_include_directories(controller_homepage PUBLIC .)
target_link_libraries(controller_homepage
        PUBLIC
        session
        )
