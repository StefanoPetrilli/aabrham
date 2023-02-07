//
// Created by Stefano on 1/24/2023.
//

#ifndef AABRHAM_SRC_CONTROLLER_SIGNUP_SIGNUP_CONTROLLER_H_
#define AABRHAM_SRC_CONTROLLER_SIGNUP_SIGNUP_CONTROLLER_H_
#include "crow.h"
#include "signup_model.h"
#include "crow/middlewares/cookie_parser.h"
#include "crow/middlewares/session.h"

namespace signup {
void AddSignupController(crow::App<crow::CookieParser, crow::SessionMiddleware<crow::InMemoryStore>> *app);
}
#endif //AABRHAM_SRC_CONTROLLER_SIGNUP_SIGNUP_CONTROLLER_H_
