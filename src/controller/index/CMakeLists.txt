add_library(controller_index
        index_controller.cc index_controller.h)

target_include_directories(controller_index PUBLIC .)
target_link_libraries(controller_index
        PUBLIC
        session
        )