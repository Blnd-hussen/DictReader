#pragma once

#include <iostream>
#include <map>
#include <optional>
#include <vector>

class DictReader {
private:
  size_t numbLines;
  std::vector<std::string> fieldNames;
  std::vector<std::map<std::string, std::string>> rows;

public:
  DictReader(const std::string, const char = ',');
  std::optional<size_t> getNumbLines();
  std::optional<std::vector<std::string>> getFieldNames();
  std::optional<std::vector<std::map<std::string, std::string>>> getRows();
};