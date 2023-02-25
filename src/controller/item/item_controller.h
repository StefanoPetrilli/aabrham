//
// Created by Stefano on 2/18/2023.
//

#ifndef AABRHAM_SRC_CONTROLLER_ITEM_ITEM_CONTROLLER_H_
#define AABRHAM_SRC_CONTROLLER_ITEM_ITEM_CONTROLLER_H_
#include <crow.h>
#include "crow/middlewares/cookie_parser.h"
#include "crow/middlewares/session.h"
#include "session.h"
#include "item_model.h"

namespace item {
void AddItemController(crow::App<crow::CookieParser, crow::SessionMiddleware<crow::InMemoryStore>> *app);
}
#endif //AABRHAM_SRC_CONTROLLER_ITEM_ITEM_CONTROLLER_H_
