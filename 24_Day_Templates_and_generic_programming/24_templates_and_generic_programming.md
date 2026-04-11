<div align="center">
  <h1>🚀 30 Days Of C++: Day 24 - Templates & Generic Programming</h1>
  <sub>Function & class templates, fold expressions, type traits, and concepts</sub>
</div>

[<< Day 23: Operator Overloading](../23_Day_Operator_overloading_and_move_semantics/23_operator_overloading_and_move_semantics.md) | [Day 25: STL Algorithms >>](../25_Day_STL_algorithms/25_stl_algorithms.md)

---

## Table of Contents
- [What are Templates?](#what-are-templates)
- [Function Templates](#function-templates)
- [Class Templates](#class-templates)
- [Non-Type Template Parameters (NTTP)](#non-type-template-parameters-nttp)
- [Template Specialization](#template-specialization)
- [Variadic Templates & Fold Expressions (C++17)](#variadic-templates--fold-expressions-c17)
- [Introduction to C++20 Concepts](#introduction-to-c20-concepts)
- [💻 Exercises - Day 24](#-exercises---day-24)

---

## Function Templates
Templates instruct the compiler to generate type-specific functions on demand:

```cpp
template <typename T>
T find_max(T a, T b) {
    return (a > b) ? a : b;
}

// Invocation
int m1 = find_max(10, 20);       // Compiler generates find_max<int>
double m2 = find_max(4.5, 2.1);   // Compiler generates find_max<double>
```

---

## Fold Expressions (C++17)
Enables compact variadic template expansions:

```cpp
template <typename... Args>
auto sum_all(Args... args) {
    return (... + args); // Unary left fold!
}
```

---

## Introduction to C++20 Concepts
Concepts constrain template types with clear compiler error diagnostics:

```cpp
#include <concepts>

template <std::integral T>
T gcd(T a, T b) {
    while (b != 0) {
        T temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
```

---

## 💻 Exercises - Day 24

### Exercises: Level 1
1. Write a function template `swap_elements<T>(T& a, T& b)` and test it with `int`, `double`, and `std::string`.
2. Write a function template `print_vector<T>(const std::vector<T>& vec)` that prints any vector.
3. Write a class template `Pair<T1, T2>` mimicking `std::pair`.

### Exercises: Level 2
1. Stack Data Structure: Implement a generic `Stack<T>` class template with `push()`, `pop()`, `top()`, and `empty()`.
2. Write a variadic fold expression function `all_true(bool... args)` that returns `true` only if all boolean arguments are true.

### Exercises: Level 3
1. Implement a Fixed-Capacity Ring Buffer using a class template with a Non-Type Template Parameter `template <typename T, size_t Capacity> class CircularBuffer`.
2. Define a C++20 custom concept `Numeric` that accepts only types satisfying `std::integral` or `std::floating_point`. Use it to constrain a generic statistical average function.
