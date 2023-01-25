//
// Created by Stefano on 1/25/2023.
//

#ifndef AABRHAM_INFRASTRUCTURE_REDIS_REPOSITORY_H_
#define AABRHAM_INFRASTRUCTURE_REDIS_REPOSITORY_H_
#include "redis-cpp/stream.h"
#include "redis-cpp/execute.h"

namespace redis {
class Connection {
 public:
  Connection();
  int HashSet(const std::string& key, const std::string& field, const std::string& value);
  std::string HashGet(const std::string& key, const std::string& field);
 private:
  std::shared_ptr<std::iostream> stream;
};
}
#endif //AABRHAM_INFRASTRUCTURE_REDIS_REPOSITORY_H_
