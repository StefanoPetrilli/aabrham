//
// Created by Stefano on 2/22/2023.
//

#include "question_model.h"

namespace question {

crow::json::wvalue GetQuestions() {
  redis_connection::RedisConnection redis_connection;
  auto question = redis_connection.HashGetAll(kQuestionKey);

  if (question.has_value()) {
    crow::json::wvalue result = {
        {"result", true}
    };

    for (auto &it : question.value())
      result["questions"][it.first] = crow::json::load(it.second);

    return result;
  }

  return {
      {"result", false},
      {"error", "Error retrieving questions from the database."}
  };
}
}