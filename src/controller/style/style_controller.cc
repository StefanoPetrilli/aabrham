//
// Created by Stefano on 1/24/2023.
//

#include "style_controller.h"

namespace style {
void AddStyleController(crow::App<crow::CookieParser, crow::SessionMiddleware<crow::InMemoryStore>> *app) {
  auto &aabrham = *app;

  CROW_ROUTE(aabrham, "/style.css")([]() {
    crow::mustache::context ctx;
    return crow::mustache::load_text("style/style.css");
  });

}
}