//
// Created by Stefano on 1/25/2023.
//

#ifndef AABRHAM_INFRASTRUCTURE_REDIS_REPOSITORY_H_
#define AABRHAM_INFRASTRUCTURE_REDIS_REPOSITORY_H_
#include <sw/redis++/redis.h>

namespace redis {
class Connection {
 public:
  Connection();
  void HashSet(const std::string& key, const std::string& field, const std::string& value);
  //std::string HashGet(const std::string& key, const std::string& field);
 private:
  sw::redis::Redis redis = sw::redis::Redis("tcp://127.0.0.1:6379");
};
}
#endif //AABRHAM_INFRASTRUCTURE_REDIS_REPOSITORY_H_
