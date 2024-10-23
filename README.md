# DictReader

DictReader provides a simple and efficient way to read and process data from CSV (Comma-Separated Values) files in C++.

## Features

- Extracts field names from the first line of the CSV file.

- Parses each data row into a key-value map (std::map), where keys are field names and values are individual data elements.

- Supports custom field delimiters (e.g., ,, ;, |, etc.).

- Handles quoted fields that contain delimiters inside them.

- Converts CSV data into a JSON-like string format for easy inspection.

- Counts the total number of lines in the CSV file.

## Usage

1. Include the DictReader.h header file in your code.
2. Create a DictReader object, specifying the path to your CSV file and the delimiter character used to separate fields (default is comma ,).

### Example usage

```c++
#include "DictReader.hpp"

int main(int argc, char **argv) {
  try {
    DictReader reader("data.csv");

    // Access field names
    std::vector<std::string> fieldNames = reader.getFieldNames();

    // Access data rows as key-value maps
    std::vector<std::map<std::string, std::string>> rows = reader.getRows();

    // Get total number of lines
    size_t numLines = reader.getNumbLines();

    // Convert parsed data to JSON-like string format
    std::string jsonString = reader.toJsonString();
    std::cout << jsonString << std::endl;

    // Process data as needed
    // ...

  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
```

### Output Example

For a csv file like

```csv
Name,Age,Location
John Doe,29,"New York, USA"
Jane Smith,31,London
```

The JSON-like output would be

```json
[
  {
    "Name": "John Doe",
    "Age": "29",
    "Location": "New York, USA"
  },
  {
    "Name": "Jane Smith",
    "Age": "31",
    "Location": "London"
  }
]
```

## Error Handling

DictReader throws exceptions for the following cases:

- Invalid or missing file paths.
- Non-CSV file formats.
- Issues with file access (e.g., permissions).

Make sure to catch these exceptions using try-catch blocks in your code to handle errors gracefully.

## Dependencies

DictReader requires the following:

- C++17 or higher (for std::filesystem, std::regex, std::map, std::vector).
- Standard C++ library features such as std::ifstream for file reading.
