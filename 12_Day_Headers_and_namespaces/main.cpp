// Day 12: Multi-file project entry point
// Compile: g++ -std=c++20 -Wall -Wextra main.cpp math_utils.cpp -o multi_file_app

#include <iostream>
#include "math_utils.hpp"

int main() {
    std::cout << "=== Day 12: Headers & Namespaces ===\n\n";

    double x = 45.0;
    double y = 15.0;

    std::cout << "MathUtils::PI: " << MathUtils::PI << "\n";
    std::cout << x << " + " << y << " = " << MathUtils::add(x, y) << "\n";
    std::cout << x << " - " << y << " = " << MathUtils::subtract(x, y) << "\n";
    std::cout << x << " * " << y << " = " << MathUtils::multiply(x, y) << "\n";
    std::cout << x << " / " << y << " = " << MathUtils::divide(x, y) << "\n";

    return 0;
}
