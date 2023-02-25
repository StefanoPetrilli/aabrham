add_subdirectory(controller)
add_subdirectory(view)
add_subdirectory(model)
add_subdirectory(infrastructure)

add_executable(aabrham main.cc)

find_package(Crow)
target_link_libraries(aabrham
        PUBLIC
        Crow::Crow
        controller_homepage
        controller_login
        controller_style
        controller_index
        controller_signup
        controller_assets
        controller_item
        controller_question
        redis_repository
        )
