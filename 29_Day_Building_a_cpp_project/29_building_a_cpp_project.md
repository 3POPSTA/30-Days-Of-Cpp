<div align="center">
  <h1>🚀 30 Days Of C++: Day 29 - Building a Complete C++ Project</h1>
  <sub>Architecture, header-source separation, persistence, and CLI Task Manager</sub>
</div>

[<< Day 28: Modern Features](../28_Day_Modern_cpp_features/28_modern_cpp_features.md) | [Day 30: Conclusions >>](../30_Day_Conclusions/30_conclusions.md)

---

## Table of Contents
- [Project Overview: Modular CLI Task Manager](#project-overview)
- [Architecture & Design Principles](#architecture--design-principles)
- [File Structure](#file-structure)
- [Building the Project](#building-the-project)
- [Running and Testing](#running-and-testing)
- [💻 Exercises - Day 29](#-exercises---day-29)

---

## Project Overview
In Day 29, we synthesize everything learned across the previous 28 days—classes, vectors, file streams, exceptions, modern algorithms, and CMake—into a complete, production-structured CLI Task Management application.

### File Structure
```
29_Day_Building_a_cpp_project/
├── CMakeLists.txt
├── task.hpp
├── task.cpp
├── task_manager.hpp
├── task_manager.cpp
└── main.cpp
```

---

## Building the Project

### Using direct g++:
```bash
g++ -std=c++20 -Wall -Wextra main.cpp task.cpp task_manager.cpp -o task_cli
./task_cli
```

### Using CMake:
```bash
cmake -B build
cmake --build build
./build/task_cli
```

---

## 💻 Exercises - Day 29

### Exercises: Level 1
1. Compile and run the Day 29 CLI Task Manager. Add tasks, mark tasks as completed, and inspect the saved file.
2. Add a priority property (`enum class Priority { Low, Medium, High }`) to each task and display it.

### Exercises: Level 2
1. Add filtering by status: Implement a command `filter <completed|pending>` to only view matching tasks.
2. Add a search command `search <keyword>` that matches keywords in task descriptions.

### Exercises: Level 3
1. Implement sorting: Sort tasks by creation timestamp or alphabetical title using `std::sort`.
2. Add export to CSV and JSON functionality.
