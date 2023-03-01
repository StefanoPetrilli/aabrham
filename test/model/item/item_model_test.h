//
// Created by Stefano on 2/26/2023.
//

#ifndef AABRHAM_TEST_MODEL_ITEM_ITEM_MODEL_TEST_H_
#include <gtest/gtest.h>
#include <sw/redis++/redis.h>
#include "item_model.h"
#include <crow.h>

#include "../../../src/infrastructure/redis/redis.h"

namespace item_model_test {
static const std::string kTestUsername = "TestUsernameHopefullyItDoesNotExist";

class ItemModelTest : public ::testing::Test {
 protected:
  static void TearDownTestSuite () {
    redis_connection::RedisConnection::getInstance()->KeyDelete(kTestUsername + ":objects");
  }
  void SetUp() override {
    if (!redis_connection::RedisConnection::getInstance()->IsConnected())
      GTEST_SKIP_("Test skipped because it is impossible to connect to the redis database");
  };
};
}
#define AABRHAM_TEST_MODEL_ITEM_ITEM_MODEL_TEST_H_

#endif //AABRHAM_TEST_MODEL_ITEM_ITEM_MODEL_TEST_H_
