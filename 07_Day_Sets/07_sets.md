<div align="center">
  <h1>🚀 30 Days Of C++: Day 7 - Sets & Multisets</h1>
  <sub>std::set, std::unordered_set, mathematical operations, and hashing</sub>
</div>

[<< Day 6: Pairs & Tuples](../06_Day_Pairs_and_tuples/06_pairs_and_tuples.md) | [Day 8: Maps & Dictionaries >>](../08_Day_Maps_and_dictionaries/08_maps_and_dictionaries.md)

---

## Table of Contents
- [Ordered Set: `std::set`](#ordered-set-stdset)
- [Unordered Set: `std::unordered_set`](#unordered-set-stdunordered_set)
- [Multisets: `std::multiset`](#multisets-stdmultiset)
- [Set Operations: Insert, Erase, Find, Contains](#set-operations-insert-erase-find-contains)
- [Mathematical Set Operations](#mathematical-set-operations)
- [Performance & Time Complexity](#performance--time-complexity)
- [💻 Exercises - Day 7](#-exercises---day-7)

---

## Ordered Set: `std::set`
Defined in `<set>`, `std::set<T>` is an associative container that contains a sorted set of unique objects of type `T`. It is typically implemented as a Red-Black Tree (Self-balancing Binary Search Tree):
- Elements are always **sorted** in ascending order.
- No duplicate values allowed.
- Search, insertion, and removal have **$O(\log n)$** time complexity.

```cpp
#include <set>
std::set<int> unique_nums{5, 2, 8, 2, 5, 1};
// Stored internally as: 1, 2, 5, 8
```

---

## Unordered Set: `std::unordered_set`
Defined in `<unordered_set>`, `std::unordered_set<T>` uses an internal hash table:
- Elements are **not sorted**.
- Average insertion, lookup, and removal time is **$O(1)$**.
- Requires type `T` to have a hash function (`std::hash<T>`) and equality operator (`==`).

---

## Multisets: `std::multiset`
If you need sorted elements that permit duplicates, use `std::multiset<T>`:
```cpp
#include <set>
std::multiset<int> scores{90, 80, 90, 100}; // Allows both 90s
```

---

## Set Operations: Insert, Erase, Find, Contains
- `insert(val)`: Returns `std::pair<iterator, bool>` indicating success.
- `contains(val)` (C++20): Clean boolean check if element exists.
- `erase(val)`: Removes element.
- `find(val)`: Returns iterator to element, or `end()` if missing.

```cpp
std::set<std::string> tags{"cpp", "coding", "performance"};
if (tags.contains("cpp")) { // C++20
    std::cout << "Found tag!\n";
}
```

---

## Mathematical Set Operations
With `<algorithm>` and `<iterator>`, you can compute set theory operations:
- `std::set_union`: Union ($A \cup B$)
- `std::set_intersection`: Intersection ($A \cap B$)
- `std::set_difference`: Difference ($A \setminus B$)
- `std::set_symmetric_difference`: Symmetric Difference ($A \triangle B$)

---

## 💻 Exercises - Day 7

### Exercises: Level 1
1. Create a `std::set<std::string>` with 6 company names, including 2 duplicates. Print the size and verify duplicates were filtered.
2. Given a vector `{4, 1, 8, 4, 2, 8, 3, 1, 9}`, use `std::set` to remove all duplicates and print the remaining sorted numbers.
3. Check whether `"Alice"` exists in a `std::unordered_set<std::string>` using `.contains()` (C++20).

### Exercises: Level 2
1. Write a program that takes two sets of integers: $A = \{1, 2, 3, 4, 5\}$ and $B = \{4, 5, 6, 7, 8\}$. Compute and print:
   - Union of $A$ and $B$
   - Intersection of $A$ and $B$
   - Difference $A - B$
2. Given an english sentence, extract all unique words in alphabetical order using `std::stringstream` and `std::set<std::string>`.

### Exercises: Level 3
1. Implement a spelling checker using `std::unordered_set<std::string>` as a dictionary. Load a list of valid words, then check a paragraph and print any misspelled words.
2. Measure the lookup time difference between `std::set` and `std::unordered_set` for 100,000 integers using `<chrono>`.
