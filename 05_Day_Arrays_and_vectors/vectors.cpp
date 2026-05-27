// Day 5: Arrays and Vectors in C++
// Compile: g++ -std=c++20 -Wall -Wextra vectors.cpp -o vectors

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

int main() {
    std::cout << "=== Day 5: Arrays & Vectors ===\n\n";

    // 1. std::array (fixed size, stack allocated)
    std::array<int, 4> fixed_arr{10, 20, 30, 40};
    std::cout << "std::array size: " << fixed_arr.size() << "\n";
    std::cout << "Element at index 2: " << fixed_arr[2] << "\n\n";

    // 2. std::vector (dynamic size, heap allocated)
    std::vector<int> vec;
    std::cout << "Initial size: " << vec.size() << ", capacity: " << vec.capacity() << "\n";

    vec.reserve(10); // Preallocate capacity
    std::cout << "After reserve(10) -> capacity: " << vec.capacity() << "\n";

    for (int i = 1; i <= 5; ++i) {
        vec.push_back(i * 10);
    }
    std::cout << "After 5 pushes -> size: " << vec.size() << ", capacity: " << vec.capacity() << "\n\n";

    // 3. Element access (bounds-safe vs unchecked)
    std::cout << "Front: " << vec.front() << ", Back: " << vec.back() << "\n";
    try {
        std::cout << "Accessing vec.at(10)...\n";
        [[maybe_unused]] int val = vec.at(10); // Throws out_of_range exception
    } catch (const std::out_of_range& e) {
        std::cout << "Caught expected exception: " << e.what() << "\n\n";
    }

    // 4. Range-based for loop
    std::cout << "Vector contents: ";
    for (const auto& num : vec) {
        std::cout << num << " ";
    }
    std::cout << "\n\n";

    // 5. 2D Vector (Matrix)
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    std::cout << "--- 2D Matrix (3x3) ---\n";
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << "\t";
        }
        std::cout << "\n";
    }

    return 0;
}
