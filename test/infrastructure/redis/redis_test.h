//
// Created by Stefano on 2/2/2023.
//

#ifndef AABRHAM_TEST_INFRASTRUCTURE_REDIS_REDIS_TEST_H_
#define AABRHAM_TEST_INFRASTRUCTURE_REDIS_REDIS_TEST_H_
#include <gtest/gtest.h>
#include <sw/redis++/redis.h>

#include "../../../src/infrastructure/redis/redis.h"

namespace redis_connection_test {
class RedisTest : public ::testing::Test {
 public:
  redis_connection::RedisConnection redis_connection;
  void SetUp();
};
}
#endif //AABRHAM_TEST_INFRASTRUCTURE_REDIS_REDIS_TEST_H_
