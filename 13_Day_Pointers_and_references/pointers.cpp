// Day 13: Pointers and References in C++
// Compile: g++ -std=c++20 -Wall -Wextra pointers.cpp -o pointers

#include <iostream>

void modify_via_pointer(int* ptr) {
    if (ptr != nullptr) {
        *ptr += 100;
    }
}

void modify_via_ref(int& ref) {
    ref += 500;
}

int main() {
    std::cout << "=== Day 13: Pointers & References ===\n\n";

    int number = 42;
    std::cout << "Original value:   " << number << "\n";
    std::cout << "Memory address:   " << &number << "\n\n";

    // 1. References (alias)
    int& num_ref = number;
    modify_via_ref(num_ref);
    std::cout << "After modify_via_ref: " << number << "\n";

    // 2. Pointers (address holders)
    int* num_ptr = &number;
    std::cout << "num_ptr holds:        " << num_ptr << "\n";
    std::cout << "Dereferenced *ptr:    " << *num_ptr << "\n";

    modify_via_pointer(num_ptr);
    std::cout << "After modify_via_ptr: " << number << "\n\n";

    // 3. nullptr check
    int* dangerous_ptr = nullptr;
    if (dangerous_ptr == nullptr) {
        std::cout << "Safely avoided null pointer dereference!\n\n";
    }

    // 4. Pointer arithmetic with arrays
    int scores[] = {10, 20, 30, 40, 50};
    int* p_score = scores; // Decays to pointer to first element

    std::cout << "Traversing array using pointer arithmetic: ";
    for (size_t i = 0; i < 5; ++i) {
        std::cout << *(p_score + i) << " ";
    }
    std::cout << "\n";

    return 0;
}
