cmake_minimum_required(VERSION 3.22)
project(aabrham)

set(CMAKE_CXX_STANDARD 20)
set(FETCHCONTENT_QUIET off)
set(CMAKE_CXX_STANDARD_LIBRARIES "${CMAKE_CXX_STANDARD_LIBRARIES} -static-libgcc -static-libstdc++")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -Wl,--no-whole-archive")
add_compile_options(-Wall -Wextra -Wpedantic -Werror)

include_directories(include)

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

#add_library(rediscpp include/redis-cpp)
#target_include_directories(rediscpp PUBLIC include)
#set_target_properties(rediscpp PROPERTIES LINKER_LANGUAGE CXX)

add_library(Crow include/crow.h)
target_include_directories(Crow PUBLIC include)
set_target_properties(Crow PROPERTIES LINKER_LANGUAGE CXX)

add_subdirectory(src)
