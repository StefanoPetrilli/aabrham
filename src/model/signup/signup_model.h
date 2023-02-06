//
// Created by Stefano on 2/4/2023.
//

#ifndef AABRHAM_SRC_MODEL_SINGUP_SIGNUP_MODEL_H_
#define AABRHAM_SRC_MODEL_SINGUP_SIGNUP_MODEL_H_
#include <crow/json.h>

#include "../../infrastructure/redis/redis.h"
#include "../../infrastructure/hashing/hashing.h"

namespace signup {
  crow::json::wvalue Signup(const std::string& username, const std::string& password);
}
#endif //AABRHAM_SRC_MODEL_SINGUP_SIGNUP_MODEL_H_
