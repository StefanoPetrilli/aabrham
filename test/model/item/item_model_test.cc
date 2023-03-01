//
// Created by Stefano on 2/26/2023.
//

#include "item_model_test.h"

namespace item_model_test {
TEST_F(ItemModelTest, InsertItem_Expect_SuccessMessage_If_ItemDoesNotExist) {

  crow::json::rvalue item_data = crow::json::load(R"({"itemName":"1231231232"})");
  auto result = item::InsertItem(item_data, kTestUsername);
  crow::json::wvalue expected = {{"result", true}};

  EXPECT_EQ(expected.dump(), result.dump());
}

TEST_F(ItemModelTest, InsertItem_Expect_Error_If_ItemExist) {
  if (!redis_connection::RedisConnection::getInstance()->Exist(kTestUsername + ":objects"))
    GTEST_SKIP_("The data needed to effectively run the test are missing.");

  crow::json::rvalue item_data = crow::json::load(R"({"itemName":"1231231232"})");
  auto result = item::InsertItem(item_data, kTestUsername);
  crow::json::wvalue expected = {
      {"result", false},
      {"error", "An item with the same name is already present in the database. Try with a different name."}
  };

  EXPECT_EQ(expected.dump(), result.dump());
}

TEST_F(ItemModelTest, GetItems_Expect_Error_IfItemDoesNotExist) {
  if (redis_connection::RedisConnection::getInstance()->Exist(kTestUsername + "NonExistent:objects"))
    GTEST_SKIP_("The data needed to run the test already exist.");

  auto result = item::GetItems(kTestUsername + "NonExistent");
  crow::json::wvalue expected = {
      {"result", false},
      {"error", "Error retrieving items from the database."}
  };

  EXPECT_EQ(expected.dump(), result.dump());
}

TEST_F(ItemModelTest, GetItems_Expect_SuccessMessage_IfItemExist) {
  if (!redis_connection::RedisConnection::getInstance()->Exist(kTestUsername + ":objects"))
    GTEST_SKIP_("The data needed to run the test does not exist.");

  auto result = item::GetItems(kTestUsername);
  crow::json::wvalue expected = {
      {"result", true}
  };

  EXPECT_EQ(expected["result"].dump(), result["result"].dump());
}
}