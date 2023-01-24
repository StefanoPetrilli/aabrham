add_subdirectory(controller)
add_subdirectory(view)
add_subdirectory(model)

add_executable(aabrham main.cc)
target_link_libraries(aabrham
        PUBLIC
        Crow
        controller_homepage
        controller_login
        controller_style
        controller_index
        controller_signup)
