//
// Created by Stefano on 2/11/2023.
//

#ifndef AABRHAM_SRC_CONTROLLER_ASSETS_ASSETS_CONTROLLER_H_
#define AABRHAM_SRC_CONTROLLER_ASSETS_ASSETS_CONTROLLER_H_
#include <crow.h>
#include "crow/middlewares/cookie_parser.h"
#include "crow/middlewares/session.h"

namespace assets {
void AddAssetsController(crow::App<crow::CookieParser, crow::SessionMiddleware<crow::InMemoryStore>> *app);
}
#endif //AABRHAM_SRC_CONTROLLER_ASSETS_ASSETS_CONTROLLER_H_
