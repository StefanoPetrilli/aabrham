//
// Created by Stefano on 2/16/2023.
//

#include "configuration.h"

namespace configuration {
Configuration *Configuration::instance = nullptr;

Configuration::Configuration() {
  auto configuration_file_content = file::ReadConfigurationFileLines();
  redis_address_ = configuration_file_content.at("redis_address");
}

std::string Configuration::getRedisAddress() {
  return redis_address_;
}

Configuration *Configuration::getInstance() {
  if (instance == nullptr)
    instance = new Configuration();
  return instance;
}
}