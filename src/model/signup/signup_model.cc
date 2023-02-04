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

  if (redis_connection.HashSet(username, "password", ToHash(password)))
    return {{"result", true}};

  return {
      {"result", false},
      {"error", "Unknown error in the signup process."}
  };
}
std::string ToHash(const std::string& input) {
  return std::to_string(std::hash<std::string>{}(input));
}
}