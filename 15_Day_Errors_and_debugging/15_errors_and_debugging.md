<div align="center">
  <h1>🚀 30 Days Of C++: Day 15 - Errors, Undefined Behavior & Debugging</h1>
  <sub>Compile vs Link vs Runtime errors, Undefined Behavior, Sanitizers & GDB</sub>
</div>

[<< Day 14: Dynamic Memory & Smart Pointers](../14_Day_Dynamic_memory_and_smart_pointers/14_dynamic_memory_and_smart_pointers.md) | [Day 16: Chrono & Date Time >>](../16_Day_Chrono_and_datetime/16_chrono_and_datetime.md)

---

## Table of Contents
- [Categories of C++ Errors](#categories-of-c-errors)
- [Compile-Time Errors](#compile-time-errors)
- [Linker Errors (`LNK2019` / `undefined reference`)](#linker-errors-lnk2019--undefined-reference)
- [Runtime Errors & Segmentation Faults](#runtime-errors--segmentation-faults)
- [Undefined Behavior (UB): The Silent Killer](#undefined-behavior-ub-the-silent-killer)
- [Compiler Warnings as Errors](#compiler-warnings-as-errors)
- [Sanitizers: AddressSanitizer (ASan)](#sanitizers-addresssanitizer-asan)
- [Debugging with GDB / LLDB](#debugging-with-gdb--lldb)
- [💻 Exercises - Day 15](#-exercises---day-15)

---

## Categories of C++ Errors
1. **Preprocessor Errors**: Missing `#include` header files, syntax errors in macro definitions.
2. **Compiler Errors**: Type mismatches, undeclared variables, missing semicolons, template substitution failures.
3. **Linker Errors**: Occur when object files are combined into an executable:
   - `undefined reference to function_name()`: Declaration exists in `.hpp`, but definition is missing in `.cpp`!
   - `multiple definition of symbol`: Same variable or non-inline function defined in multiple translation units.
4. **Runtime Errors & UB**: Crashes, buffer overflows, double free, division by zero.

---

## Undefined Behavior (UB)
When your program violates C++ language rules, the compiler makes no guarantees about what machine code will be generated. Examples:
- Reading uninitialized variables
- Accessing arrays out of bounds
- Dereferencing `nullptr`
- Signed integer overflow

---

## Sanitizers: AddressSanitizer (ASan)
Modern compilers (GCC and Clang) provide built-in runtime instrumentation tools:
```bash
g++ -std=c++20 -fsanitize=address -g program.cpp -o program
```
If an out-of-bounds access or memory leak occurs, ASan halts the program immediately with an exact stack trace!

---

## 💻 Exercises - Day 15

### Exercises: Level 1
1. Intentionally create a linker error by declaring a function `void do_secret_work();` in a file and calling it from `main()`, but without providing a definition. Observe the linker diagnostic.
2. Demonstrate an out-of-bounds array read. Explain why C-style array access `arr[10]` might not immediately crash, but is dangerous Undefined Behavior.
3. Turn on strict compiler flags `-Wall -Wextra -Wpedantic -Werror`. Write code that generates a warning (e.g. unused variable) and watch the build fail.

### Exercises: Level 2
1. Write a function that tests for division by zero before performing division and returns a boolean status flag or throws a standard error.
2. Use AddressSanitizer (`-fsanitize=address`): Write a small program with an off-by-one heap buffer overflow. Compile with ASan and analyze the output crash report.

### Exercises: Level 3
1. Debugging with GDB:
   - Compile `debugging.cpp` with debug symbols (`-g`).
   - Launch GDB: `gdb ./debugging`.
   - Set a breakpoint: `break main`.
   - Run the program: `run`.
   - Step line-by-line: `next` or `step`.
   - Inspect variables: `print variable_name`.
   - Exit GDB: `quit`.
