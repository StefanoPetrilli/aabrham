//
// Created by Stefano on 2/7/2023.
//
#include "session.h"

namespace session {
bool IsLogged(crow::SessionMiddleware<crow::InMemoryStore>::context &session) {
  std::string key_content = session.get<std::string>("IsLogged");
  return !key_content.empty();
}

void StartSession(crow::SessionMiddleware<crow::InMemoryStore>::context &session, std::string username) {
  session.set("IsLogged", "true");
  session.set("Username", username);
}

void Signout(crow::SessionMiddleware<crow::InMemoryStore>::context &session) {
  session.remove("IsLogged");
  session.remove("Username");
}

std::string GetUsername(crow::SessionMiddleware<crow::InMemoryStore>::context &session) {
  return session.get<std::string>("Username");
}
}
