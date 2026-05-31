<div align="center">
  <h1>🚀 30 Days Of C++: Day 4 - Strings & String Views</h1>
  <sub>std::string, std::string_view, stringstreams, and text manipulation</sub>
</div>

[<< Day 3: Operators](../03_Day_Operators/03_operators.md) | [Day 5: Arrays & Vectors >>](../05_Day_Arrays_and_vectors/05_arrays_and_vectors.md)

---

## Table of Contents
- [C-Strings vs `std::string`](#c-strings-vs-stdstring)
- [String Construction and Concatenation](#string-construction-and-concatenation)
- [Essential `std::string` Methods](#essential-stdstring-methods)
- [Modern Zero-Copy: `std::string_view` (C++17)](#modern-zero-copy-stdstring_view-c17)
- [Character Manipulation (`<cctype>`)](#character-manipulation-cctype)
- [String Streams (`<sstream>`)](#string-streams-sstream)
- [String and Number Conversions](#string-and-number-conversions)
- [💻 Exercises - Day 4](#-exercises---day-4)

---

## C-Strings vs `std::string`
In legacy C, strings are represented as null-terminated character arrays (`char str[] = "hello\0";`), which are notorious for buffer overflows.
Modern C++ provides `std::string` (`#include <string>`), a dynamically-sized, memory-safe container managing its own memory allocation.

---

## String Construction and Concatenation
```cpp
#include <string>

std::string s1 = "Hello";
std::string s2 = "World";
std::string greeting = s1 + ", " + s2 + "!"; // Concatenation with +
greeting += " Welcome to C++.";              // Append with +=
```

---

## Essential `std::string` Methods
- `.length()` / `.size()`: Returns number of characters.
- `.empty()`: Returns `true` if string length is 0.
- `.clear()`: Empties the string.
- `operator[](size_t index)`: Fast direct character access (no bounds check).
- `.at(size_t index)`: Bounds-checked character access (throws `std::out_of_range`).
- `.substr(pos, count)`: Extracts a substring.
- `.find("substring")`: Returns index of first match, or `std::string::npos` if not found.
- `.replace(pos, count, "new_text")`: Replaces part of string.
- `.insert(pos, "inserted_text")`: Inserts text at specified position.

---

## Modern Zero-Copy: `std::string_view` (C++17)
`std::string_view` (`#include <string_view>`) represents a non-owning read-only reference to an existing character buffer. It avoids costly heap allocations when passing strings to functions!

```cpp
#include <string_view>

void print_message(std::string_view sv) { // No string copying occurs!
    std::cout << "Message: " << sv << " (Length: " << sv.length() << ")\n";
}
```

---

## Character Manipulation (`<cctype>`)
- `std::isalpha(c)`: Checks if alphabetic.
- `std::isdigit(c)`: Checks if numeric digit.
- `std::isspace(c)`: Checks if whitespace.
- `std::toupper(c)`, `std::tolower(c)`: Converts case.

---

## String Streams (`<sstream>`)
`std::stringstream` acts like an in-memory I/O stream, ideal for formatting, tokenizing words, and parsing CSV lines:

```cpp
#include <sstream>

std::string data = "John 25 84.5";
std::stringstream ss(data);

std::string name;
int age;
double weight;
ss >> name >> age >> weight; // Clean extraction
```

---

## 💻 Exercises - Day 4

### Exercises: Level 1
1. Declare a string `"30 Days Of Modern C++"`. Print its length, the first character, the last character, and check if it contains the word `"Modern"`.
2. Write a program that takes a sentence from the user using `std::getline` and converts all characters to uppercase.
3. Concatenate the strings `"C++ is "`, `"fast, "`, `"robust, "`, and `"fun!"` into a single string.

### Exercises: Level 2
1. Palindrome Checker: Write a function that accepts a string and checks if it reads the same backward and forward (ignoring case and whitespace).
2. Word Counter: Using `std::stringstream`, count the total number of words in an input sentence.
3. Write a program that extracts the username and domain from an email address (e.g. from `alice@example.com`, extract `alice` and `example.com` using `.find()` and `.substr()`).

### Exercises: Level 3
1. Implement a string trim function: `trim_left`, `trim_right`, and `trim` that removes leading and trailing whitespace using `std::string_view`.
2. Implement a simple Run-Length Encoding (RLE) compressor: Given `"AAAABBBCCDAA"`, output `"4A3B2C1D2A"`.
