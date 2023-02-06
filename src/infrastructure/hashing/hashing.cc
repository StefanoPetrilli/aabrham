//
// Created by Stefano on 2/6/2023.
//

#include "hashing.h"

namespace hashing {
std::string ToHash(const std::string& input) {
  return std::to_string(std::hash<std::string>{}(input));
}
}