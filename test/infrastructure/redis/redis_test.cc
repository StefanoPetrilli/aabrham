//
// Created by Stefano on 2/2/2023.
//
#include "redis_test.h"

namespace redis_connection_test {

void RedisTest::SetUp() {
  redis_connection = redis_connection::RedisConnection();
  if (!redis_connection.IsConnected())
    GTEST_SKIP_("Test skipped because it is impossible to connect to the redis database");
}

TEST_F(RedisTest, Expect_CorrectWrite) {
  EXPECT_TRUE(redis_connection.HashSet("TestKey", "TestField", "TestValue"));
}

TEST_F(RedisTest, Expect_SuccesfullReadFromDatabase) {
  auto result = redis_connection.HashGet("TestKey", "TestField").value();
  auto expected = "TestValue";

  EXPECT_EQ(expected, result);
}

TEST_F(RedisTest, Expect_Exist) {
  EXPECT_TRUE(redis_connection.Exist("TestKey"));
  EXPECT_FALSE(redis_connection.Exist("NonExistentKey"));
}

TEST_F(RedisTest, Expect_SuccesfullDeleteFromDatabase) {
  EXPECT_TRUE(redis_connection.KeyDelete("TestKey"));
}
}