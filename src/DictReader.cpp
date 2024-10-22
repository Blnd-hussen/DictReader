#include "../include/DictReader.hpp"
#include <fstream>
#include <regex>

namespace fs = std::filesystem;

DictReader::DictReader(const fs::path filePath, const char delimiter) {

  // * make sure a csv path is provided
  if (filePath.empty() || filePath.extension() != ".csv") {
    throw std::invalid_argument(
        "Invalid file path provided. provide a valid path to a CSV file. " +
        filePath.generic_string());
  }

  // * check if the file exists and is a regular file
  if (!fs::exists(filePath) || !fs::is_regular_file(filePath)) {
    throw std::runtime_error(filePath.generic_string() +
                             " does not exist or is not regular file");
  }

  // * make sure that file has read permission
  std::ifstream file(filePath);
  if (!file.is_open()) {
    throw std::runtime_error(
        "Failed to open CSV file: " + filePath.generic_string() +
        "\nensure that you have appropriate permissions.");
  }

  numbLines = 0;
  std::string line{};
  while (std::getline(file, line)) {
    if (numbLines == 0) {
      fieldNames = split(line, delimiter);
    } else {
      auto rowData = split(line, delimiter);

      std::map<std::string, std::string> row;
      for (size_t i = 0; i < fieldNames.size(); ++i) {
        if (i >= rowData.size()) {
          row[fieldNames[i]] = "None";
        } else {
          row[fieldNames[i]] = rowData[i];
        }
      }
      rows.push_back(row);
    }
    numbLines++;
  }
};

auto DictReader::getFieldNames() -> std::vector<std::string> {
  return fieldNames;
}

auto DictReader::getRows() -> std::vector<std::map<std::string, std::string>> {
  return rows;
}

auto DictReader::getNumbLines() -> size_t { return numbLines; }

auto DictReader::hasFieldNames() -> bool { return fieldNames.size() > 0; }

auto DictReader::hasRows() -> bool { return rows.size() > 0; }

auto split(const std::string str, const char delimiter)
    -> std::vector<std::string> {

  std::vector<std::string> tokens;
  std::smatch matches;
  std::regex re("\"([^\"]*)\"|([^,]+)");
  
  std::string line = str;
  while (std::regex_search(line, matches, re)) {
    for (int i = 1; i < matches.size(); ++i) {
      if (matches[i].matched) {
        tokens.push_back(matches[i].str());
      }
    }
    line = matches.suffix().str();
  }

  return tokens;
}
