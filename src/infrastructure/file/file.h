//
// Created by Stefano on 2/17/2023.
//

#ifndef AABRHAM_SRC_INFRASTRUCTURE_FILE_FILE_H_
#define AABRHAM_SRC_INFRASTRUCTURE_FILE_FILE_H_
#include <string>
#include <fstream>
#include <iostream>
#include <unordered_map>

namespace file {

const static char kNewLine = '\n';
const static std::string kPathSeparator =
#ifdef _WIN32
    "\\";
#else
    "/";
#endif
const std::string kDefaultConfigurationFilePath = ".."
    + kPathSeparator
    + "configuration"
    + kPathSeparator;
const std::string kDefaultConfigurationFileName = "local_configuration";
const std::string kDelimiter = "=";

std::unordered_map<std::string, std::string> ReadConfigurationFileLines();
}
#endif //AABRHAM_SRC_INFRASTRUCTURE_FILE_FILE_H_
