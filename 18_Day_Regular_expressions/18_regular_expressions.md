<div align="center">
  <h1>🚀 30 Days Of C++: Day 18 - Regular Expressions</h1>
  <sub>std::regex, regex_match, regex_search, smatch, and regex_replace</sub>
</div>

[<< Day 17: Exception Handling](../17_Day_Exception_handling/17_exception_handling.md) | [Day 19: File Handling >>](../19_Day_File_handling/19_file_handling.md)

---

## Table of Contents
- [The `<regex>` Library](#the-regex-library)
- [Raw String Literals: `R"(...)"`](#raw-string-literals-r)
- [Exact Matching: `std::regex_match`](#exact-matching-stdregex_match)
- [Searching Within Text: `std::regex_search`](#searching-within-text-stdregex_search)
- [Capturing Groups: `std::smatch`](#capturing-groups-stdsmatch)
- [Iterating All Matches: `std::sregex_iterator`](#iterating-all-matches-stdsregex_iterator)
- [Replacing Text: `std::regex_replace`](#replacing-text-stdregex_replace)
- [💻 Exercises - Day 18](#-exercises---day-18)

---

## Raw String Literals: `R"(...)"`
Regular expressions rely heavily on backslashes (`\d`, `\w`, `\s`). In standard C++ strings, backslashes must be escaped (`"\\d"`). Raw string literals eliminate double escaping:

```cpp
// Standard string:
std::regex r1("\\d{3}-\\d{4}");

// Raw string literal (PREFERRED):
std::regex r2(R"(\d{3}-\d{4})");
```

---

## Exact Matching vs Substring Search
- `std::regex_match`: Returns `true` ONLY if the **entire** target string matches the pattern.
- `std::regex_search`: Returns `true` if the pattern matches anywhere **inside** the target text.

---

## Capturing Groups: `std::smatch`
`std::smatch` holds matched results:
- `match[0]`: Entire matching substring.
- `match[1]..match[n]`: Captured sub-groups matching parentheses `(...)`.

---

## Replacing Text: `std::regex_replace`
```cpp
std::string text = "Contact us at info@example.com or support@example.com";
std::regex email_regex(R"([\w.-]+@[\w.-]+)");
std::string masked = std::regex_replace(text, email_regex, "[REDACTED_EMAIL]");
```

---

## 💻 Exercises - Day 18

### Exercises: Level 1
1. Write a regex to validate whether a string is a valid US phone number in the format `(xxx) xxx-xxxx` or `xxx-xxx-xxxx`.
2. Check if a string is a valid hex color code (e.g. `#FFA500` or `#fff`).
3. Use `std::regex_replace` to remove all punctuation from a sentence.

### Exercises: Level 2
1. Email Parser: Write a program that extracts all valid email addresses from `data/email_exchanges.txt` using `std::sregex_iterator`.
2. URL Component Extractor: Using capturing groups, extract protocol (`http` or `https`), domain name, and port (optional) from a URL string.

### Exercises: Level 3
1. Implement a Markdown-to-HTML parser using `std::regex_replace`:
   - Convert `# Header` to `<h1>Header</h1>`
   - Convert `**bold**` to `<strong>bold</strong>`
   - Convert `*italic*` to `<em>italic</em>`
