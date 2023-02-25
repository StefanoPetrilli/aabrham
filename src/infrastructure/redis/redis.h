//
// Created by Stefano on 1/25/2023.
//

#ifndef AABRHAM_INFRASTRUCTURE_REDIS_REPOSITORY_H_
#define AABRHAM_INFRASTRUCTURE_REDIS_REPOSITORY_H_
#include <sw/redis++/redis.h>
#include <optional>
#include "configuration.h"

namespace redis_connection {
class RedisConnection {
 public:
  static RedisConnection *getInstance();
  RedisConnection(RedisConnection const &) = delete;
  void operator=(RedisConnection const &) = delete;
  bool IsConnected();
  bool HashSet(const std::string &key, const std::string &field, const std::string &value);
  std::optional<std::string> HashGet(const std::string &key, const std::string &field);
  bool KeyDelete(const std::string &key);
  bool Exist(const std::string &key);
  bool Exist(const std::string &key, const std::string &field);
  std::optional<std::unordered_map<std::string, std::string>> HashGetAll(const std::string &key);

 private:
  RedisConnection();
  static RedisConnection *instance;
  sw::redis::Redis connection_;
};
}
#endif //AABRHAM_INFRASTRUCTURE_REDIS_REPOSITORY_H_
