// Day 7: Sets, Multisets, and Set Algorithms
// Compile: g++ -std=c++20 -Wall -Wextra sets.cpp -o sets

#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <iterator>

int main() {
    std::cout << "=== Day 7: Sets & Multisets ===\n\n";

    // 1. std::set (Sorted & Unique)
    std::set<int> ordered_set{42, 10, 88, 10, 5, 42};
    std::cout << "std::set (automatically sorted and deduplicated):\n";
    for (int x : ordered_set) {
        std::cout << x << " ";
    }
    std::cout << "\n\n";

    // 2. std::unordered_set (Hash table, average O(1) lookup)
    std::unordered_set<std::string> users{"alice", "bob", "charlie"};
    users.insert("dave");

    // C++20 .contains()
    if (users.contains("bob")) {
        std::cout << "User 'bob' is registered.\n";
    }
    if (!users.contains("eve")) {
        std::cout << "User 'eve' is NOT registered.\n\n";
    }

    // 3. std::multiset (Allows duplicates, keeps sorted order)
    std::multiset<int> exam_grades{85, 92, 85, 74, 92, 100};
    std::cout << "Multiset: ";
    for (int g : exam_grades) {
        std::cout << g << " ";
    }
    std::cout << "\nNumber of students who scored 85: " << exam_grades.count(85) << "\n\n";

    // 4. Mathematical Set Operations (Intersection & Union)
    std::set<int> setA{1, 2, 3, 4, 5};
    std::set<int> setB{4, 5, 6, 7, 8};

    std::vector<int> intersection_result;
    std::set_intersection(
        setA.begin(), setA.end(),
        setB.begin(), setB.end(),
        std::back_inserter(intersection_result)
    );

    std::cout << "Intersection of SetA and SetB: ";
    for (int val : intersection_result) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    return 0;
}
