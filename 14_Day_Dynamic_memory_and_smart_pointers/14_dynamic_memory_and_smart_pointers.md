<div align="center">
  <h1>🚀 30 Days Of C++: Day 14 - Dynamic Memory & Smart Pointers</h1>
  <sub>Stack vs Heap, RAII, std::unique_ptr, std::shared_ptr, and std::weak_ptr</sub>
</div>

[<< Day 13: Pointers & References](../13_Day_Pointers_and_references/13_pointers_and_references.md) | [Day 15: Errors & Debugging >>](../15_Day_Errors_and_debugging/15_errors_and_debugging.md)

---

## Table of Contents
- [Stack vs Heap Allocation](#stack-vs-heap-allocation)
- [Legacy Manual Memory: `new` and `delete`](#legacy-manual-memory-new-and-delete)
- [RAII: The Core Philosophy of C++](#raii-the-core-philosophy-of-c)
- [`std::unique_ptr` (Exclusive Ownership)](#stdunique_ptr-exclusive-ownership)
- [`std::shared_ptr` (Shared Ownership)](#stdshared_ptr-shared-ownership)
- [`std::weak_ptr` (Breaking Cycles)](#stdweak_ptr-breaking-cycles)
- [Smart Pointer Best Practices](#smart-pointer-best-practices)
- [💻 Exercises - Day 14](#-exercises---day-14)

---

## Stack vs Heap Allocation
- **Stack**: Fast, automatic lifetime, managed by CPU execution pointer. Limited size.
- **Heap**: Dynamic memory pool, manually managed or managed by smart pointer wrappers. Slower, virtually unbounded size.

---

## RAII: Resource Acquisition Is Initialization
RAII guarantees that resources are acquired in a constructor and released in a destructor when the wrapper object leaves scope. This makes C++ memory management completely automatic and exception-safe without a garbage collector!

---

## `std::unique_ptr` (Exclusive Ownership)
Defined in `<memory>`.
- Owns and manages another object through a pointer.
- Cannot be copied, only moved (`std::move`).
- Zero overhead: same size and speed as a raw pointer!

```cpp
#include <memory>

auto ptr = std::make_unique<int>(100);
std::cout << *ptr << "\n";
// Memory automatically deallocated when ptr exits scope!
```

---

## `std::shared_ptr` (Shared Ownership)
- Multiple `shared_ptr` instances can own the same resource.
- Maintains an internal thread-safe reference count.
- Resource is deleted when the reference count drops to zero.

```cpp
auto p1 = std::make_shared<std::string>("Shared Resource");
auto p2 = p1; // Ref count becomes 2
std::cout << "Use count: " << p1.use_count() << "\n"; // 2
```

---

## 💻 Exercises - Day 14

### Exercises: Level 1
1. Allocate an integer dynamically using `std::make_unique<int>`. Assign it a value, print it, and verify how scope destruction works.
2. Create a struct `Person` with a constructor and destructor that print messages. Instantiate it with `std::unique_ptr` inside an inner `{}` block and watch the destructor trigger automatically upon exiting the block.
3. Demonstrate transfer of ownership of a `std::unique_ptr` using `std::move`.

### Exercises: Level 2
1. Create a `std::vector<std::unique_ptr<std::string>>`. Add 3 strings dynamically and iterate over the vector to print them.
2. Use `std::shared_ptr` to share a resource between two functions. Print `use_count()` before and after passing.

### Exercises: Level 3
1. Circular Reference Demonstration: Create two structs `NodeA` and `NodeB` holding `std::shared_ptr` to each other. Demonstrate that memory leaks because destructors are never called. Then fix the leak using `std::weak_ptr`.
2. Implement a simple Factory function that creates and returns `std::unique_ptr<Sensor>` based on a configuration type string.
