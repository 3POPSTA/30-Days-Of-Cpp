// Day 3: Operators in Modern C++
// Compile: g++ -std=c++20 -Wall -Wextra operators.cpp -o operators

#include <iostream>
#include <compare>
#include <bitset>
#include <cstdint>

int main() {
    std::cout << "=== Day 3: Operators ===\n\n";

    // 1. Arithmetic & Integer Division
    int x = 17;
    int y = 5;
    std::cout << "x = " << x << ", y = " << y << "\n";
    std::cout << "x + y = " << (x + y) << "\n";
    std::cout << "x - y = " << (x - y) << "\n";
    std::cout << "x * y = " << (x * y) << "\n";
    std::cout << "x / y (integer) = " << (x / y) << "\n";
    std::cout << "x / y (floating) = " << (static_cast<double>(x) / y) << "\n";
    std::cout << "x % y (remainder) = " << (x % y) << "\n\n";

    // 2. Prefix vs Postfix
    int count = 10;
    std::cout << "Initial count: " << count << "\n";
    std::cout << "count++ (postfix returns old value): " << count++ << "\n";
    std::cout << "After postfix, count is: " << count << "\n";
    std::cout << "++count (prefix returns new value): " << ++count << "\n\n";

    // 3. Relational & Logical Operators
    bool is_weekend = false;
    bool has_free_time = true;
    bool can_code = is_weekend || has_free_time;
    std::cout << "Can code today? " << std::boolalpha << can_code << "\n\n";

    // 4. C++20 Spaceship Operator (<=>)
    int val_a = 42;
    int val_b = 99;
    auto cmp = (val_a <=> val_b);
    if (cmp < 0) {
        std::cout << val_a << " is LESS than " << val_b << "\n\n";
    }

    // 5. Bitwise Operations & Bitset
    uint8_t a = 0b00001100; // 12
    uint8_t b = 0b00001010; // 10
    std::cout << "Bitwise a:       " << std::bitset<8>(a) << "\n";
    std::cout << "Bitwise b:       " << std::bitset<8>(b) << "\n";
    std::cout << "a & b (AND):     " << std::bitset<8>(a & b) << "\n";
    std::cout << "a | b (OR):      " << std::bitset<8>(a | b) << "\n";
    std::cout << "a ^ b (XOR):     " << std::bitset<8>(a ^ b) << "\n";
    std::cout << "a << 2 (LSHIFT): " << std::bitset<8>(a << 2) << "\n\n";

    // 6. Ternary Operator
    int marks = 85;
    std::string grade = (marks >= 50) ? "PASS" : "FAIL";
    std::cout << "Marks: " << marks << " -> " << grade << "\n";

    return 0;
}
