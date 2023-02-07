//
// Created by Stefano on 1/22/2023.
//

#include "homepage_controller.h"

namespace homepage {
void AddHomepageController(crow::App<crow::CookieParser, crow::SessionMiddleware<crow::InMemoryStore>> *app) {
  auto &aabrham = *app;

  CROW_ROUTE(aabrham, "/homepage")
      ([&](const crow::request &request) {
        //auto &session = aabrham.get_context<crow::SessionMiddleware<crow::InMemoryStore>>(request);
        //std::string string_v = session.get<std::string>("key");
        crow::response response;

        if (session::IsLogged(&aabrham, request)) {
          response.redirect("/");
          return response;
        }

        crow::mustache::context ctx;
        response.body = crow::mustache::load_text("homepage/homepageTemplate.html");
        return response;
      });

  CROW_ROUTE(aabrham, "/homepageDirective.js")([]() {
    crow::mustache::context ctx;
    return crow::mustache::load_text("homepage/homepageDirective.js");
  });

}
}
