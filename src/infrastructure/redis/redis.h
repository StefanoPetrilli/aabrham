//
// Created by Stefano on 1/25/2023.
//

#ifndef AABRHAM_INFRASTRUCTURE_REDIS_REPOSITORY_H_
#define AABRHAM_INFRASTRUCTURE_REDIS_REPOSITORY_H_
#include <sw/redis++/redis.h>
#include <optional>

namespace redis_connection {
class RedisConnection {
 public:
  RedisConnection();
  bool HashSet(const std::string &key, const std::string &field, const std::string &value);
  std::optional<std::string> HashGet(const std::string &key, const std::string &field);
  bool IsConnected();
  bool KeyDelete(const std::string &key);
  bool Exist(const std::string &key);
 protected:
  sw::redis::Redis connection = sw::redis::Redis("tcp://172.17.0.2:6379");
};
}
#endif //AABRHAM_INFRASTRUCTURE_REDIS_REPOSITORY_H_
