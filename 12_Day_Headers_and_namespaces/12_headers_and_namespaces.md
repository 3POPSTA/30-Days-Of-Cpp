<div align="center">
  <h1>🚀 30 Days Of C++: Day 12 - Headers, Source Files & Namespaces</h1>
  <sub>Multi-file compilation, #pragma once, namespaces, and C++20 modules intro</sub>
</div>

[<< Day 11: Functions](../11_Day_Functions/11_functions.md) | [Day 13: Pointers & References >>](../13_Day_Pointers_and_references/13_pointers_and_references.md)

---

## Table of Contents
- [Multi-File C++ Architecture](#multi-file-c-architecture)
- [Header Files (`.hpp`) vs Source Files (`.cpp`)](#header-files-hpp-vs-source-files-cpp)
- [Header Guards vs `#pragma once`](#header-guards-vs-pragma-once)
- [Namespaces & Avoiding `using namespace std;`](#namespaces--avoiding-using-namespace-std)
- [Nested & Anonymous Namespaces](#nested--anonymous-namespaces)
- [Introduction to C++20 Modules](#introduction-to-c20-modules)
- [Compiling Multi-File Projects](#compiling-multi-file-projects)
- [💻 Exercises - Day 12](#-exercises---day-12)

---

## Multi-File C++ Architecture
Real-world software is split across multiple files:
- **Header Files (`.hpp` or `.h`)**: Contain declarations, prototypes, class definitions, and inline templates.
- **Source Files (`.cpp`)**: Contain implementation definitions and business logic.

---

## Header Guards vs `#pragma once`
To prevent the same header from being included multiple times in a translation unit (which causes duplicate symbol definition errors), use `#pragma once`:

```cpp
#pragma once

namespace Math {
    double square(double x);
}
```

---

## Namespaces & Avoiding `using namespace std;`
Namespaces prevent naming collisions between different libraries.

> [!CAUTION]
> **NEVER put `using namespace std;` in a header file!**
> Doing so pollutes the global namespace of every file that includes your header, causing subtle and hard-to-diagnose name clashes.

---

## Compiling Multi-File Projects
```bash
g++ -std=c++20 -Wall -Wextra main.cpp math_utils.cpp -o app
```

---

## 💻 Exercises - Day 12

### Exercises: Level 1
1. Inspect `math_utils.hpp`, `math_utils.cpp`, and `main.cpp`. Compile them together using `g++` and run the executable.
2. Add a new function `double power(double base, int exponent)` into `math_utils.hpp` and implement it in `math_utils.cpp`. Call it from `main.cpp`.
3. Create a custom namespace `Physics::Constants` containing constants like `speed_of_light` and `gravity`.

### Exercises: Level 2
1. Create a `geometry.hpp` and `geometry.cpp` with a namespace `Geometry`. Implement functions for circle circumference, sphere volume, and cylinder surface area.
2. Demonstrate how anonymous namespaces (`namespace { ... }`) create internal linkage, making functions invisible to other translation units.

### Exercises: Level 3
1. Create a 3-tier architecture:
   - `logger.hpp` / `logger.cpp` (Logging utility)
   - `account.hpp` / `account.cpp` (Bank Account logic)
   - `main.cpp` (Application entrypoint)
   Compile all three translation units together and verify clean separation of concerns.
