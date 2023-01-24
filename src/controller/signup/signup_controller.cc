//
// Created by Stefano on 1/24/2023.
//

#include "signup_controller.h"

namespace signup {
void AddSignupController(crow::SimpleApp* app) {
  crow::SimpleApp &aabrham = *app;

  CROW_ROUTE(aabrham, "/signup")([]() {
    crow::mustache::context ctx;
    return crow::mustache::load_text("signup/signupTemplate.html");
  });

  CROW_ROUTE(aabrham, "/signupDirective.js")([]() {
    crow::mustache::context ctx;
    return crow::mustache::load_text("signup/signupDirective.js");
  });
}
}