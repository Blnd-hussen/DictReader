#pragma once

#include <iostream>
#include <vector>
#include <map>

class DictReader
{
private:
  size_t numbLines;
  std::vector<std::string> fieldNames;
  std::vector<std::map<std::string, std::string>> rows;

  std::vector<std::string> split(const std::string, const char = ' ');

public:
  DictReader(const std::string, const char = ',');
  size_t getNumbLines();
  std::vector<std::string> getFieldNames();
  std::vector<std::map<std::string, std::string>> getRows();
};