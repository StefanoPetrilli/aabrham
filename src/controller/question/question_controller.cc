//
// Created by Stefano on 2/22/2023.
//

#include "question_controller.h"

namespace question {
void AddQuestionController(crow::App<crow::CookieParser, crow::SessionMiddleware<crow::InMemoryStore>> *app) {
  auto &aabrham = *app;

  CROW_ROUTE(aabrham, "/api/question/get")
      ([&](const crow::request &request) {
        auto &session = aabrham.get_context<crow::SessionMiddleware<crow::InMemoryStore >>(request);
        crow::response response;
        crow::mustache::context ctx;

        if (!session::IsLogged(session))
          response = crow::response(401, "To perform this action, first you should login.");
        else
          response = question::GetQuestions();

        return response;
      });
}
}

