<div align="center">
  <h1>🚀 30 Days Of C++: Day 3 - Operators</h1>
  <sub>Arithmetic, logic, bits, spaceship operator (<=>), and precedence</sub>
</div>

[<< Day 2: Variables & Data Types](../02_Day_Variables_and_data_types/02_variables_and_data_types.md) | [Day 4: Strings >>](../04_Day_Strings/04_strings.md)

---

## Table of Contents
- [Arithmetic Operators & Division Pitfalls](#arithmetic-operators--division-pitfalls)
- [Compound Assignment Operators](#compound-assignment-operators)
- [Increment and Decrement Operators](#increment-and-decrement-operators)
- [Relational and Comparison Operators](#relational-and-comparison-operators)
- [The C++20 Three-Way Comparison (Spaceship `<=>`)](#the-c20-three-way-comparison-spaceship-)
- [Logical Operators & Short-Circuiting](#logical-operators--short-circuiting)
- [Bitwise Operators & Bit Manipulation](#bitwise-operators--bit-manipulation)
- [Ternary Conditional Operator](#ternary-conditional-operator)
- [Operator Precedence](#operator-precedence)
- [💻 Exercises - Day 3](#-exercises---day-3)

---

## Arithmetic Operators & Division Pitfalls
C++ supports the standard mathematical operators:
- Addition: `+`
- Subtraction: `-`
- Multiplication: `*`
- Division: `/`
- Modulus (Remainder): `%` (integers only)

### Integer Division Trap
When dividing two integers, C++ performs integer division and truncates the decimal remainder:
```cpp
int a = 7;
int b = 2;
std::cout << a / b; // Prints 3 (NOT 3.5!)

// To get floating-point division, at least one operand must be a float or double:
std::cout << static_cast<double>(a) / b; // Prints 3.5
```

---

## Increment and Decrement Operators
- Prefix (`++x`, `--x`): Increments/decrements first, then returns the new value.
- Postfix (`x++`, `x--`): Returns the current value, then increments/decrements.

```cpp
int a = 5;
int b = ++a; // a becomes 6, b receives 6

int c = 5;
int d = c++; // d receives 5, c becomes 6
```
> [!TIP]
> In modern C++, prefer prefix increment (`++i`) for loop counters and iterators because it avoids making a temporary copy of the object!

---

## Relational and Comparison Operators
Evaluate expressions to `bool` (`true` or `false`):
- Equal to: `==`
- Not equal to: `!=`
- Greater than / Less than: `>`, `<`
- Greater than or equal / Less than or equal: `>=`, `<=`

---

## The C++20 Three-Way Comparison (Spaceship `<=>`)
C++20 introduced the `<=>` operator (defined in `<compare>`). It allows comparing two objects in a single operation:
```cpp
#include <compare>

auto result = (a <=> b);
if (result < 0)  std::cout << "a is less than b\n";
if (result == 0) std::cout << "a is equal to b\n";
if (result > 0)  std::cout << "a is greater than b\n";
```

---

## Logical Operators & Short-Circuiting
- Logical AND: `&&` (both operands must be true)
- Logical OR: `||` (at least one operand must be true)
- Logical NOT: `!` (inverts boolean value)

**Short-Circuit Evaluation:**
In `A && B`, if `A` is false, `B` is never evaluated.
In `A || B`, if `A` is true, `B` is never evaluated.

---

## Bitwise Operators & Bit Manipulation
Directly operate on individual bits of integer types:
- Bitwise AND: `&`
- Bitwise OR: `|`
- Bitwise XOR: `^`
- Bitwise NOT: `~`
- Left Shift: `<<` (multiplies by 2^n)
- Right Shift: `>>` (divides by 2^n)

Example:
```cpp
uint8_t flags = 0b00000101; // 5
flags = flags | 0b00000010; // Set bit 1 -> 0b00000111 (7)
```

---

## 💻 Exercises - Day 3

### Exercises: Level 1
1. Declare two integer variables `x = 24` and `y = 7`. Compute and print their sum, difference, product, quotient (floating point), and remainder (`%`).
2. Demonstrate prefix vs postfix operators: write a code snippet showing the difference in values returned when printing `++count` vs `count++`.
3. Check if a given year (e.g. 2024) is a leap year using logical operators (`(year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)`).

### Exercises: Level 2
1. Write a program to calculate the Body Mass Index (BMI):
   $$\text{BMI} = \frac{\text{weight in kg}}{(\text{height in m})^2}$$
   Use relational operators to print whether the user is underweight (<18.5), normal weight (18.5-24.9), overweight (25-29.9), or obese (>=30).
2. Use the ternary operator to find the maximum and minimum of three numbers entered by the user.

### Exercises: Level 3
1. Implement basic bit manipulation:
   - Check if a number is even or odd using the bitwise AND operator `& 1`.
   - Multiply and divide an integer by 4 using bit shifts `<<` and `>>`.
   - Swap two integer variables without a temporary variable using bitwise XOR (`^`).
2. Using `<compare>`, write a program demonstrating the three-way comparison operator `<=>` on two floating-point numbers.
