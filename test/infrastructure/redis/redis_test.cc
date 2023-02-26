//
// Created by Stefano on 2/2/2023.
//
#include "redis_test.h"

namespace redis_connection_test {

void RedisTest::SetUp() {
  redis_connection = redis_connection::RedisConnection::getInstance();
  if (!redis_connection->IsConnected())
    GTEST_SKIP_("Test skipped because it is impossible to connect to the redis database");
}

TEST_F(RedisTest, HashSet_Expect_CorrectWrite_WhenTheKeyDoesNotExist) {
  if (redis_connection->Exist("TestKey", "TestField") || redis_connection->Exist("TestKey", "TestField2"))
    GTEST_SKIP_("Test is skipped because the keys and field needed to perform the test already exist");

  EXPECT_TRUE(redis_connection->HashSet("TestKey", "TestField", "TestValue"));
  EXPECT_TRUE(redis_connection->HashSet("TestKey", "TestField2", "TestValue2"));
}

TEST_F(RedisTest, HashSet_Expect_False_WhenTheKeyAlreadyExist) {
  if (!redis_connection->Exist("TestKey", "TestField"))
    GTEST_SKIP_("Test is skipped because the keys and field needed to perform the test does not exist");

  EXPECT_FALSE(redis_connection->HashSet("TestKey", "TestField", "TestValue"));
}

TEST_F(RedisTest, HashGet_Expect_SuccesfullReadFromDatabase_WhenKeyExist) {
  if (!redis_connection->Exist("TestKey", "TestField"))
    GTEST_SKIP_("Test is skipped because the keys and field needed to perform the test does not exist");

  auto result = redis_connection->HashGet("TestKey", "TestField").value();
  auto expected = "TestValue";

  EXPECT_EQ(expected, result);
}

TEST_F(RedisTest, HashGet_Expect_EmptyResult_WhenKeyDoesNotExist) {
  if (redis_connection->Exist("TestKeyNotExistent"))
    GTEST_SKIP_("Test is skipped because the keys and field needed to perform the test already exist");

  EXPECT_FALSE(redis_connection->HashGet("TestKeyNotExistent", "TestField").has_value());
}

TEST_F(RedisTest, HashGetAll_Expect_SuccesfullReadFromDatabase_WhenKeyExist) {
  if (!redis_connection->Exist("TestKey"))
    GTEST_SKIP_("Test is skipped because the keys and field needed to perform the does not exist");

  auto result = redis_connection->HashGetAll("TestKey").value();
  std::unordered_map<std::string, std::string> expected = {{"TestField", "TestValue"},
               {"TestField2", "TestValue2"}};

  EXPECT_EQ(expected, result);
}

TEST_F(RedisTest, HashGetAll_Expect_EmptyResut_WhenKeyDoesNotExist) {
  if (redis_connection->Exist("TestKeyNotExistent"))
    GTEST_SKIP_("Test is skipped because the keys and field needed to perform the test does not exist");
  EXPECT_FALSE(redis_connection->HashGetAll("TestKeyNotExistent").has_value());
}

TEST_F(RedisTest, Exist_Expect_Exist) {
  EXPECT_TRUE(redis_connection->Exist("TestKey"));
  EXPECT_FALSE(redis_connection->Exist("NonExistentKey"));
}

TEST_F(RedisTest, KeyDelete_Expect_SuccesfullDeleteFromDatabase) {
  if (!redis_connection->Exist("TestKey"))
    GTEST_SKIP_("Test is skipped because the keys and field needed to perform the does not exist");

  EXPECT_TRUE(redis_connection->KeyDelete("TestKey"));
}

TEST_F(RedisTest, KeyDelete_Expect_False_WhenKeyDoesNotExist) {
  if (redis_connection->Exist("TestKeyNotExistent"))
    GTEST_SKIP_("Test is skipped because the keys and field needed to perform the test exist");

  EXPECT_FALSE(redis_connection->KeyDelete("TestKeyNotExistent"));
}
}