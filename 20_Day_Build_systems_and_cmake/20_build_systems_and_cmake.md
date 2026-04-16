<div align="center">
  <h1>🚀 30 Days Of C++: Day 20 - Build Systems & Modern CMake</h1>
  <sub>Makefiles, target-based CMake, project layout, and package management</sub>
</div>

[<< Day 19: File Handling](../19_Day_File_handling/19_file_handling.md) | [Day 21: Classes & Objects >>](../21_Day_Classes_and_objects/21_classes_and_objects.md)

---

## Table of Contents
- [Why Build Systems?](#why-build-systems)
- [Standard C++ Project Directory Layout](#standard-c-project-directory-layout)
- [Target-Based Modern CMake](#target-based-modern-cmake)
- [Out-of-Source Builds](#out-of-source-builds)
- [C++ Package Managers: vcpkg & Conan](#c-package-managers-vcpkg--conan)
- [💻 Exercises - Day 20](#-exercises---day-20)

---

## Standard C++ Project Directory Layout
```
my_project/
├── CMakeLists.txt
├── include/
│   └── my_project/
│       └── calculator.hpp
├── src/
│   ├── calculator.cpp
│   └── main.cpp
└── tests/
    └── test_calculator.cpp
```

---

## Target-Based Modern CMake
Modern CMake organizes everything around **targets** (libraries and executables):

```cmake
cmake_minimum_required(VERSION 3.20)
project(ModernCppProject VERSION 1.0.0 LANGUAGES CXX)

# Enforce C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable
add_executable(app_demo main.cpp)

# Specify compile warnings
target_compile_options(app_demo PRIVATE
    $<$<CXX_COMPILER_ID:GNU,Clang>:-Wall -Wextra -Wpedantic>
    $<$<CXX_COMPILER_ID:MSVC>:/W4>
)
```

---

## Out-of-Source Builds
Never build inside the source directory. Always build in a dedicated `build/` directory:

```bash
# Configure build tree
cmake -B build -S .

# Compile
cmake --build build

# Run
./build/app_demo
```

---

## 💻 Exercises - Day 20

### Exercises: Level 1
1. Inspect the `CMakeLists.txt` and `main.cpp` in this day's folder.
2. Read about `add_executable()` vs `add_library()` in CMake.
3. What is the difference between `PRIVATE`, `PUBLIC`, and `INTERFACE` target properties in CMake?

### Exercises: Level 2
1. Create a CMake project that compiles a static library `MathEngine` containing vector math routines, and links it to an executable `MathCLI`.
2. Configure CMake to compile with optimization level `-O3` in `Release` mode and debug symbols `-g` in `Debug` mode.

### Exercises: Level 3
1. Explore `vcpkg`: Install `fmt` or `nlohmann-json` using `vcpkg install fmt`, then link it to your CMake project using `find_package(fmt CONFIG REQUIRED)`.
