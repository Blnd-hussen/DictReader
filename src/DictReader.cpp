#include "../include/DictReader.hpp"
#include <fstream>
#include <regex>

DictReader::DictReader(const std::string filePath, const char delimiter) {
  // check if a CSV file path is provided
  std::regex re("^.+\\.csv$");
  if (!std::regex_match(filePath, re))
    throw std::invalid_argument(
        "Invalid file path provided. provide a valid path to a CSV file.");

  // open the file for reading and check if it exists
  std::ifstream file(filePath);
  if (!file.is_open())
    throw std::runtime_error("Failed to open CSV file. ensure the file exists "
                             "and you have appropriate permissions.");

  numbLines = 0;
  std::string line{};
  while (std::getline(file, line)) {
    if (numbLines == 0) {
      fieldNames = split(line, delimiter);
    } else {
      auto rowData = split(line, delimiter);
      std::map<std::string, std::string> row;
      for (size_t i = 0; i < fieldNames.size(); ++i) {
        row[fieldNames[i]] = rowData[i];
      }
      rows.push_back(row);
    }
    numbLines++;
  }
  file.close();
};

std::vector<std::string> DictReader::split(const std::string str,
                                           const char delimiter) {
  std::vector<std::string> tokens;
  std::string token{};

  for (int i = 0; str[i] != '\0'; ++i) {
    if (str[i] == delimiter || str[i + 1] == '\0') {
      if (str[i + 1] == '\0')
        token += str[i];

      tokens.push_back(token);
      token = "";
    } else {
      token += str[i];
    }
  }

  return tokens;
}

std::vector<std::string> DictReader::getFieldNames() { return fieldNames; }

std::vector<std::map<std::string, std::string>> DictReader::getRows() {
  return rows;
}

size_t DictReader::getNumbLines() { return numbLines; }
