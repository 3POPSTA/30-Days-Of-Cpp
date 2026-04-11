<div align="center">
  <h1>🚀 30 Days Of C++: Day 21 - Classes & Objects</h1>
  <sub>Encapsulation, constructors, member initializer lists, and RAII</sub>
</div>

[<< Day 20: Build Systems & CMake](../20_Day_Build_systems_and_cmake/20_build_systems_and_cmake.md) | [Day 22: Inheritance & Polymorphism >>](../22_Day_Inheritance_and_polymorphism/22_inheritance_and_polymorphism.md)

---

## Table of Contents
- [Object-Oriented Paradigm in C++](#object-oriented-paradigm-in-c)
- [`class` vs `struct`](#class-vs-struct)
- [Access Specifiers: `public`, `private`, `protected`](#access-specifiers-public-private-protected)
- [Constructors & Member Initializer Lists](#constructors--member-initializer-lists)
- [Destructors (`~ClassName`)](#destructors-classname)
- [Const Member Functions](#const-member-functions)
- [The `this` Pointer](#the-this-pointer)
- [Static Members](#static-members)
- [💻 Exercises - Day 21](#-exercises---day-21)

---

## `class` vs `struct`
In C++, `struct` and `class` are nearly identical, with only ONE difference:
- In a `struct`, members are **`public`** by default.
- In a `class`, members are **`private`** by default.

Idiomatic convention: Use `struct` for plain passive data (DTOs / records); use `class` when enforcing invariants and encapsulation.

---

## Member Initializer Lists
Always prefer member initializer lists over assignment inside the constructor body:

```cpp
class Account {
    std::string owner;
    double balance;
public:
    // RECOMMENDED: initializes members directly without extra default-constructions!
    Account(std::string name, double initial)
        : owner(std::move(name)), balance(initial) {}
};
```

---

## Const Member Functions
A member function marked `const` promises not to modify any member variables of the object. It can be safely called on `const` instances:

```cpp
double get_balance() const { return balance; } // Cannot modify member variables
```

---

## 💻 Exercises - Day 21

### Exercises: Level 1
1. Create a `Rectangle` class with private `width` and `height`. Provide a parameterized constructor, getters, setters, and member functions `area()` and `perimeter()`.
2. Instantiate `const Rectangle r(10, 5);` and verify that calling `r.area()` works only because `area()` is marked `const`.
3. Create a `Counter` class with a `static int total_instances` tracking how many objects have been created.

### Exercises: Level 2
1. Bank Account Class: Implement a `BankAccount` with account number, account holder name, and balance. Implement deposit, withdrawal (with validation), and interest calculation methods.
2. Custom Dynamic String Wrapper: Create a minimal string class `SimpleString` that allocates a `char*` buffer in its constructor and deallocates it in its destructor `~SimpleString()`. Verify RAII.

### Exercises: Level 3
1. Implement a `Matrix` class with dynamic dimensions (rows, cols). Implement methods for addition, scalar multiplication, and transpose, ensuring bounds checking.
