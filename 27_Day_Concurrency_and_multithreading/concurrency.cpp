// Day 27: Concurrency, Threading, Mutexes, and Atomics
// Compile: g++ -std=c++20 -Wall -Wextra concurrency.cpp -o concurrency

#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <vector>
#include <future>
#include <chrono>

std::mutex print_mtx;
std::atomic<int> atomic_counter{0};

void worker_thread(int id) {
    for (int i = 0; i < 500; ++i) {
        atomic_counter.fetch_add(1);
    }

    // Thread-safe console printing
    {
        std::lock_guard<std::mutex> lock(print_mtx);
        std::cout << "Worker #" << id << " completed batch of 500 increments.\n";
    }
}

// Asynchronous heavy computation simulation
int calculate_factors_async(int base) {
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    return base * base;
}

int main() {
    std::cout << "=== Day 27: Concurrency & Multithreading ===\n\n";

    // 1. Spawning multiple threads
    std::cout << "--- Spawning 4 Worker Threads ---\n";
    std::vector<std::thread> thread_pool;
    for (int i = 1; i <= 4; ++i) {
        thread_pool.emplace_back(worker_thread, i);
    }

    // Wait for all threads to finish
    for (auto& t : thread_pool) {
        t.join();
    }

    std::cout << "Final Atomic Counter: " << atomic_counter.load() << " (Expected: 2000)\n\n";

    // 2. Asynchronous execution with std::async and std::future
    std::cout << "--- Asynchronous Task Demo (std::async) ---\n";
    std::future<int> f1 = std::async(std::launch::async, calculate_factors_async, 12);
    std::future<int> f2 = std::async(std::launch::async, calculate_factors_async, 20);

    std::cout << "Main thread is free to do other work while tasks compute in background...\n";

    int res1 = f1.get(); // Waits for completion
    int res2 = f2.get();

    std::cout << "Result 1: " << res1 << "\n";
    std::cout << "Result 2: " << res2 << "\n";

    return 0;
}
