//
// Created by Stefano on 1/22/2023.
//

#ifndef AABRHAM_BACKEND_SRC_CONTROLLER_HOMEPAGE_HOMEPAGE_CONTROLLER_H_
#define AABRHAM_BACKEND_SRC_CONTROLLER_HOMEPAGE_HOMEPAGE_CONTROLLER_H_
#include <crow.h>
#include "crow/middlewares/cookie_parser.h"
#include "crow/middlewares/session.h"
#include "session.h"

namespace homepage {
void AddHomepageController(crow::App<crow::CookieParser, crow::SessionMiddleware<crow::InMemoryStore>> *app);
}

#endif //AABRHAM_BACKEND_SRC_CONTROLLER_HOMEPAGE_HOMEPAGE_CONTROLLER_H_
