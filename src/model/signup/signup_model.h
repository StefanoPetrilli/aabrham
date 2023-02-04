//
// Created by Stefano on 2/4/2023.
//

#ifndef AABRHAM_SRC_MODEL_SINGUP_SIGNUP_MODEL_H_
#define AABRHAM_SRC_MODEL_SINGUP_SIGNUP_MODEL_H_
#include <crow/json.h>

#include "../../infrastructure/redis/redis.h"

namespace signup {
  crow::json::wvalue Signup(const std::string& username, const std::string& password);
  std::string ToHash(const std::string& input);
}
#endif //AABRHAM_SRC_MODEL_SINGUP_SIGNUP_MODEL_H_
