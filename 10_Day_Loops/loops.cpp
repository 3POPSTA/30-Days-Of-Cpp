// Day 10: Loops and Iteration Patterns
// Compile: g++ -std=c++20 -Wall -Wextra loops.cpp -o loops

#include <iostream>
#include <vector>
#include <string>

int main() {
    std::cout << "=== Day 10: Loops ===\n\n";

    // 1. Traditional for loop with prefix ++i
    std::cout << "Counting: ";
    for (int i = 1; i <= 5; ++i) {
        std::cout << i << " ";
    }
    std::cout << "\n\n";

    // 2. Range-based for: mutating via reference (auto&)
    std::vector<int> numbers{1, 2, 3, 4, 5};
    for (auto& num : numbers) {
        num *= 10; // Multiply each element in-place
    }

    // Range-based for: read-only via const auto&
    std::cout << "Mutated numbers: ";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n\n";

    // 3. while loop with loop control (break / continue)
    std::cout << "Odds between 1 and 10: ";
    int counter = 0;
    while (counter < 10) {
        ++counter;
        if (counter % 2 == 0) {
            continue; // Skip evens
        }
        std::cout << counter << " ";
    }
    std::cout << "\n\n";

    // 4. Reverse iterators
    std::vector<std::string> words{"C++", "is", "wildly", "fast"};
    std::cout << "Traversing backwards with rbegin/rend: ";
    for (auto it = words.rbegin(); it != words.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    return 0;
}
