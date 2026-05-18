// Day 8: Maps and Dictionaries in Modern C++
// Compile: g++ -std=c++20 -Wall -Wextra maps.cpp -o maps

#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <sstream>

int main() {
    std::cout << "=== Day 8: Maps & Dictionaries ===\n\n";

    // 1. std::map (Sorted by key)
    std::map<std::string, double> book_prices{
        {"Clean Code", 38.99},
        {"The C++ Programming Language", 59.95},
        {"Effective Modern C++", 44.50}
    };

    std::cout << "--- Book Catalog (Sorted alphabetically by key) ---\n";
    for (const auto& [title, price] : book_prices) {
        std::cout << "• " << title << " -> $" << price << "\n";
    }
    std::cout << "\n";

    // 2. Safe access with .at() vs operator[]
    try {
        std::cout << "Price of 'Clean Code': $" << book_prices.at("Clean Code") << "\n";
        [[maybe_unused]] double missing = book_prices.at("Design Patterns");
    } catch (const std::out_of_range& e) {
        std::cout << "Caught expected error: 'Design Patterns' is not in catalog.\n\n";
    }

    // 3. std::unordered_map: Word Frequency Counter
    std::string text = "learn cpp because cpp is fast and cpp is powerful";
    std::unordered_map<std::string, int> word_counts;

    std::stringstream ss(text);
    std::string word;
    while (ss >> word) {
        word_counts[word]++;
    }

    std::cout << "--- Word Frequency Counter ---\n";
    for (const auto& [w, count] : word_counts) {
        std::cout << "'" << w << "': " << count << "\n";
    }

    return 0;
}
