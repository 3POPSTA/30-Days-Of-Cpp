<div align="center">
  <h1>🚀 30 Days Of C++: Day 2 - Variables & Built-in Data Types</h1>
  <sub>Static typing, memory layouts, limits, and standard I/O</sub>
</div>

[<< Day 1: Introduction](../01_Day_Introduction/01_introduction.md) | [Day 3: Operators >>](../03_Day_Operators/03_operators.md)

---

## Table of Contents
- [C++ Type System Overview](#c-type-system-overview)
- [Fundamental Data Types & Size](#fundamental-data-types--size)
- [Fixed-Width Integers (`<cstdint>`)](#fixed-width-integers-cstdint)
- [Variable Initialization Styles](#variable-initialization-styles)
- [Type Modifiers: const and constexpr](#type-modifiers-const-and-constexpr)
- [Automatic Type Deduction (`auto`)](#automatic-type-deduction-auto)
- [Type Casting (`static_cast`)](#type-casting-static_cast)
- [Standard Input with `std::cin`](#standard-input-with-stdcin)
- [💻 Exercises - Day 2](#-exercises---day-2)

---

## C++ Type System Overview
C++ is a **statically typed** and **strongly typed** language. Every variable, expression, and object has a known type determined at compile time. Static typing enables the compiler to optimize memory layout, verify type safety, and catch errors before execution.

---

## Fundamental Data Types & Size

| Type | Typical Size | Description | Value Range (typical) |
|---|---|---|---|
| `bool` | 1 byte | Boolean value | `true` (1) or `false` (0) |
| `char` | 1 byte | Single ASCII character | -128 to 127 |
| `short` | 2 bytes | Short integer | -32,768 to 32,767 |
| `int` | 4 bytes | Standard integer | -2,147,483,648 to 2,147,483,647 |
| `long long` | 8 bytes | Extended integer | approx ±9.22 × 10^18 |
| `float` | 4 bytes | Single-precision floating point | ~7 decimal digits precision |
| `double` | 8 bytes | Double-precision floating point | ~15-17 decimal digits precision |
| `size_t` | 4 or 8 bytes | Unsigned size type (architecture native) | 0 to max addressable bytes |

You can query the size of any type using the `sizeof` operator:
```cpp
std::cout << "Size of int: " << sizeof(int) << " bytes\n";
```

---

## Fixed-Width Integers (`<cstdint>`)
Because sizes of `int` and `long` can vary between operating systems (e.g. 32-bit Windows vs 64-bit Linux), systems programming standardizes on fixed-width types:
- `int8_t`, `uint8_t` (8-bit signed/unsigned)
- `int16_t`, `uint16_t` (16-bit signed/unsigned)
- `int32_t`, `uint32_t` (32-bit signed/unsigned)
- `int64_t`, `uint64_t` (64-bit signed/unsigned)

---

## Variable Initialization Styles
C++ offers three main ways to initialize variables:

```cpp
// 1. C-style assignment initialization
int a = 10;

// 2. Direct constructor initialization
int b(20);

// 3. Uniform / Brace initialization (C++11, RECOMMENDED)
int c{30};

// Why brace initialization is preferred: prevents narrowing conversion!
// double pi = 3.14159;
// int x{pi}; // COMPILE ERROR: narrowing conversion from double to int!
```

---

## Type Modifiers: const and constexpr
- `const`: Promises that the variable will not be mutated after initialization. Checked at compile time, but value can be determined at runtime.
- `constexpr`: Evaluated strictly at **compile time**. Ideal for constants and performance-critical tables.

```cpp
const int runtime_max = calculate_limit(); // OK: determined at runtime
constexpr double PI = 3.141592653589793;   // Guaranteed compile-time constant
```

---

## Automatic Type Deduction (`auto`)
Introduced in C++11, `auto` tells the compiler to infer the variable's type from its initializer:

```cpp
auto age = 25;           // int
auto price = 19.99;      // double
auto letter = 'A';       // char
auto is_active = true;   // bool
```

---

## Type Casting (`static_cast`)
Avoid error-prone C-style casts like `(int)x`. In modern C++, use `static_cast<Type>(variable)`:

```cpp
double total_price = 49.95;
int whole_dollars = static_cast<int>(total_price); // Explicit and safe
```

---

## Standard Input with `std::cin`
Reading inputs from terminal:

```cpp
int age;
std::cout << "Enter your age: ";
std::cin >> age;

// Reading strings with spaces:
std::string full_name;
std::cout << "Enter your full name: ";
std::cin.ignore(); // Flush leftover newline
std::getline(std::cin, full_name);
```

---

## 💻 Exercises - Day 2

### Exercises: Level 1
1. Declare variables of types: `int`, `double`, `char`, `bool`, and `std::string`. Print their values and their memory sizes using `sizeof`.
2. Write a program that computes the area and perimeter of a rectangle where `length = 15.5` and `width = 8.2`. Use `constexpr` or `const`.
3. Print the minimum and maximum values of `int`, `unsigned int`, `double`, and `long long` using `<limits>` (`std::numeric_limits<T>::min()` and `max()`).

### Exercises: Level 2
1. Write a program that asks the user for their first name, last name, age, and height in meters. Print a formatted summary.
2. Demonstrate how brace initialization `{}` prevents narrowing conversion by writing code that causes a compiler error and fixing it with `static_cast`.
3. Create a temperature converter program: Prompt the user for a temperature in Celsius (double) and convert it to Fahrenheit using the formula `(Celsius * 9.0 / 5.0) + 32.0`.

### Exercises: Level 3
1. Implement a program that prompts the user for two integers, casts them to `double`, and calculates both their integer division result and floating-point division result.
2. Explore `<cstdint>`: Create variables of `uint8_t`, `uint16_t`, `uint32_t`, and `uint64_t`. Print their sizes and demonstrate integer overflow by adding 1 to the maximum value of `uint8_t` (255).
