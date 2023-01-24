//
// Created by Stefano on 1/22/2023.
//

#include "homepage_controller.h"

namespace homepage {
void AddHomepageController(crow::SimpleApp *app) {
  crow::SimpleApp &aabrham = *app;

  CROW_ROUTE(aabrham, "/")([]() {
    crow::mustache::context ctx;
    return crow::mustache::load_text("homepage/homepageTemplate.html");
  });

  CROW_ROUTE(aabrham, "/homepageDirective.js")([]() {
    crow::mustache::context ctx;
    return crow::mustache::load_text("homepage/homepageDirective.js");
  });

}
}
