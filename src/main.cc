#include <iostream>
#include "crow.h"
#include "homepage_controller.h"
#include "login_controller.h"
#include "style_controller.h"

int main() {
  const static std::string kFrontendBaseDirectory = "view";

  crow::SimpleApp aabrham_backend;
  crow::mustache::set_global_base(kFrontendBaseDirectory);
  homepage::AddHomepageController(&aabrham_backend);
  login::AddLoginController(&aabrham_backend);
  style::AddStyleController(&aabrham_backend);

  aabrham_backend.port(18080).multithreaded().run();
}
