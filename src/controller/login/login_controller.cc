//
// Created by Stefano on 1/22/2023.
//

#include "login_controller.h"

namespace login {
void AddLoginController(crow::SimpleApp *app) {
  crow::SimpleApp &aabrham = *app;

  CROW_ROUTE(aabrham, "/login")([]() {
    crow::mustache::context ctx;
    return crow::mustache::load_text("login/loginTemplate.html");
  });

  CROW_ROUTE(aabrham, "/loginDirective.js")([]() {
    crow::mustache::context ctx;
    return crow::mustache::load_text("login/loginDirective.js");
  });

  CROW_ROUTE(aabrham, "/login/api/<string>/<string>")([](const std::string &username, const std::string &password) {
    crow::json::wvalue response = login::Login(username, password);
    return crow::response(std::move(response));
  });

}
}
