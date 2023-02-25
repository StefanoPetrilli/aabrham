//
// Created by Stefano on 2/22/2023.
//

#ifndef AABRHAM_SRC_MODEL_QUESTION_H_
#define AABRHAM_SRC_MODEL_QUESTION_H_
#include <crow.h>
#include <string>
#include "../../infrastructure/redis/redis.h"

namespace question {
static const std::string kQuestionKey = "question";
crow::json::wvalue GetQuestions();
}
#endif //AABRHAM_SRC_MODEL_QUESTION_H_
