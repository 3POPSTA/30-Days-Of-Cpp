<div align="center">
  <h1>🚀 30 Days Of C++: Day 26 - Lambdas & Functional Programming</h1>
  <sub>Closures, capture clauses, generic lambdas, and std::function</sub>
</div>

[<< Day 25: STL Algorithms](../25_Day_STL_algorithms/25_stl_algorithms.md) | [Day 27: Concurrency >>](../27_Day_Concurrency_and_multithreading/27_concurrency_and_multithreading.md)

---

## Table of Contents
- [Lambda Expression Syntax](#lambda-expression-syntax)
- [Capture Clauses: Value vs Reference vs Init-Capture](#capture-clauses)
- [Generic Lambdas (`auto` parameters)](#generic-lambdas)
- [Mutable Lambdas](#mutable-lambdas)
- [Storing Callables: `std::function`](#storing-callables-stdfunction)
- [Higher-Order Functions & Currying](#higher-order-functions)
- [💻 Exercises - Day 26](#-exercises---day-26)

---

## Lambda Expression Syntax
```
[capture_clause](parameters) mutable -> return_type { body }
```

- `[]`: Captures nothing from the enclosing scope.
- `[=]`: Captures all used local variables by **copy/value**.
- `[&]`: Captures all used local variables by **reference**.
- `[x, &y]`: Captures `x` by value, `y` by reference.
- `[p = std::move(ptr)]`: C++14 move/init capture.

---

## Storing Callables: `std::function`
Defined in `<functional>`, `std::function<R(Args...)>` is a polymorphic function wrapper that can store lambdas, function pointers, and functors:

```cpp
#include <functional>

std::function<int(int, int)> operation = [](int a, int b) { return a + b; };
std::cout << operation(5, 7); // 12
```

---

## 💻 Exercises - Day 26

### Exercises: Level 1
1. Write a lambda that accepts two strings and returns the longer of the two.
2. Use a lambda inside `std::sort` to sort strings by length rather than alphabetical order.
3. Demonstrate a mutable lambda that maintains an internal counter every time it is invoked.

### Exercises: Level 2
1. Create a filter function `std::vector<int> filter(const std::vector<int>& data, std::function<bool(int)> predicate)` that returns elements satisfying the predicate lambda.
2. Write a higher-order function `make_multiplier(int factor)` that returns a lambda capable of multiplying any input by `factor`.

### Exercises: Level 3
1. Implement a callback event dispatcher system: Create an `EventEmitter` class where listeners can subscribe to events by name using `std::function<void(const std::string&)>`.
