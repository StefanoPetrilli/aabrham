add_library(redis_repository
        repository.cc repository.h)

target_include_directories(redis_repository PUBLIC .)