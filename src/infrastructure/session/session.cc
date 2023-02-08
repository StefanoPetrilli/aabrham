//
// Created by Stefano on 2/7/2023.
//
#include "session.h"

namespace session {
bool IsLogged(crow::SessionMiddleware<crow::InMemoryStore>::context &session) {
  std::string key_content = session.get<std::string>("IsLogged");
  return !key_content.empty();
}

void StartSession(crow::SessionMiddleware<crow::InMemoryStore>::context &session) {
  session.set("IsLogged", "true");
}
}
