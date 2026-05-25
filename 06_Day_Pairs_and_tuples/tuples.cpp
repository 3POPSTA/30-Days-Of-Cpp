// Day 6: Pairs, Tuples, and Structured Bindings
// Compile: g++ -std=c++20 -Wall -Wextra tuples.cpp -o tuples

#include <iostream>
#include <utility>
#include <tuple>
#include <string>
#include <vector>

// Function returning multiple values via tuple
std::tuple<int, int, double> calculate_summary(const std::vector<int>& values) {
    if (values.empty()) return {0, 0, 0.0};
    int min_v = values[0];
    int max_v = values[0];
    long long sum = 0;
    for (int v : values) {
        if (v < min_v) min_v = v;
        if (v > max_v) max_v = v;
        sum += v;
    }
    double avg = static_cast<double>(sum) / values.size();
    return {min_v, max_v, avg};
}

int main() {
    std::cout << "=== Day 6: Pairs & Tuples ===\n\n";

    // 1. std::pair
    std::pair<std::string, int> item{"Mechanical Keyboard", 120};
    std::cout << "Pair: " << item.first << " -> $" << item.second << "\n\n";

    // 2. std::tuple
    std::tuple<std::string, int, double, bool> employee{
        "Grace Hopper", 1001, 95000.50, true
    };

    // Access via std::get
    std::cout << "Employee ID: " << std::get<1>(employee) << "\n";
    std::cout << "Employee Salary: $" << std::get<2>(employee) << "\n\n";

    // 3. C++17 Structured Bindings
    std::cout << "--- C++17 Structured Bindings ---\n";
    auto [name, id, salary, is_active] = employee;
    std::cout << "Name:      " << name << "\n";
    std::cout << "ID:        " << id << "\n";
    std::cout << "Salary:    $" << salary << "\n";
    std::cout << "Active:    " << std::boolalpha << is_active << "\n\n";

    // 4. Function returning tuple + structured binding
    std::vector<int> scores{88, 92, 79, 95, 84, 91};
    auto [min_score, max_score, average] = calculate_summary(scores);
    std::cout << "Scores Summary:\n";
    std::cout << "Min Score: " << min_score << "\n";
    std::cout << "Max Score: " << max_score << "\n";
    std::cout << "Average:   " << average << "\n";

    return 0;
}
