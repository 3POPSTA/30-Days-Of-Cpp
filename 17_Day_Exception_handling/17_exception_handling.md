<div align="center">
  <h1>🚀 30 Days Of C++: Day 17 - Exception Handling</h1>
  <sub>try, catch, throw, custom exceptions, and exception safety guarantees</sub>
</div>

[<< Day 16: Chrono & Date Time](../16_Day_Chrono_and_datetime/16_chrono_and_datetime.md) | [Day 18: Regular Expressions >>](../18_Day_Regular_expressions/18_regular_expressions.md)

---

## Table of Contents
- [The Exception Mechanism: `try`, `catch`, `throw`](#the-exception-mechanism-try-catch-throw)
- [The Standard Exception Hierarchy (`<stdexcept>`)](#the-standard-exception-hierarchy-stdexcept)
- [Catching by Const Reference](#catching-by-const-reference)
- [Custom Exception Classes](#custom-exception-classes)
- [Catch-All Handler (`catch (...)`)](#catch-all-handler-catch-)
- [Re-throwing Exceptions](#re-throwing-exceptions)
- [Exception Guarantees & `noexcept`](#exception-guarantees--noexcept)
- [💻 Exercises - Day 17](#-exercises---day-17)

---

## The Exception Mechanism: `try`, `catch`, `throw`
Exceptions decouple error detection from error handling. When an anomaly is detected, an exception object is thrown:

```cpp
#include <stdexcept>

double calculate_vat(double price, double rate) {
    if (price < 0.0 || rate < 0.0) {
        throw std::invalid_argument("Price and rate cannot be negative");
    }
    return price * rate;
}
```

---

## The Standard Exception Hierarchy
All standard exceptions inherit from `std::exception`:
- `std::logic_error`: Bugs detectable before execution (e.g. `invalid_argument`, `out_of_range`).
- `std::runtime_error`: Errors detected only during runtime (e.g. `overflow_error`, `system_error`).

Always catch by const reference to avoid object slicing:
```cpp
catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << "\n";
}
```

---

## Custom Exception Classes
```cpp
#include <exception>
#include <string>

class DatabaseConnectionException : public std::runtime_error {
public:
    explicit DatabaseConnectionException(const std::string& msg)
        : std::runtime_error("[Database Error] " + msg) {}
};
```

---

## Exception Guarantees & `noexcept`
- **Basic Guarantee**: No resources leaked, program remains in valid state.
- **Strong Guarantee**: If an operation throws, state remains completely unmodified (transactional).
- **Nothrow Guarantee (`noexcept`)**: Operation never throws. Essential for move constructors and destructors!

---

## 💻 Exercises - Day 17

### Exercises: Level 1
1. Write a function `safe_sqrt(double x)` that throws `std::domain_error` if $x < 0$. Call it inside a `try-catch` block.
2. Given a string representing an integer, convert it using `std::stoi` and handle `std::invalid_argument` and `std::out_of_range` exceptions.

### Exercises: Level 2
1. Create a custom exception `InsufficientFundsException` that holds requested withdrawal amount and current account balance. Use it in a `BankAccount` withdrawal function.
2. Demonstrate exception re-throwing: Catch an exception, log an audit message, and re-throw with `throw;` to let an outer handler process it.

### Exercises: Level 3
1. Implement a resource-safe file loader class using RAII that opens a file in constructor and closes it in destructor. Demonstrate that when an exception is thrown mid-processing, the file destructor cleanly runs without resource leaks.
