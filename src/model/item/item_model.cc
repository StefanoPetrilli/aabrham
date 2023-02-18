//
// Created by Stefano on 2/18/2023.
//

#include "item_model.h"

namespace item {
//TODO write tests
crow::json::wvalue InsertItem(std::string product_name, std::string username) {
  redis_connection::RedisConnection redis_connection;
  std::string key = username + ":objects";

  if (redis_connection.Exist(key, product_name))
    return {
        {"result", false},
        {"error", "An item with the same name is already present in the database. Try with a different name."}
    };

  if (redis_connection.HashSet(key, product_name, ""))
    return {{"result", true}};

  return {
      {"result", false},
      {"error", "Errore nella scrittura dei dati riguardanti l'oggetto sul database."}
  };
}

}
