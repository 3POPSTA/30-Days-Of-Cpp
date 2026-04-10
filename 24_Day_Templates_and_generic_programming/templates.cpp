// Day 24: Templates and Generic Programming in Modern C++
// Compile: g++ -std=c++20 -Wall -Wextra templates.cpp -o templates

#include <iostream>
#include <string>
#include <concepts>
#include <vector>

// 1. Function Template
template <typename T>
T get_max(T a, T b) {
    return (a > b) ? a : b;
}

// 2. Class Template: Generic Stack
template <typename T>
class SimpleStack {
    std::vector<T> elements;
public:
    void push(const T& item) { elements.push_back(item); }
    void pop() { if (!elements.empty()) elements.pop_back(); }
    const T& top() const { return elements.back(); }
    bool empty() const { return elements.empty(); }
    size_t size() const { return elements.size(); }
};

// 3. C++17 Fold Expression (Variadic Sum)
template <typename... Args>
auto sum_values(Args... args) {
    return (... + args); // Fold expression expands to (arg1 + arg2 + ... + argN)
}

// 4. C++20 Concept constraint
template <std::integral T>
bool is_even(T number) {
    return (number % 2) == 0;
}

int main() {
    std::cout << "=== Day 24: Templates & Generic Programming ===\n\n";

    // Function template deduction
    std::cout << "get_max(42, 108):       " << get_max(42, 108) << "\n";
    std::cout << "get_max(3.14, 2.71):     " << get_max(3.14, 2.71) << "\n";
    std::cout << "get_max(string):         " << get_max(std::string("alpha"), std::string("omega")) << "\n\n";

    // Class template
    SimpleStack<std::string> stack;
    stack.push("First");
    stack.push("Second");
    stack.push("Third");
    std::cout << "Stack top: " << stack.top() << "\n";
    stack.pop();
    std::cout << "After pop, top: " << stack.top() << "\n\n";

    // Fold expression
    auto total = sum_values(1, 2, 3, 4, 5, 10);
    std::cout << "Fold expression sum_values(1,2,3,4,5,10) = " << total << "\n\n";

    // C++20 Concept
    std::cout << "is_even(14): " << std::boolalpha << is_even(14) << "\n";

    return 0;
}
