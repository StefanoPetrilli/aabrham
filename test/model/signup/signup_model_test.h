//
// Created by Stefano on 2/4/2023.
//

#ifndef AABRHAM_TEST_MODEL_SIGNUP_SIGNUP_MODEL_TEST_H_
#define AABRHAM_TEST_MODEL_SIGNUP_SIGNUP_MODEL_TEST_H_
#include <gtest/gtest.h>
#include <sw/redis++/redis.h>
#include "signup_model.h"

#include "../../../src/infrastructure/redis/redis.h"

namespace signup_model_test {
class SingupModelTest : public ::testing::Test {
 public:
  redis_connection::RedisConnection redis_connection;
  void SetUp();
};
}
#endif //AABRHAM_TEST_MODEL_SIGNUP_SIGNUP_MODEL_TEST_H_
