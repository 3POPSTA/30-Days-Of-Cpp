<div align="center">
  <h1>🚀 30 Days Of C++: Day 8 - Maps & Hash Tables</h1>
  <sub>std::map, std::unordered_map, key-value lookup, and structured bindings</sub>
</div>

[<< Day 7: Sets](../07_Day_Sets/07_sets.md) | [Day 9: Conditionals >>](../09_Day_Conditionals/09_conditionals.md)

---

## Table of Contents
- [Ordered Map: `std::map`](#ordered-map-stdmap)
- [Unordered Hash Map: `std::unordered_map`](#unordered-hash-map-stdunordered_map)
- [Inserting & Accessing Elements](#inserting--accessing-elements)
  - [`operator[]` vs `.at()`](#operator-vs-at)
- [C++17 `insert_or_assign` and `try_emplace`](#c17-insert_or_assign-and-try_emplace)
- [Iterating with Structured Bindings](#iterating-with-structured-bindings)
- [Multimaps (`std::multimap`)](#multimaps-stdmultimap)
- [💻 Exercises - Day 8](#-exercises---day-8)

---

## Ordered Map: `std::map`
Defined in `<map>`, `std::map<Key, Value>` stores unique key-value pairs sorted by key:
- Implemented as a Red-Black Tree.
- Insertion, search, removal time: **$O(\log n)$**.

```cpp
#include <map>
#include <string>

std::map<std::string, int> populations;
populations["Tokyo"] = 37400000;
populations["Delhi"] = 32900000;
```

---

## Unordered Hash Map: `std::unordered_map`
Defined in `<unordered_map>`, `std::unordered_map<Key, Value>` is a hash table:
- Elements are not sorted.
- Average lookup and insertion time: **$O(1)$**.
- Ideal when fast key lookup is the primary requirement.

---

## Inserting & Accessing Elements

### `operator[]` vs `.at()`
```cpp
std::map<std::string, double> prices{{"apple", 1.50}, {"banana", 0.75}};

// operator[] inserts default value (0.0) if key doesn't exist!
double p1 = prices["orange"]; // "orange" added with value 0.0

// .at() throws std::out_of_range if key doesn't exist (SAFE FOR LOOKUPS):
try {
    double p2 = prices.at("mango");
} catch (const std::out_of_range& e) {
    std::cout << "Key not found!\n";
}
```

---

## Iterating with Structured Bindings
```cpp
for (const auto& [item, price] : prices) {
    std::cout << item << " costs $" << price << "\n";
}
```

---

## 💻 Exercises - Day 8

### Exercises: Level 1
1. Create a `std::map<std::string, std::string>` representing a country-to-capital dictionary with 5 countries. Print all pairs.
2. Given a `std::unordered_map<std::string, int>` of stock inventory, use `.contains()` (C++20) to check if `"laptop"` is in stock.
3. Demonstrate why using `operator[]` on a non-existent key can accidentally mutate the map, and write the safe alternative using `.find()` or `.at()`.

### Exercises: Level 2
1. Word Frequency Counter: Write a program that reads a paragraph and uses `std::unordered_map<std::string, int>` to count how many times each word appears.
2. Phonebook Directory: Implement an interactive phonebook using `std::map<std::string, std::string>` supporting:
   - Add contact
   - Search by contact name
   - Delete contact
   - Display all contacts in alphabetical order

### Exercises: Level 3
1. Implement a student grading registry:
   Use `std::map<std::string, std::vector<int>>` where each student has a list of test scores. Compute each student's average score and find the class valedictorian.
2. Cache with eviction: Implement a simple Least Frequently Used (LFU) counter using `std::unordered_map`.
