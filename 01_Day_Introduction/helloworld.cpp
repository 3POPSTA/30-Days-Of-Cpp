// Day 1: Introduction to C++
// Compile: g++ -std=c++20 -Wall -Wextra helloworld.cpp -o helloworld

#include <iostream>

int main() {
    // 1. Classic greeting
    std::cout << "============================================" << std::endl;
    std::cout << "🚀 Welcome to 30 Days of Modern C++!" << std::endl;
    std::cout << "============================================" << std::endl;

    // 2. Printing multiple lines
    std::cout << "Day 01: Introduction & Environment Setup" << std::endl;
    std::cout << "C++ Standard: C++20 / C++23" << std::endl;

    // 3. Using '\n' vs std::endl (std::endl flushes the stream, '\n' is faster)
    std::cout << "Tip: Prefer '\n' over std::endl in high-throughput logging!\n";

    return 0; // 0 indicates successful execution to the operating system
}
