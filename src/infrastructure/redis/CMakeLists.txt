add_library(redis_repository
        redis.cc redis.h)

target_include_directories(redis_repository PUBLIC ${REDIS_PLUS_PLUS_HEADER} ${HIREDIS_HEADER})
target_link_libraries(redis_repository
        PUBLIC
        ${HIREDIS_LIB}
        ${REDIS_PLUS_PLUS_HEADER}
        ${REDIS_PLUS_PLUS_LIB}
        configuration
        )
