//
// Created by Stefano on 2/4/2023.
//

#include "login_model.h"

namespace login {
crow::json::wvalue Login(const std::string &username, const std::string &password) {

  redis_connection::RedisConnection redis_connection;

  if (!redis_connection.Exist(username))
    return {
        {"result", false},
        {"error", "The username is not in the database. You might want to "}
      };

  auto stored_password = redis_connection.HashGet(username, "password");
  if (stored_password->empty())
    return {
        {"result", false},
        {"error", "Error in the login process, contact the developer: "} //TODO add contacts
    };

  if (stored_password.value() != hashing::ToHash(password))
    return {
        {"result", false},
        {"error", "The combination of username and password does not correspond to any user."}
    };

  return {{"result", true}, {"token", 1}};
}
}