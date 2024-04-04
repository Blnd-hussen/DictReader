# DictReader

DictReader provides a simple and efficient way to read and process data from CSV (Comma-Separated Values) files in C++.

## Features

- Extracts field names from the first line of the CSV file.
- Parses each data row into a key-value map, where keys are field names and values are individual data elements.
- Counts the total number of lines in the CSV file.

## Usage

1. Include the DictReader.h header file in your code.
2. Create a DictReader object, specifying the path to your CSV file and the delimiter character used to separate fields (default is comma ,).

### Example usage

```c++
#include "DictReader.h"

int main(int argc, char **argv) {
  try {
    DictReader reader("data.csv");

    // Access field names
    std::vector<std::string> fieldNames = reader.getFieldNames();

    // Access data rows as key-value maps
    std::vector<std::map<std::string, std::string>> rows = reader.getRows();

    // Get total number of lines
    size_t numLines = reader.getNumbLines();

    // Process data as needed
    // ...

  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
```

## Error Handling

DictReader throws exceptions for invalid file paths and file access errors. Make sure to catch these exceptions using try-catch blocks in your code.

## Dependencies

This library requires a C++ compiler with support for C++11 features (e.g., regular expressions, std::map, std::vector).
