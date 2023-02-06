//
// Created by Stefano on 2/4/2023.
//

#include "signup_model.h"

namespace signup {
crow::json::wvalue Signup(const std::string &username, const std::string &password) {

  redis_connection::RedisConnection redis_connection;

  if (redis_connection.Exist(username))
    return {
        {"result", false},
        {"error", "This username is already in use. Try with a different one."}
    };

  if (redis_connection.HashSet(username, "password", hashing::ToHash(password)))
    return {{"result", true}};

  return {
      {"result", false},
      {"error", "Unknown error in the signup process."}
  };
}
}