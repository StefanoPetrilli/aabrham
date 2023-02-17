//
// Created by Stefano on 2/16/2023.
//

#ifndef AABRHAM_SRC_INFRASTRUCTURE_CONFIGURATION_CONFIGURATION_H_
#define AABRHAM_SRC_INFRASTRUCTURE_CONFIGURATION_CONFIGURATION_H_
#include <string>
#include "file.h"

namespace configuration {
class Configuration {

 public:
  static Configuration *getInstance();
  std::string getRedisAddress();
  Configuration(Configuration const &) = delete;
  void operator=(Configuration const &) = delete;

 private:
  Configuration();
  static Configuration *instance;
  std::string redis_address_;

};
}
#endif //AABRHAM_SRC_INFRASTRUCTURE_CONFIGURATION_CONFIGURATION_H_
