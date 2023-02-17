//
// Created by Stefano on 2/17/2023.
//

#include "file.h"
//TODO this file could really use a refactoring
//TODO this file need tests

#include <unistd.h>
#define GetCurrentDir getcwd

namespace file {

static std::string GetConfigurationFileContent() {
  char buff[FILENAME_MAX]; //create string buffer to hold path
  GetCurrentDir( buff, FILENAME_MAX );

  std::ifstream file_stream(kDefaultConfigurationFilePath + kDefaultConfigurationFileName);
  std::string file_content;

  if (file_stream.is_open()) {
    getline(file_stream, file_content, '\x1A');
    file_stream.close();
  } else {
    throw std::invalid_argument("The path does not correspond to a file or the file cannot be accessed");
  }

  return file_content;
}

std::unordered_map<std::string, std::string> ReadConfigurationFileLines() {

  std::string file_content = GetConfigurationFileContent();

  std::unordered_map<std::string, std::string> result{};
  std::string line;

  size_t position_start = 0, position_end, delimiter_length = 1;
  while ((position_end = file_content.find(kNewLine, position_start)) != std::string::npos) {
    line = RemoveEscapeCharacter(file_content.substr(position_start, position_end - position_start));
    position_start = position_end + delimiter_length;

    result.insert({
                      line.substr(0, line.find(kDelimiter)),
                      line.substr(line.find(kDelimiter) + 1)
                  });

    line = "";
  }

  if (not line.empty())
    result.insert({
                      line.substr(0, line.find(kDelimiter)),
                      line.substr(line.find(kDelimiter) + 1)
                  });

  return result;
}

std::string RemoveEscapeCharacter(const std::string &line) {
  std::string result = line;
  while (result.starts_with('\n') || result.starts_with('\r')) result = result.substr(1);
  while (result.ends_with('\n') || result.ends_with('\r')) result = result.substr(0, result.length() - 1);
  return result;
}

}