//
// Created by Stefano on 2/18/2023.
//

#include "item_model.h"
//TODO write tests
namespace item {

crow::json::wvalue InsertItem(const crow::json::rvalue &item_data,
                              const std::string &username) { //TODO rewrite using hsetnx
  redis_connection::RedisConnection redis_connection;
  auto key = username + ":objects";
  auto itemName = item_data["itemName"].s();

  if (redis_connection.Exist(key, itemName))
    return {
        {"result", false},
        {"error", "An item with the same name is already present in the database. Try with a different name."}
    };

  crow::json::wvalue field_value = {
      {"time", GetDelay(item_data)},
      {"hasBeenBought", false}
  };

  if (redis_connection.HashSet(key, itemName, field_value.dump()))
    return {{"result", true}};

  return {
      {"result", false},
      {"error", "Errore nella scrittura dei dati riguardanti l'oggetto sul database."}
  };
}

crow::json::wvalue GetItems(const std::string &username) {
  redis_connection::RedisConnection redis_connection;
  auto key = username + ":objects";

  auto objects = redis_connection.HashGetAll(key);
  if (objects.has_value()) {
    crow::json::wvalue result = {
        {"result", true}
    };

    for (auto &it : objects.value()) {
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

static long GetTimestampPlusHours(int hours) {
  auto now = std::chrono::system_clock::now().time_since_epoch();
  auto hours_to_add = std::chrono::hours(hours);
  auto result_timestamp = now + hours_to_add;
  return duration_cast<std::chrono::milliseconds>(result_timestamp).count();
}

long GetDelay(const crow::json::rvalue &values) {
  int hoursNumber = 0;

  for (const auto &v : values.keys()) {
    if (v == "itemName") continue;
    hoursNumber += GetNumberOfHoursCorrespondingToAnswer(v, values[v]);
  }

  return GetTimestampPlusHours(hoursNumber);
}

int GetNumberOfHoursCorrespondingToAnswer(const std::string &key, const crow::json::rvalue &answer) {
  redis_connection::RedisConnection redis_connection;
  std::string field = key + ":";

  switch (answer.t()) {
    case crow::json::type::Number:field += std::to_string(answer.i());
      break;
    default:field += answer.s();
      break;
  }

  auto hours = redis_connection.HashGet(kQuestionEvalKey, field);
  if (hours.has_value()) return std::stoi(hours.value());

  return -1;
}

}
