#pragma once

#include <filesystem>
#include <iostream>
#include <map>
#include <vector>

class DictReader {
private:
  size_t numbLines;
  std::vector<std::string> fieldNames;
  std::vector<std::map<std::string, std::string>> rows;

public:
  DictReader(const std::filesystem::path filePath, const char delimiter = ',');
  bool hasFieldNames();
  bool hasRows();
  size_t getNumbLines();
  std::vector<std::string> getFieldNames();
  std::vector<std::map<std::string, std::string>> getRows();
};

std::vector<std::string> split(const std::string str, const char delimiter);
