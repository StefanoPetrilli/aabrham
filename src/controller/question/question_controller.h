//
// Created by Stefano on 2/22/2023.
//

#ifndef AABRHAM_SRC_CONTROLLER_QUESTION_QUESTION_H_
#define AABRHAM_SRC_CONTROLLER_QUESTION_QUESTION_H_
#include <crow.h>
#include "crow/middlewares/cookie_parser.h"
#include "crow/middlewares/session.h"
#include "session.h"
#include "question_model.h"

namespace question {
void AddQuestionController(crow::App<crow::CookieParser, crow::SessionMiddleware<crow::InMemoryStore>> *app);
}

#endif //AABRHAM_SRC_CONTROLLER_QUESTION_QUESTION_H_
