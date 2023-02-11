//
// Created by Stefano on 2/11/2023.
//

#include "assets_controller.h"

namespace assets {
void AddAssetsController(crow::App<crow::CookieParser, crow::SessionMiddleware<crow::InMemoryStore>> *app) {
  auto &aabrham = *app;

  CROW_ROUTE(aabrham, "/assets/logo/TT_50.png")([](crow::response &res) {
    res.set_static_file_info("view/assets/logo/TT_50.png");
    res.end();
  });
}
}