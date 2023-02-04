//
// Created by Stefano on 1/25/2023.
//
#include "redis.h"

namespace redis_connection {
RedisConnection::RedisConnection() = default;

bool RedisConnection::HashSet(const std::string &key, const std::string &field, const std::string &value) {
  try {
    connection.hset(key, std::make_pair(field, value));
    return true;
  } catch (sw::redis::Error& e) {
    return false;
  }
}

std::optional<std::string> RedisConnection::HashGet(const std::string &key, const std::string &field) {
  return connection.hget(key, field);
}

bool RedisConnection::KeyDelete(const std::string &key) {
  return connection.del(key) == 1;
}

bool RedisConnection::IsConnected() {
  try {
    return connection.ping("") == "";
  } catch (sw::redis::Error& e) {
    return false;
  }
}
bool RedisConnection::Exist(const std::string &key) {
  try {
    return connection.exists(key) == 1;
  } catch (sw::redis::Error& e) {
    return false;
  }
}

}
