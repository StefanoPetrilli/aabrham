//
// Created by Stefano on 2/7/2023.
//

#ifndef AABRHAM_SRC_INFRASTRUCTURE_SESSION_SESSION_H_
#define AABRHAM_SRC_INFRASTRUCTURE_SESSION_SESSION_H_
#include <crow/app.h>
#include "crow/middlewares/session.h"

namespace session {
bool IsLogged(crow::App<crow::CookieParser, crow::SessionMiddleware<crow::InMemoryStore>> *app, const crow::request &request);
}
#endif //AABRHAM_SRC_INFRASTRUCTURE_SESSION_SESSION_H_
