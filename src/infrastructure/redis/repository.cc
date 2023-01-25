//
// Created by Stefano on 1/25/2023.
//

#include "repository.h"

namespace redis {
redis::Connection::Connection() {
  stream = rediscpp::make_stream("localhost", "6379");
}

int Connection::HashSet(const std::string& key, const std::string& field, const std::string& value) {
  auto response = rediscpp::execute(*stream, "hset",
                                    key, field, value);
  return (int) response.as_integer();
}
std::string Connection::HashGet(const std::string& key, const std::string& field) {
  auto response = rediscpp::execute(*stream, "hget",
                                    key, field);
  return response.as<std::string>();
}
}
