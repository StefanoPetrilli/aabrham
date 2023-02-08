//
// Created by Stefano on 1/24/2023.
//

#include "index_controller.h"

namespace indexx { //It is not possible to use index as there is a namespace conflict in the crows library
void AddIndexController(crow::App<crow::CookieParser, crow::SessionMiddleware<crow::InMemoryStore>> *app) {
  auto &aabrham = *app;

  CROW_ROUTE(aabrham, "/")
  ([&](const crow::request &request) {
    auto &session = aabrham.get_context<crow::SessionMiddleware<crow::InMemoryStore>>(request);
    crow::response response;
    crow::mustache::context ctx;

    if (session::IsLogged(session))
      response.redirect("/homepage");
    else
      response.body = crow::mustache::load_text("index/indexTemplate.html");

    return response;
  });

  CROW_ROUTE(aabrham, "/indexDirective.js")([]() {
    crow::mustache::context ctx;
    return crow::mustache::load_text("index/indexDirective.js");
  });
}
}