// Day 25: STL Algorithms and C++20 Ranges
// Compile: g++ -std=c++20 -Wall -Wextra algorithms.cpp -o algorithms

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ranges>
#include <string>

int main() {
    std::cout << "=== Day 25: STL Algorithms & Ranges ===\n\n";

    std::vector<int> numbers{45, 12, 89, 34, 7, 63, 28, 91, 16};

    // 1. Sorting
    std::sort(numbers.begin(), numbers.end());
    std::cout << "Sorted: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << "\n\n";

    // 2. std::accumulate (Summation)
    long long sum = std::accumulate(numbers.begin(), numbers.end(), 0LL);
    std::cout << "Sum: " << sum << "\n";
    std::cout << "Average: " << static_cast<double>(sum) / numbers.size() << "\n\n";

    // 3. std::count_if
    long evens_count = std::count_if(numbers.begin(), numbers.end(), [](int n) {
        return (n % 2) == 0;
    });
    std::cout << "Count of even numbers: " << evens_count << "\n\n";

    // 4. std::transform (in-place squaring)
    std::vector<int> squared;
    squared.reserve(numbers.size());
    std::transform(numbers.begin(), numbers.end(), std::back_inserter(squared), [](int x) {
        return x * x;
    });

    std::cout << "Squares of elements: ";
    for (int s : squared) std::cout << s << " ";
    std::cout << "\n\n";

    // 5. C++20 Ranges & Views Pipeline
    std::cout << "--- C++20 Ranges Pipeline ---\n";
    std::cout << "Even numbers transformed (multiplied by 10):\n";
    auto even_view = numbers
        | std::views::filter([](int n) { return n % 2 == 0; })
        | std::views::transform([](int n) { return n * 10; });

    for (int n : even_view) {
        std::cout << n << " ";
    }
    std::cout << "\n";

    return 0;
}
