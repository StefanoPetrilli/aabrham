//
// Created by Stefano on 2/18/2023.
//

#include "item_controller.h"

namespace item {
void AddItemController(crow::App<crow::CookieParser, crow::SessionMiddleware<crow::InMemoryStore>> *app) {
  auto &aabrham = *app;

  CROW_ROUTE(aabrham, "/api/item/insert")
      .methods("POST"_method)
          ([&](const crow::request &request) {
            crow::mustache::context ctx;
            crow::response response;
            auto &session = aabrham.get_context<crow::SessionMiddleware<crow::InMemoryStore>>(request);
            auto serialized_request = crow::json::load(request.body);

            if (!session::IsLogged(session))
              response = crow::response(401, "To perform this action, first you should login.");
            else {
              response = item::InsertItem(serialized_request, session::GetUsername(session));
            }

            return response;
          });

  CROW_ROUTE(aabrham, "/api/item/get")
      ([&](const crow::request &request) {
        crow::mustache::context ctx;
        crow::response response;
        auto &session = aabrham.get_context<crow::SessionMiddleware<crow::InMemoryStore>>(request);

        if (!session::IsLogged(session))
          response = crow::response(401, "To perform this action, first you should login.");
        else {
          response = item::GetItems(session::GetUsername(session));
        }

        return response;
      });
}
}