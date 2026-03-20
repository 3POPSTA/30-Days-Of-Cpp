// Day 30: Final Graduation Challenge & Mastery Verification
// Compile: g++ -std=c++20 -Wall -Wextra final_challenge.cpp -o final_challenge

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <memory>
#include <concepts>
#include <ranges>

template <std::integral T>
T compute_fibonacci(T n) {
    if (n <= 1) return n;
    T a = 0, b = 1;
    for (T i = 2; i <= n; ++i) {
        T temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int main() {
    std::cout << "====================================================\n";
    std::cout << "🏆 CONGRATULATIONS! 30 DAYS OF C++ COMPLETED! 🏆\n";
    std::cout << "====================================================\n\n";

    std::cout << "Executing Mastery Verification Suite...\n";

    // 1. Concept-constrained template execution
    int fib10 = compute_fibonacci(10);
    std::cout << "[Pass] Generic Concept Fibonacci(10): " << fib10 << "\n";

    // 2. RAII Smart Pointer verification
    auto smart_buf = std::make_unique<std::vector<int>>(std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    std::cout << "[Pass] RAII Smart Pointer buffer allocated on heap (" << smart_buf->size() << " elements)\n";

    // 3. C++20 Ranges pipeline verification
    auto even_squares = *smart_buf
        | std::views::filter([](int n) { return n % 2 == 0; })
        | std::views::transform([](int n) { return n * n; });

    std::cout << "[Pass] C++20 Ranges pipeline computed even squares: ";
    for (int v : even_squares) {
        std::cout << v << " ";
    }
    std::cout << "\n\n";

    std::cout << "You are now equipped with Modern C++ principles, RAII mastery,\n";
    std::cout << "STL proficiency, concurrency knowledge, and production architecture!\n";
    std::cout << "Happy coding! 🧡\n";

    return 0;
}
