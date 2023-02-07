//
// Created by Stefano on 1/22/2023.
//

#include "homepage_controller.h"

namespace homepage {
void AddHomepageController(crow::App<crow::CookieParser, crow::SessionMiddleware<crow::InMemoryStore>> *app) {
  auto &aabrham = *app;

  CROW_ROUTE(aabrham, "/homepage")([]() {
    crow::mustache::context ctx;
    return crow::mustache::load_text("homepage/homepageTemplate.html");
  });

  CROW_ROUTE(aabrham, "/homepageDirective.js")([]() {
    crow::mustache::context ctx;
    return crow::mustache::load_text("homepage/homepageDirective.js");
  });

}
}
