//
// Created by Stefano on 1/22/2023.
//

#include "login_controller.h"

namespace login {
void AddLoginController(crow::App<crow::CookieParser, crow::SessionMiddleware<crow::InMemoryStore>> *app) {
  auto &aabrham = *app;

  CROW_ROUTE(aabrham, "/login")
      ([&](const crow::request &request) {
        auto &session = aabrham.get_context<crow::SessionMiddleware<crow::InMemoryStore>>(request);
        crow::response response;
        crow::mustache::context ctx;

        if (session::IsLogged(session))
          response.redirect("/homepage");
        else
          response.body = crow::mustache::load_text("login/loginTemplate.html");

        return response;
      });

  CROW_ROUTE(aabrham, "/loginDirective.js")([]() {
    crow::mustache::context ctx;
    return crow::mustache::load_text("login/loginDirective.js");
  });

  CROW_ROUTE(aabrham, "/login/api/<string>/<string>")
      ([&](const crow::request &request, const std::string &username, const std::string &password) {
        auto &session = aabrham.get_context<crow::SessionMiddleware<crow::InMemoryStore >>(request);
        crow::json::wvalue response = login::Login(username, password);

        if (IsPositive(response))
          session::StartSession(session);

        return crow::response(std::move(response));
      });
}

bool IsPositive(crow::json::wvalue response) {
  return response["result"].dump() == "true"; //Is there a more elegant way of doing this?
}
}
