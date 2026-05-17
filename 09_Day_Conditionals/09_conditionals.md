<div align="center">
  <h1>🚀 30 Days Of C++: Day 9 - Conditionals & Flow Control</h1>
  <sub>if-else, init-statements (C++17), switch-case, and if constexpr</sub>
</div>

[<< Day 8: Maps & Dictionaries](../08_Day_Maps_and_dictionaries/08_maps_and_dictionaries.md) | [Day 10: Loops >>](../10_Day_Loops/10_loops.md)

---

## Table of Contents
- [The `if`, `else if`, `else` Statements](#the-if-else-if-else-statements)
- [C++17 `if` with Initializer](#c17-if-with-initializer)
- [The `switch-case` Statement & `[[fallthrough]]`](#the-switch-case-statement--fallthrough)
- [Scoped Enums (`enum class`) with Switch](#scoped-enums-enum-class-with-switch)
- [Compile-Time Branching: `if constexpr` (C++17)](#compile-time-branching-if-constexpr-c17)
- [Guard Clauses & Branching Best Practices](#guard-clauses--branching-best-practices)
- [💻 Exercises - Day 9](#-exercises---day-9)

---

## The `if`, `else if`, `else` Statements
```cpp
int score = 85;

if (score >= 90) {
    std::cout << "Grade: A\n";
} else if (score >= 80) {
    std::cout << "Grade: B\n";
} else if (score >= 70) {
    std::cout << "Grade: C\n";
} else {
    std::cout << "Grade: F\n";
}
```

---

## C++17 `if` with Initializer
In C++17, you can declare and initialize a variable directly inside the condition header. The variable's scope is strictly confined to the `if` and `else` blocks:

```cpp
// if (init; condition)
if (auto it = inventory.find("GPU"); it != inventory.end()) {
    std::cout << "Item found: " << it->second << "\n";
} else {
    std::cout << "GPU is out of stock.\n";
}
// 'it' does NOT leak into the surrounding scope!
```

---

## The `switch-case` Statement & `[[fallthrough]]`
`switch` inspects integral or enum values:
```cpp
int code = 2;
switch (code) {
    case 1:
        std::cout << "Initializing...\n";
        break;
    case 2:
        std::cout << "Running...\n";
        [[fallthrough]]; // Explicitly informs compiler fallthrough is intentional
    case 3:
        std::cout << "Monitoring...\n";
        break;
    default:
        std::cout << "Unknown state\n";
        break;
}
```

---

## Scoped Enums (`enum class`) with Switch
Prefer `enum class` over old C-style unscoped enums for type safety:

```cpp
enum class Status { Pending, Approved, Rejected };

Status s = Status::Approved;
switch (s) {
    case Status::Pending:  std::cout << "Pending review\n"; break;
    case Status::Approved: std::cout << "Approved!\n"; break;
    case Status::Rejected: std::cout << "Rejected.\n"; break;
}
```

---

## Compile-Time Branching: `if constexpr` (C++17)
Discards unused branches at compile-time:
```cpp
template <typename T>
void inspect_type(T val) {
    if constexpr (std::is_integral_v<T>) {
        std::cout << "Integer value: " << val << "\n";
    } else {
        std::cout << "Non-integer value\n";
    }
}
```

---

## 💻 Exercises - Day 9

### Exercises: Level 1
1. Write a program that checks whether a user-entered integer is positive, negative, or zero.
2. Given a person's age, check if they are eligible to drive (age >= 18) and print an appropriate message.
3. Write a program using `switch` that accepts a number from 1 to 7 and prints the corresponding day of the week.

### Exercises: Level 2
1. Write a program using C++17 `if` with initializer to check if an element exists in a `std::vector` using `std::find`.
2. Traffic Light Simulator: Create an `enum class TrafficLight { Red, Yellow, Green }`. Write a function that accepts a light status and prints the action (Stop, Prepare to stop, Go) using `switch`.
3. Leap Year & Days in Month: Given a month (1-12) and year, print how many days are in that month, taking leap years into account.

### Exercises: Level 3
1. Implement a basic CLI calculator: Prompt the user for two numbers and an operator (`+`, `-`, `*`, `/`, `%`). Use `switch` to perform the operation. Handle division by zero gracefully.
2. Write a function template using `if constexpr` that takes any value and prints whether `sizeof(T)` is greater than 4 bytes at compile time.
