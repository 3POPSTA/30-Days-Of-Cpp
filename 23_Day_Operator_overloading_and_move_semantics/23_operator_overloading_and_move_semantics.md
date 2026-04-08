<div align="center">
  <h1>🚀 30 Days Of C++: Day 23 - Operator Overloading & Move Semantics</h1>
  <sub>Operators, lvalues vs rvalues, std::move, and the Rule of 0/3/5</sub>
</div>

[<< Day 22: Inheritance & Polymorphism](../22_Day_Inheritance_and_polymorphism/22_inheritance_and_polymorphism.md) | [Day 24: Templates >>](../24_Day_Templates_and_generic_programming/24_templates_and_generic_programming.md)

---

## Table of Contents
- [Operator Overloading Syntax](#operator-overloading-syntax)
- [Overloading Stream Operators (`<<` and `>>`)](#overloading-stream-operators--and-)
- [Value Categories: Lvalues vs Rvalues](#value-categories-lvalues-vs-rvalues)
- [Move Semantics & `std::move`](#move-semantics--stdmove)
- [The Rule of Three, Five, and Zero](#the-rule-of-three-five-and-zero)
- [💻 Exercises - Day 23](#-exercises---day-23)

---

## Overloading Stream Operators
To print your class with `std::cout << obj;`:

```cpp
class Vector2D {
public:
    double x, y;
    Vector2D(double x, double y) : x(x), y(y) {}

    // Overload +
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    // Overload << (friend function)
    friend std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
        return os << "(" << v.x << ", " << v.y << ")";
    }
};
```

---

## Move Semantics: Stealing Resources
Copying large heap allocations is slow. Move semantics allow transferring ownership of resources from an expiring temporary object (rvalue) without deep copying:

```cpp
// Move constructor
Buffer(Buffer&& other) noexcept
    : data(other.data), size(other.size) {
    other.data = nullptr; // Leave other in valid empty state!
    other.size = 0;
}
```

---

## The Rule of 0 / 3 / 5
- **Rule of Zero (Modern Best Practice)**: Use RAII types (`std::string`, `std::vector`), and write NO custom destructors/copy/move constructors!
- **Rule of Three**: If you define Destructor, Copy Constructor, or Copy Assignment, define all 3.
- **Rule of Five**: Add Move Constructor and Move Assignment.

---

## 💻 Exercises - Day 23

### Exercises: Level 1
1. Implement a `ComplexNumber` class with `real` and `imag` parts. Overload `+`, `-`, and `<<` operators.
2. Overload the equality operator `==` for a `Point3D` struct.

### Exercises: Level 2
1. Create a `DynamicArray` class managing a heap `int*`. Implement the full Rule of Five (Destructor, Copy Constructor, Copy Assignment, Move Constructor, Move Assignment). Verify that moving transfers ownership without reallocating.

### Exercises: Level 3
1. Implement a `BigInt` or `Fraction` class with overloaded `+`, `-`, `*`, `/`, `<`, and `==` operators.
