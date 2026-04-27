<div align="center">
  <h1>🚀 30 Days Of C++: Day 16 - Chrono & Date Time</h1>
  <sub>Clocks, durations, time points, benchmarking, and calendar features</sub>
</div>

[<< Day 15: Errors & Debugging](../15_Day_Errors_and_debugging/15_errors_and_debugging.md) | [Day 17: Exception Handling >>](../17_Day_Exception_handling/17_exception_handling.md)

---

## Table of Contents
- [The `<chrono>` Header](#the-chrono-header)
- [Clocks: System, Steady & High Resolution](#clocks-system-steady--high-resolution)
- [Durations & Units](#durations--units)
- [Benchmarking Code Execution](#benchmarking-code-execution)
- [C++20 Chrono Calendar Features](#c20-chrono-calendar-features)
- [💻 Exercises - Day 16](#-exercises---day-16)

---

## Clocks: System, Steady & High Resolution
Defined in `<chrono>`:
- `std::chrono::system_clock`: Real-world wall-clock time. Can be adjusted by NTP or user, so NOT suitable for measuring elapsed time.
- `std::chrono::steady_clock`: Monotonic clock that never goes backwards. **Ideal for benchmarking.**
- `std::chrono::high_resolution_clock`: Clock with smallest tick period available.

---

## Durations & Units
C++ provides strongly-typed duration literals:
- `std::chrono::nanoseconds`
- `std::chrono::microseconds`
- `std::chrono::milliseconds`
- `std::chrono::seconds`

```cpp
using namespace std::chrono_literals;
auto delay = 250ms; // 250 milliseconds
auto timeout = 5s;  // 5 seconds
```

---

## Benchmarking Code Execution
```cpp
auto start = std::chrono::steady_clock::now();

// Code to measure...

auto end = std::chrono::steady_clock::now();
auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
std::cout << "Elapsed: " << elapsed.count() << " us\n";
```

---

## 💻 Exercises - Day 16

### Exercises: Level 1
1. Print the current system wall-clock time as a formatted string using `std::chrono::system_clock::to_time_t`.
2. Measure the time it takes to push 100,000 integers into a `std::vector<int>` without calling `reserve()`.
3. Measure the time it takes to push 100,000 integers into a `std::vector<int>` WITH calling `reserve(100000)`. Compare the two measurements.

### Exercises: Level 2
1. Write a reusable `Timer` class using RAII that records start time upon construction and prints elapsed time in microseconds upon destruction.
2. Benchmark sorting 50,000 random integers using `std::sort`.

### Exercises: Level 3
1. Explore C++20 calendar types: Create a `std::chrono::year_month_day` object representing today's date and check if it is a valid date using `.ok()`.
2. Build a micro-benchmark harness function `benchmark(std::string_view name, Func&& f, int iterations)` that executes a callable $N$ times and computes the average, minimum, and maximum execution times.
