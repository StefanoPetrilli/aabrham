//
// Created by Stefano on 2/4/2023.
//
#include "signup_model_test.h"

namespace signup_model_test {
void SingupModelTest::SetUp() {
  redis_connection = redis_connection::RedisConnection();
  if (!redis_connection.IsConnected())
    GTEST_SKIP_("Test skipped because it is impossible to connect to the redis database");
}

TEST_F(SingupModelTest, Expect_ErrorWhenUsernameAlreadyExist) {
  EXPECT_TRUE(redis_connection.HashSet("username", "password", "psw"));

  auto result = signup::Signup("username", "psw");
  crow::json::wvalue expected = {
      {"result", false},
      {"error", "This username is already in use. Try with a different one."}
  };

  EXPECT_TRUE(redis_connection.KeyDelete("username"));
  EXPECT_EQ(expected.dump(), result.dump());
}
}