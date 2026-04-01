<div align="center">
  <h1>🚀 30 Days Of C++: Day 28 - Modern C++ Features (C++17/20/23)</h1>
  <sub>std::optional, std::variant, std::any, Attributes, and Concepts</sub>
</div>

[<< Day 27: Concurrency](../27_Day_Concurrency_and_multithreading/27_concurrency_and_multithreading.md) | [Day 29: Building a Project >>](../29_Day_Building_a_cpp_project/29_building_a_cpp_project.md)

---

## Table of Contents
- [Modern Vocabulary Types](#modern-vocabulary-types)
- [`std::optional<T>` (Safe Nullable Values)](#stdoptionalt)
- [`std::variant<Ts...>` (Type-Safe Unions)](#stdvariantts)
- [Pattern Matching with `std::visit`](#pattern-matching-with-stdvisit)
- [Standard Attributes (`[[nodiscard]]`, `[[maybe_unused]]`)](#standard-attributes)
- [C++20 Concepts and Constraints](#c20-concepts-and-constraints)
- [💻 Exercises - Day 28](#-exercises---day-28)

---

## `std::optional<T>` (C++17)
Represents a value that may or may not exist without using pointers or magic sentinel values (-1, null):

```cpp
#include <optional>

std::optional<int> parse_port(const std::string& str) {
    try {
        return std::stoi(str);
    } catch (...) {
        return std::nullopt; // No value present
    }
}
```

---

## `std::variant<Ts...>` (C++17)
A type-safe union that holds one value out of a fixed set of alternative types:

```cpp
#include <variant>

using Response = std::variant<std::string, int, double>;
Response resp = "Success";
```

Use `std::visit` to process the active alternative:
```cpp
std::visit([](const auto& arg) {
    std::cout << "Received: " << arg << "\n";
}, resp);
```

---

## Standard Attributes
- `[[nodiscard]]`: Compiler warns if caller ignores the return value.
- `[[maybe_unused]]`: Suppresses warnings about unused variables.
- `[[fallthrough]]`: Documents intentional switch-case fallthrough.
- `[[deprecated("reason")]]`: Warns when outdated functions are called.

---

## 💻 Exercises - Day 28

### Exercises: Level 1
1. Write a function `std::optional<std::string> find_user_by_id(int id)` that returns the user's name if found, or `std::nullopt`. Use `.value_or("Guest")` at call site.
2. Declare a function marked `[[nodiscard]] bool connect_server()`. Call it without storing its result and observe the compiler warning.

### Exercises: Level 2
1. Create a `std::variant<int, double, std::string>` representing a JSON primitive value. Write a visitor with `std::visit` that prints the type name and value.
2. Define a C++20 concept `Printable` that requires a type to support `std::cout << val`.

### Exercises: Level 3
1. Implement an AST (Abstract Syntax Tree) expression evaluator using `std::variant` and `std::visit` representing numbers, binary operations, and unary operations.
