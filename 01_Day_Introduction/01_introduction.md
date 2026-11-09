<div align="center">
  <h1>🚀 30 Days Of C++: Day 1 - Introduction & Setup</h1>
  <sub>Master modern C++ from first principles to production mastery</sub>
</div>

[<< Table of Contents](../readme.md) | [Day 2: Variables & Data Types >>](../02_Day_Variables_and_data_types/02_variables_and_data_types.md)

---

## Table of Contents
- [Welcome to 30 Days of C++](#welcome-to-30-days-of-c)
- [Why C++?](#why-c)
- [The C++ Compilation Model](#the-c-compilation-model)
- [Development Environment Setup](#development-environment-setup)
  - [Windows (MSYS2 / MinGW-w64)](#windows-msys2--mingw-w64)
  - [Linux (GCC / Clang)](#linux-gcc--clang)
  - [macOS (Apple Clang / Homebrew GCC)](#macos-apple-clang--homebrew-gcc)
- [Your First C++ Program: Hello World](#your-first-c-program-hello-world)
  - [Code Breakdown](#code-breakdown)
  - [Compiling and Running via CLI](#compiling-and-running-via-cli)
- [Common Compiler Flags](#common-compiler-flags)
- [💻 Exercises - Day 1](#-exercises---day-1)

---

## Welcome to 30 Days of C++
C++ is one of the most powerful, influential, and widely deployed systems programming languages in computer science history. Designed by **Bjarne Stroustrup** at Bell Labs in 1979 as an extension of the C language ("C with Classes"), C++ has evolved into a multi-paradigm powerhouse supporting procedural, object-oriented, functional, and generic programming.

This 30-day curriculum focuses on **Modern C++ (C++17, C++20, and C++23)**. We prioritize memory safety, clean idioms, RAII (Resource Acquisition Is Initialization), Standard Library (STL) algorithms, and production performance.

---

## Why C++?
1. **Zero-Overhead Abstraction**: You only pay for what you use. High-level abstractions (templates, classes, ranges) compile down to bare-metal machine code with zero runtime cost.
2. **Direct Hardware Control**: Direct access to memory pointers, hardware registers, and system cache hierarchies.
3. **Deterministic Resource Management**: Through RAII, resources (memory, file handles, network sockets, thread locks) are released automatically and deterministically when going out of scope without needing a Garbage Collector.
4. **Dominance in High-Performance Domains**:
   - Game engines (Unreal Engine)
   - High-Frequency Trading (HFT) and quantitative finance
   - Operating systems and hypervisors (Windows, Linux, macOS kernels)
   - Web browsers (V8, Chromium, WebKit)
   - AI/ML frameworks (PyTorch, TensorFlow runtime engines)
   - Embedded systems, robotics, and aerospace

---

## The C++ Compilation Model
Unlike interpreted or bytecode languages, C++ compiles directly into native CPU machine instructions. The process has 4 distinct phases:

```
Source Code (.cpp, .hpp)
        │
        ▼  [1. Preprocessor]  (Expands #include, #define, #ifdef)
Preprocessed Source
        │
        ▼  [2. Compiler]      (Parses syntax, semantic analysis, optimizes, generates assembly)
Assembly Code (.s)
        │
        ▼  [3. Assembler]     (Converts assembly to machine code)
Object File (.o / .obj)
        │
        ▼  [4. Linker]        (Resolves external symbols, combines objects & libraries)
Executable Binary (.exe / a.out)
```

---

## Development Environment Setup

### Windows (MSYS2 / MinGW-w64)
1. Download and install [MSYS2](https://www.msys2.org/).
2. In the MSYS2 UCRT64 terminal, run:
   ```bash
   pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-gdb mingw-w64-ucrt-x86_64-cmake
   ```
3. Add `C:\msys64\ucrt64\bin` to your system `PATH`.
4. Verify in PowerShell:
   ```powershell
   g++ --version
   ```

### Linux (GCC / Clang)
On Ubuntu/Debian:
```bash
sudo apt update
sudo apt install build-essential gdb cmake clang
```

### macOS (Apple Clang / Homebrew GCC)
Install Xcode command line tools:
```bash
xcode-select --install
```
Or via Homebrew:
```bash
brew install gcc cmake
```

---

## Your First C++ Program: Hello World

Create a file named `helloworld.cpp`:

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, World! Welcome to 30 Days of C++!" << std::endl;
    return 0;
}
```

### Code Breakdown
- `#include <iostream>`: A preprocessor directive including the Input/Output Stream library from the C++ Standard Library.
- `int main()`: The entry point function for every executable C++ program. It returns an integer status code to the operating system.
- `std::cout`: Standard character output object (pronounced "see-out"), part of the `std` namespace.
- `<<`: Stream insertion operator. It pushes formatted characters into the stream.
- `std::endl`: Inserts a newline character (`'\n'`) and flushes the output stream buffer.
- `return 0;`: Returns status code 0 to the calling environment, indicating successful termination. Non-zero codes signal an error.

### Compiling and Running via CLI
Run the following command in your terminal:

```bash
# Compile with C++20 standard and recommended warning flags
g++ -std=c++20 -Wall -Wextra helloworld.cpp -o helloworld

# Execute on Windows:
.\helloworld.exe

# Execute on Linux/macOS:
./helloworld
```

Output:
```text
Hello, World! Welcome to 30 Days of C++!
```

---

## Common Compiler Flags
Always compile your code with strict diagnostic flags to catch bugs before runtime:
- `-std=c++20`: Enforce the C++20 standard.
- `-Wall`: Enable all common warning messages.
- `-Wextra`: Enable extra warning flags not covered by `-Wall`.
- `-Wpedantic`: Enforce strict adherence to ISO C++.
- `-O2` or `-O3`: Turn on compiler optimization passes.
- `-g`: Emit debug symbols for GDB / LLDB inspection.

---

## 💻 Exercises - Day 1

### Exercises: Level 1
1. Verify your compiler version by running `g++ --version` or `clang++ --version` and print the output.
2. Compile and execute `helloworld.cpp` in the terminal.
3. Modify `helloworld.cpp` to print your name, favorite programming language, and the year.

### Exercises: Level 2
1. Write a program `about_me.cpp` that prints a formatted bio containing:
   - Your name
   - Your country of residence
   - Why you want to learn C++
   - The date you started this challenge
2. Experiment with removing `#include <iostream>` or misspelling `main` as `Main`. Read the compiler errors carefully to understand diagnostic messages.

### Exercises: Level 3
1. Write a program that prints an ASCII art rocket ship or computer terminal using multiple `std::cout` statements.
2. Compare the difference between `std::endl` and `'\n'`. Read about why modern C++ developers prefer `\n` when stream flushing is not strictly required.
