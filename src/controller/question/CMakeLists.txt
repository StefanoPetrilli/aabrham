add_library(controller_question
        question_controller.cc question_controller.h)

target_include_directories(controller_question PUBLIC .)
target_link_libraries(controller_question
        PUBLIC
        model_question
        session
        )