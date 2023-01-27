//
// Created by Stefano on 1/25/2023.
//
#include "repository.h"

namespace redis {

redis::Connection::Connection() {}

void Connection::HashSet(const std::string& key, const std::string& field, const std::string& value) {
  redis.hset(key, std::make_pair(field, value));
}
/*
std::string Connection::HashGet(const std::string& key, const std::string& field) {
  auto response = rediscpp::execute(*stream, "hget",
                                    key, field);
  return response.as<std::string>();
}
 */
}
