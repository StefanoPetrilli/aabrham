add_library(configuration
        configuration.cc configuration.h)

target_include_directories(configuration PUBLIC .)
target_link_libraries(configuration
        PUBLIC
        file
        )
