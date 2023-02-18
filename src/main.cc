#include <iostream>
#include <crow.h>
#include "homepage_controller.h"
#include "login_controller.h"
#include "style_controller.h"
#include "index_controller.h"
#include "signup_controller.h"
#include "item_controller.h"
#include "assets_controller.h"
#include "crow/middlewares/session.h"

int main() {
  const static std::string kFrontendBaseDirectory = "view";

  crow::App<crow::CookieParser, crow::SessionMiddleware<crow::InMemoryStore>> aabrham_backend{
      crow::SessionMiddleware<crow::InMemoryStore>{
          crow::CookieParser::Cookie("session").max_age(/*one day*/ 24 * 60 * 60).path("/"),
          4,
          crow::InMemoryStore{}}};

  crow::mustache::set_global_base(kFrontendBaseDirectory);
  homepage::AddHomepageController(&aabrham_backend);
  login::AddLoginController(&aabrham_backend);
  style::AddStyleController(&aabrham_backend);
  indexx::AddIndexController(&aabrham_backend);
  signup::AddSignupController(&aabrham_backend);
  item::AddItemController(&aabrham_backend);
  assets::AddAssetsController(&aabrham_backend);

  aabrham_backend.port(18080).multithreaded().run();
}
