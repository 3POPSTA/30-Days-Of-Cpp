// Day 15: Errors, Undefined Behavior & Diagnostic Defenses
// Compile: g++ -std=c++20 -Wall -Wextra -g debugging.cpp -o debugging

#include <iostream>
#include <vector>
#include <optional>

// Defensive function preventing division by zero error
std::optional<double> safe_divide(double numerator, double denominator) {
    if (denominator == 0.0) {
        return std::nullopt; // Safe return without crashing
    }
    return numerator / denominator;
}

int main() {
    std::cout << "=== Day 15: Errors & Debugging ===\n\n";

    // 1. Safe division demonstration
    double a = 10.0;
    double b = 0.0;

    auto result = safe_divide(a, b);
    if (result.has_value()) {
        std::cout << "Result: " << result.value() << "\n";
    } else {
        std::cout << "[Defensive Check] Cannot divide by zero!\n\n";
    }

    // 2. Out of bounds defense: std::vector::at() vs operator[]
    std::vector<int> numbers{10, 20, 30};
    std::cout << "Vector size: " << numbers.size() << "\n";

    try {
        std::cout << "Attempting to access index 5 via .at()...\n";
        [[maybe_unused]] int val = numbers.at(5); // Caught safely
    } catch (const std::out_of_range& e) {
        std::cout << "Safely caught out_of_range exception: " << e.what() << "\n\n";
    }

    std::cout << "All defensive checks passed!\n";
    return 0;
}
