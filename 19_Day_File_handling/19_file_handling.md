<div align="center">
  <h1>🚀 30 Days Of C++: Day 19 - File Streams & Filesystem</h1>
  <sub>std::fstream, line-by-line parsing, binary I/O, and C++17 std::filesystem</sub>
</div>

[<< Day 18: Regular Expressions](../18_Day_Regular_expressions/18_regular_expressions.md) | [Day 20: Build Systems & CMake >>](../20_Day_Build_systems_and_cmake/20_build_systems_and_cmake.md)

---

## Table of Contents
- [The Stream Hierarchy (`<fstream>`)](#the-stream-hierarchy-fstream)
- [Writing to Text Files (`std::ofstream`)](#writing-to-text-files-stdofstream)
- [Reading from Text Files (`std::ifstream`)](#reading-from-text-files-stdifstream)
- [File Open Modes & Flags](#file-open-modes--flags)
- [Binary File I/O](#binary-file-io)
- [The Modern C++17 Filesystem Library (`<filesystem>`)](#the-modern-c17-filesystem-library-filesystem)
- [💻 Exercises - Day 19](#-exercises---day-19)

---

## The Stream Hierarchy (`<fstream>`)
- `std::ifstream`: Input file stream (read-only).
- `std::ofstream`: Output file stream (write-only).
- `std::fstream`: Input & Output file stream (read & write).

Because streams follow RAII, they close their file handles automatically when destructed!

---

## Reading Line-by-Line
```cpp
#include <fstream>
#include <string>

std::ifstream file("sample.txt");
if (!file.is_open()) {
    std::cerr << "Failed to open file!\n";
    return;
}

std::string line;
while (std::getline(file, line)) {
    std::cout << line << "\n";
}
```

---

## C++17 `<filesystem>`
Provides platform-independent path manipulation, directory traversal, and disk queries:

```cpp
#include <filesystem>
namespace fs = std::filesystem;

fs::path p = "output/logs";
if (!fs::exists(p)) {
    fs::create_directories(p); // Creates all parent directories
}

for (const auto& entry : fs::directory_iterator(".")) {
    std::cout << entry.path().filename() << " (" << fs::file_size(entry) << " bytes)\n";
}
```

---

## 💻 Exercises - Day 19

### Exercises: Level 1
1. Write a program that creates a file `notes.txt` and writes 5 favorite motivational quotes into it using `std::ofstream`.
2. Write a program that reads `notes.txt` using `std::ifstream` and prints the line count, word count, and character count.
3. Use `std::filesystem::exists` to check if a file exists on disk and print its size in kilobytes.

### Exercises: Level 2
1. CSV Parser: Read the `files/csv_example.csv` file, parse each comma-separated line into fields, and print a formatted ASCII table.
2. File Appender: Write a program that prompts the user for log messages and appends each message to `app.log` along with a timestamp.

### Exercises: Level 3
1. Binary Serialization: Define a struct `struct GameSave { int level; double health; char name[32]; };`. Save it to a binary file `save.dat` using `.write()`, and load it back using `.read()`. Verify integrity.
2. Directory Tree Traversal: Write a utility using `std::filesystem::recursive_directory_iterator` that lists all files in a directory ending with `.cpp` or `.hpp` and prints their line counts.
