<div align="center">
  <h1>🚀 30 Days Of C++: Day 22 - Inheritance & Polymorphism</h1>
  <sub>Virtual functions, vtable, abstract classes, override, and virtual destructors</sub>
</div>

[<< Day 21: Classes & Objects](../21_Day_Classes_and_objects/21_classes_and_objects.md) | [Day 23: Operator Overloading >>](../23_Day_Operator_overloading_and_move_semantics/23_operator_overloading_and_move_semantics.md)

---

## Table of Contents
- [Inheritance Syntax & Access](#inheritance-syntax--access)
- [Constructor & Destructor Order](#constructor--destructor-order)
- [Virtual Functions & Dynamic Dispatch](#virtual-functions--dynamic-dispatch)
- [The `vtable` and `vptr` Explained](#the-vtable-and-vptr-explained)
- [Pure Virtual Functions & Abstract Classes](#pure-virtual-functions--abstract-classes)
- [`override` and `final` Specifiers](#override-and-final-specifiers)
- [CRITICAL: Virtual Destructors](#critical-virtual-destructors)
- [💻 Exercises - Day 22](#-exercises---day-22)

---

## Virtual Functions & Dynamic Dispatch
Without `virtual`, C++ performs static binding (compile-time resolution based on pointer type).
With `virtual`, C++ performs dynamic binding (runtime dispatch based on actual runtime object type).

```cpp
class Shape {
public:
    virtual ~Shape() = default; // VITAL!
    virtual void draw() const = 0; // Pure virtual function -> Abstract Class!
};

class Circle : public Shape {
public:
    void draw() const override { // Explicitly override
        std::cout << "Drawing Circle\n";
    }
};
```

---

## CRITICAL: Virtual Destructors
If a class has any virtual functions, its destructor **MUST be declared `virtual`**:

```cpp
virtual ~Base() = default;
```

**Why?** If you delete a derived object through a base pointer (`Base* ptr = new Derived(); delete ptr;`), and `~Base()` is not virtual, only `~Base()` runs—the derived destructor is skipped, causing memory leaks and undefined behavior!

---

## 💻 Exercises - Day 22

### Exercises: Level 1
1. Create a base class `Vehicle` and derived classes `Car` and `Motorcycle`. Implement a virtual function `start_engine()`.
2. Demonstrate polymorphism by storing pointers to `Car` and `Motorcycle` inside a `std::vector<std::unique_ptr<Vehicle>>` and calling `start_engine()` in a loop.
3. Verify why `override` protects against subtle bugs: Intentionally write a mismatched signature with `override` and read the compiler diagnostic.

### Exercises: Level 2
1. Payment Gateway Interface:
   - Create an abstract class `PaymentProcessor` with pure virtual function `process_payment(double amount)`.
   - Implement `CreditCardProcessor` and `CryptoProcessor`.
   - Write a checkout function `void checkout(PaymentProcessor& processor, double total)`.

### Exercises: Level 3
1. Employee Payroll Hierarchy:
   - Base abstract class `Employee` with pure virtual `calculate_monthly_pay()`.
   - Derived classes: `SalariedEmployee`, `HourlyEmployee`, `CommissionEmployee`.
   - Compute total company monthly payroll using smart pointers.
