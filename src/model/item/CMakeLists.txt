add_library(model_item
        item_model.cc item_model.h)

target_include_directories(model_item PUBLIC .)
target_link_libraries(model_item
        PUBLIC
        redis_repository
        )
