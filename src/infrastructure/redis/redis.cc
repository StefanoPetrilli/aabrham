//
// Created by Stefano on 1/25/2023.
//
#include "redis.h"

namespace redis_connection {
RedisConnection *RedisConnection::instance = nullptr;

RedisConnection::RedisConnection() : connection_(configuration::Configuration::getInstance()->getRedisAddress()) {}

RedisConnection *RedisConnection::getInstance() {
  if (instance == nullptr)
    instance = new RedisConnection();
  return instance;
}

bool RedisConnection::HashSet(const std::string &key, const std::string &field, const std::string &value) {
  try {
    connection_.hset(key, std::make_pair(field, value));
    return true;
  } catch (sw::redis::Error& e) {
    return false;
  }
}

std::optional<std::string> RedisConnection::HashGet(const std::string &key, const std::string &field) {
  return connection_.hget(key, field);
}

bool RedisConnection::KeyDelete(const std::string &key) {
  return connection_.del(key) == 1;
}

bool RedisConnection::IsConnected() {
  try {
    return connection_.ping("").empty();
  } catch (sw::redis::Error& e) {
    return false;
  }
}

bool RedisConnection::Exist(const std::string &key) {
  try {
    return connection_.exists(key) == 1;
  } catch (sw::redis::Error& e) {
    return false;
  }
}

bool RedisConnection::Exist(const std::string &key, const std::string &field) {
  try {
    return connection_.hget(key, field).has_value();
  } catch (sw::redis::Error& e) {
    return false;
  }
}

std::optional<std::unordered_map<std::string, std::string>> RedisConnection::HashGetAll(const std::string &key) {
  std::unordered_map<std::string, std::string> output;

  try {
    connection_.hgetall(key, std::inserter(output, output.begin()));
  } catch (sw::redis::Error& e) {
    return output;
  }

  return output;
}
}
