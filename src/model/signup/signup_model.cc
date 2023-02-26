//
// Created by Stefano on 2/4/2023.
//

#include "signup_model.h"

namespace signup {
crow::json::wvalue Signup(const std::string &username, const std::string &password) {

  auto redis_connection = redis_connection::RedisConnection::getInstance();

  if (!redis_connection->IsConnected())
    return {
        {"result", false},
        {"error", "Error connecting to the database."}
    };

  if (redis_connection->Exist(username))
    return {
        {"result", false},
        {"error", "This username is already in use. Try with a different one."}
    };

  if (redis_connection->HashSet(username, "password", hashing::ToHash(password)))
    return {{"result", true}};

  return {
      {"result", false},
      {"error", "Unknown error in the signup process."}
  };
}
}