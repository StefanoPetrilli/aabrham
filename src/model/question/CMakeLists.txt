add_library(model_question
        question_model.cc question_model.h)

target_include_directories(model_question PUBLIC .)
target_link_libraries(model_question
        PUBLIC
        redis_repository
        hashing
        )
