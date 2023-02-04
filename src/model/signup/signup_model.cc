//
// Created by Stefano on 2/4/2023.
//

#include "signup_model.h"

namespace signup {
crow::json::wvalue Signup(const std::string &username, const std::string &password) {

  redis_connection::RedisConnection redis_connection;
  crow::json::wvalue response;

  if (redis_connection.Exist(username))
    response = {
        {"result", false},
        {"error", "This username is already in use. Try with a different one."}
    };

  std::cout << password; //-Wall

  return response;
}
}