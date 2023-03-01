//
// Created by Stefano on 2/4/2023.
//
#include "login_model_test.h"

namespace login_model_test {
void LoginModelTest::SetUp() {
  redis_connection = redis_connection::RedisConnection::getInstance();
  if (!redis_connection->IsConnected())
    GTEST_SKIP_("Test skipped because it is impossible to connect to the redis database");
}

TEST_F(LoginModelTest, Expect_Error_WhenUsernameAndPasswordDoesNotCorrespond) {
  EXPECT_TRUE(redis_connection->HashSet("username", "password", "psw"));

  auto result = login::Login("username", "psw");
  crow::json::wvalue expected = {
      {"result", false},
      {"error", "The combination of username and password does not correspond to any user."}
  };

  EXPECT_TRUE(redis_connection->KeyDelete("username"));
  EXPECT_EQ(expected.dump(), result.dump());
}

TEST_F(LoginModelTest, Expect_Error_WhenUsernameDoesNotExist) {

  auto result = login::Login("UnregisteredUsername", "psw");
  crow::json::wvalue expected = {
      {"result", false},
      {"error", "The username is not in the database. You might want to "}
  };

  EXPECT_EQ(expected.dump(), result.dump());
}

TEST_F(LoginModelTest, Expect_Success_WhenUsernameAndPasswordExist) {

  if(redis_connection->HashSet("unregistered_user", "password", hashing::ToHash("psw")))
    GTEST_SKIP_("The username used for the test: unregistered_user, does not exist.");

  auto result = login::Login("unregistered_user", "psw");
  crow::json::wvalue expected = {
      {"result", true},
      {"token", 1}
  };

  EXPECT_EQ(expected.dump(), result.dump());
}
}
