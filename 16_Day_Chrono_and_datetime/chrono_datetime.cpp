// Day 16: std::chrono, Time Measurements & Benchmarking
// Compile: g++ -std=c++20 -Wall -Wextra chrono_datetime.cpp -o chrono_datetime

#include <iostream>
#include <chrono>
#include <vector>
#include <ctime>

// RAII Execution Timer
class ScopedTimer {
    std::string task_name;
    std::chrono::steady_clock::time_point start_time;
public:
    explicit ScopedTimer(std::string name)
        : task_name(std::move(name)), start_time(std::chrono::steady_clock::now()) {}

    ~ScopedTimer() {
        auto end_time = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
        std::cout << "[Timer] '" << task_name << "' took: " << elapsed.count() << " microseconds\n";
    }
};

int main() {
    std::cout << "=== Day 16: Chrono & Date Time ===\n\n";

    // 1. Current wall-clock time
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::cout << "Current System Time: " << std::ctime(&now_c);

    // 2. Benchmarking with ScopedTimer
    {
        ScopedTimer timer("Populating vector without reserve");
        std::vector<int> v;
        for (int i = 0; i < 200000; ++i) {
            v.push_back(i);
        }
    }

    {
        ScopedTimer timer("Populating vector WITH reserve");
        std::vector<int> v;
        v.reserve(200000);
        for (int i = 0; i < 200000; ++i) {
            v.push_back(i);
        }
    }

    return 0;
}
