// Day 11: Functions in Modern C++
// Compile: g++ -std=c++20 -Wall -Wextra functions.cpp -o functions

#include <iostream>
#include <string>
#include <vector>
#include <array>

// 1. Pass-by-value (for primitives)
int add(int a, int b) {
    return a + b;
}

// 2. Pass-by-reference (modifies caller's variable)
void increment_in_place(int& x) {
    ++x;
}

// 3. Pass-by-const-reference (avoids copy, read-only)
void display_banner(const std::string& title) {
    std::cout << "--- [ " << title << " ] ---\n";
}

// 4. Function overloading
double area(double radius) {
    constexpr double PI = 3.14159265;
    return PI * radius * radius;
}

double area(double width, double height) {
    return width * height;
}

// 5. constexpr function (computable at compile time!)
constexpr int compile_time_fact(int n) {
    return (n <= 1) ? 1 : (n * compile_time_fact(n - 1));
}

int main() {
    std::cout << "=== Day 11: Functions ===\n\n";

    display_banner("Math Utilities");
    std::cout << "add(15, 27) = " << add(15, 27) << "\n";

    int counter = 100;
    increment_in_place(counter);
    std::cout << "After increment_in_place, counter = " << counter << "\n\n";

    std::cout << "Overloaded area(circle r=5):     " << area(5.0) << "\n";
    std::cout << "Overloaded area(rectangle 4x6):  " << area(4.0, 6.0) << "\n\n";

    // Use compile-time evaluated factorial as std::array size!
    constexpr int fact4 = compile_time_fact(4); // 24 at compile time
    std::array<int, fact4> buffer{};
    std::cout << "Compile-time factorial(4) = " << fact4 << "\n";
    std::cout << "Created std::array of size: " << buffer.size() << "\n";

    return 0;
}
