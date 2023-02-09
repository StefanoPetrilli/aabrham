//
// Created by Stefano on 1/24/2023.
//

#ifndef AABRHAM_SRC_CONTROLLER_STYLE_STYLE_CONTROLLER_H_
#define AABRHAM_SRC_CONTROLLER_STYLE_STYLE_CONTROLLER_H_
#include "crow.h"
#include "crow/middlewares/cookie_parser.h"
#include "crow/middlewares/session.h"

namespace style {
void AddStyleController(crow::App<crow::CookieParser, crow::SessionMiddleware<crow::InMemoryStore>> *app);
}

#endif //AABRHAM_SRC_CONTROLLER_STYLE_STYLE_CONTROLLER_H_
