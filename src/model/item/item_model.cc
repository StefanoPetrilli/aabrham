//
// Created by Stefano on 2/18/2023.
//

#include "item_model.h"
//TODO write tests
namespace item {

static long GetTimestampPlusHours(int hours) {
  auto now = std::chrono::system_clock::now().time_since_epoch();
  auto hours_to_add = std::chrono::hours(hours);
  auto result_timestamp = now + hours_to_add;
  return duration_cast<std::chrono::milliseconds>(result_timestamp).count();
}

crow::json::wvalue InsertItem(const std::string& product_name, const std::string& username) { //TODO rewrite using hsetnx
  redis_connection::RedisConnection redis_connection;
  std::string key = username + ":objects";

  if (redis_connection.Exist(key, product_name))
    return {
        {"result", false},
        {"error", "An item with the same name is already present in the database. Try with a different name."}
    };

  crow::json::wvalue field_value = {
      {"time", GetTimestampPlusHours(1)},
      {"hasBeenBought", false} //TODO write an enum to handle the case where a decision has not been made yet
  };

  if (redis_connection.HashSet(key, product_name, field_value.dump()))
    return {{"result", true}};

  return {
      {"result", false},
      {"error", "Errore nella scrittura dei dati riguardanti l'oggetto sul database."}
  };
}

crow::json::wvalue GetItems(const std::string& username) {
  redis_connection::RedisConnection redis_connection;
  auto key = username + ":objects";

  auto objects = redis_connection.HashGetAll(key);
  if (objects.has_value()) {
    crow::json::wvalue result = {
        {"result", true}
    };

    for (auto & it : objects.value()) {
      result["items"][it.first]["time"] = crow::json::load(it.second)["time"];
      result["items"][it.first]["hasBeenBought"] = crow::json::load(it.second)["hasBeenBought"];
    }

    return result;
  }

  return {
      {"result", false},
      {"error", "Error retrieving items from the database."}
  };
}

}
