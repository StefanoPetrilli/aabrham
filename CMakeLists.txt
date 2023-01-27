cmake_minimum_required(VERSION 3.22)
project(aabrham)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(FETCHCONTENT_QUIET off)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--whole-archive -Wl,--no-whole-archive")
add_compile_options(-Wall -Wextra -Wpedantic -Werror)

include_directories(include)

# Include google test
include(FetchContent)
include(GoogleTest)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

# Import Crow
add_library(Crow include/crow.h)
target_include_directories(Crow PUBLIC include)
set_target_properties(Crow PROPERTIES LINKER_LANGUAGE CXX)


# Inmport Redis-plus-plus
find_path(HIREDIS_HEADER hiredis)
find_path(REDIS_PLUS_PLUS_HEADER sw)
find_library(HIREDIS_LIB hiredis)
find_library(REDIS_PLUS_PLUS_LIB redis++)

add_subdirectory(src)
