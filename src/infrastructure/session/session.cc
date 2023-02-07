//
// Created by Stefano on 2/7/2023.
//
#include "session.h"

namespace session {
bool IsLogged(crow::App<crow::CookieParser, crow::SessionMiddleware<crow::InMemoryStore>> *app, const crow::request &request) {
  auto &aabrham = *app;

  auto &session = aabrham.get_context<crow::SessionMiddleware<crow::InMemoryStore>>(request);
  std::string string_v = session.get<std::string>("key");
  return string_v.empty();
}
}
