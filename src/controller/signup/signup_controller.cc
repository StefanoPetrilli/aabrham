//
// Created by Stefano on 1/24/2023.
//

#include "signup_controller.h"

namespace signup {
void AddSignupController(crow::App<crow::CookieParser, crow::SessionMiddleware<crow::InMemoryStore>> *app) {
  auto &aabrham = *app;

  CROW_ROUTE(aabrham, "/signup")
      ([&](const crow::request &request) {
        auto &session = aabrham.get_context<crow::SessionMiddleware<crow::InMemoryStore >>(request);
        crow::response response;
        crow::mustache::context ctx;

        if (session::IsLogged(session))
          response.redirect("/homepage");
        else
          response.body = crow::mustache::load_text("signup/signupTemplate.html");

        return response;
      });

  CROW_ROUTE(aabrham, "/signupDirective.js")([]() {
    crow::mustache::context ctx;
    return crow::mustache::load_text("signup/signupDirective.js");
  });

  CROW_ROUTE(aabrham, "/signup/api/<string>/<string>")
      ([&](const crow::request &request, const std::string &username, const std::string &password) {
        auto &session = aabrham.get_context<crow::SessionMiddleware<crow::InMemoryStore >>(request);
        crow::json::wvalue response = signup::Signup(username, password);

        if (IsPositive(response))
          session::StartSession(session, username);

        return crow::response(std::move(response));
      });
}

bool IsPositive(crow::json::wvalue response) {
  return response["result"].dump() == "true"; //TODO Is there a more elegant way of doing this?
}
}