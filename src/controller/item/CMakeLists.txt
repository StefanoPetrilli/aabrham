add_library(controller_item
        item_controller.cc item_controller.h)

target_include_directories(controller_item PUBLIC .)
target_link_libraries(controller_item
        PUBLIC
        session
        model_item
        )