//
// Created by Stefano on 2/4/2023.
//

#include "login_model.h"

namespace login {
crow::json::wvalue Login(const std::string &username, const std::string &password) {

  auto redis_connection = redis_connection::RedisConnection::getInstance();

  if (!redis_connection->IsConnected())
    return {
        {"result", false},
        {"error", "Error connecting to the database."}
    };

  if (!redis_connection->Exist(username))
    return {
        {"result", false},
        {"error", "The username is not in the database. You might want to "}
      };

  auto stored_password = redis_connection->HashGet(username, "password");
  if (stored_password->empty())
    return {
        {"result", false},
        {"error", "Error in the login process"}
    };

  if (stored_password.value() != hashing::ToHash(password))
    return {
        {"result", false},
        {"error", "The combination of username and password does not correspond to any user."}
    };

  return {{"result", true}, {"token", 1}};
}
}