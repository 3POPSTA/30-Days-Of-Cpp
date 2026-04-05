<div align="center">
  <h1>🚀 30 Days Of C++: Day 27 - Concurrency & Multithreading</h1>
  <sub>std::thread, mutex, lock_guard, atomics, and asynchronous std::async</sub>
</div>

[<< Day 26: Lambdas](../26_Day_Lambdas_and_functional_programming/26_lambdas_and_functional_programming.md) | [Day 28: Modern Features >>](../28_Day_Modern_cpp_features/28_modern_cpp_features.md)

---

## Table of Contents
- [Threads: `std::thread` and `std::jthread` (C++20)](#threads-stdthread-and-stdjthread)
- [Joining and Detaching](#joining-and-detaching)
- [Data Races & Critical Sections](#data-races--critical-sections)
- [Mutexes & `std::lock_guard`](#mutexes--stdlock_guard)
- [Lock-Free Concurrency: `std::atomic<T>`](#lock-free-concurrency-stdatomic)
- [Asynchronous Tasks: `std::async` & `std::future`](#asynchronous-tasks-stdasync--stdfuture)
- [💻 Exercises - Day 27](#-exercises---day-27)

---

## Threads: `std::thread`
Defined in `<thread>`.
Every thread represents an independent execution path:

```cpp
#include <thread>
#include <iostream>

void task() {
    std::cout << "Worker thread running!\n";
}

int main() {
    std::thread t(task);
    t.join(); // Main thread waits for t to finish!
}
```

---

## Data Races & Mutexes
When multiple threads read and write shared data simultaneously without synchronization, a **Data Race** occurs (Undefined Behavior!).
Use `std::mutex` and RAII `std::lock_guard` (`<mutex>`) to protect shared memory:

```cpp
#include <mutex>

std::mutex mtx;
int shared_counter = 0;

void increment() {
    std::lock_guard<std::mutex> lock(mtx); // Locks on construction, unlocks on destruction
    ++shared_counter;
}
```

---

## Lock-Free Programming: `std::atomic<T>`
For fundamental types, `<atomic>` provides lock-free hardware synchronization without mutex overhead:

```cpp
#include <atomic>
std::atomic<int> counter{0};
counter.fetch_add(1); // Thread-safe atomic increment
```

---

## Asynchronous Programming: `std::async`
Defined in `<future>`. Runs a function asynchronously and delivers its return value in a `std::future`:

```cpp
#include <future>

int compute() { return 42 * 2; }

int main() {
    std::future<int> fut = std::async(std::launch::async, compute);
    std::cout << "Result: " << fut.get() << "\n"; // Blocks until result is ready
}
```

---

## 💻 Exercises - Day 27

### Exercises: Level 1
1. Launch 4 worker threads that each print their unique thread ID (`std::this_thread::get_id()`) and a greeting. Ensure all are properly joined.
2. Demonstrate a data race by running 10 threads incrementing a non-atomic integer 10,000 times without a mutex, and observe incorrect total sums.
3. Fix Exercise 2 using `std::atomic<int>` and verify the exact sum.

### Exercises: Level 2
1. Thread-Safe Bank Account: Implement a `SafeAccount` class where multiple threads concurrently deposit and withdraw money using `std::mutex` and `std::lock_guard`.
2. Asynchronous File Downloader Simulator: Use `std::async` to download 3 files in parallel (using `std::this_thread::sleep_for`), and collect their byte sizes via futures.

### Exercises: Level 3
1. Implement a Thread Pool: Design a basic multi-threaded worker pool with a thread-safe task queue and condition variables (`std::condition_variable`).
