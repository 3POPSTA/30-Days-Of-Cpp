// Day 26: Lambdas and Functional C++
// Compile: g++ -std=c++20 -Wall -Wextra lambdas.cpp -o lambdas

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>

// Higher-order function: accepts a function as argument
void process_records(const std::vector<int>& records,
                     const std::function<void(int)>& processor) {
    for (int r : records) {
        processor(r);
    }
}

// Function returning a closure (generator factory)
auto make_adder(int increment) {
    return [increment](int value) {
        return value + increment;
    };
}

int main() {
    std::cout << "=== Day 26: Lambdas & Functional C++ ===\n\n";

    // 1. Basic & Generic Lambda
    auto print_double = [](auto x) {
        std::cout << "Double: " << (x * 2) << "\n";
    };
    print_double(21);
    print_double(3.14);
    std::cout << "\n";

    // 2. Capture by value vs reference
    int factor = 10;
    auto multiplier = [factor](int x) { return x * factor; };
    std::cout << "5 * " << factor << " = " << multiplier(5) << "\n\n";

    // 3. Mutable lambda (stateful closure)
    auto counter = [count = 0]() mutable {
        return ++count;
    };
    std::cout << "Call 1: " << counter() << "\n";
    std::cout << "Call 2: " << counter() << "\n";
    std::cout << "Call 3: " << counter() << "\n\n";

    // 4. Higher-order function usage
    std::vector<int> sensor_data{100, 200, 300};
    std::cout << "Processing sensor data:\n";
    process_records(sensor_data, [](int val) {
        std::cout << "Sensor telemetry: " << val << " mV\n";
    });
    std::cout << "\n";

    // 5. Returning a closure
    auto add100 = make_adder(100);
    std::cout << "add100(25) = " << add100(25) << "\n";

    return 0;
}
