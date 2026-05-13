<div align="center">
  <h1>🚀 30 Days Of C++: Day 11 - Functions & Parameter Passing</h1>
  <sub>Prototypes, pass-by-value/ref/const-ref, overloading, and constexpr</sub>
</div>

[<< Day 10: Loops](../10_Day_Loops/10_loops.md) | [Day 12: Headers & Namespaces >>](../12_Day_Headers_and_namespaces/12_headers_and_namespaces.md)

---

## Table of Contents
- [Function Declaration vs Definition](#function-declaration-vs-definition)
- [Parameter Passing Semantics](#parameter-passing-semantics)
  - [Pass-by-Value](#pass-by-value)
  - [Pass-by-Reference (`T&`)](#pass-by-reference-t)
  - [Pass-by-Const-Reference (`const T&`)](#pass-by-const-reference-const-t)
- [Default Arguments](#default-arguments)
- [Function Overloading](#function-overloading)
- [Inline Functions & `constexpr` Functions](#inline-functions--constexpr-functions)
- [Recursion](#recursion)
- [💻 Exercises - Day 11](#-exercises---day-11)

---

## Function Declaration vs Definition
In C++, a function must be known before it is called:
- **Declaration (Prototype)**: Tells compiler the name, return type, and parameters.
- **Definition**: The actual implementation code.

```cpp
// Prototype
int add(int a, int b);

int main() {
    std::cout << add(3, 4);
}

// Definition
int add(int a, int b) {
    return a + b;
}
```

---

## Parameter Passing Semantics

| Style | Syntax | Use Case |
|---|---|---|
| **Pass by Value** | `void fn(int x)` | Primitives (`int`, `double`, `bool`) and small trivial types |
| **Pass by Reference** | `void fn(int& x)` | When the function needs to modify the caller's variable in-place |
| **Pass by Const Reference** | `void fn(const std::string& s)` | **GOLD STANDARD** for non-trivial objects (avoids expensive copying) |

---

## Function Overloading
Multiple functions can share the same name provided their parameter types or count differ:

```cpp
int multiply(int a, int b) { return a * b; }
double multiply(double a, double b) { return a * b; }
int multiply(int a, int b, int c) { return a * b * c; }
```

---

## `constexpr` Functions
Can be evaluated at compile time if arguments are known at compile time:
```cpp
constexpr int factorial(int n) {
    return (n <= 1) ? 1 : (n * factorial(n - 1));
}

constexpr int f5 = factorial(5); // Computed at compile-time! (120)
```

---

## 💻 Exercises - Day 11

### Exercises: Level 1
1. Write a function `square(double x)` that returns the square of a number.
2. Write a function `greet(const std::string& name, const std::string& greeting = "Hello")` with a default greeting argument.
3. Write a function `swap_values(int& a, int& b)` that swaps two integers using pass-by-reference.

### Exercises: Level 2
1. Function Overloading: Create overloaded functions `calculate_area` for:
   - Circle: `calculate_area(double radius)`
   - Rectangle: `calculate_area(double width, double height)`
   - Triangle: `calculate_area(double base, double height, bool is_triangle)`
2. Write a function `filter_evens(const std::vector<int>& input)` that returns a new vector containing only even numbers.

### Exercises: Level 3
1. Implement a `constexpr` power function `power(base, exponent)` and verify that its result can be used as the size of a `std::array<int, power(2, 4)>`.
2. Write a recursive function to solve the Towers of Hanoi puzzle for $N$ disks.
