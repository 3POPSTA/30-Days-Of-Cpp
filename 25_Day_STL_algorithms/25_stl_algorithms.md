<div align="center">
  <h1>🚀 30 Days Of C++: Day 25 - STL Algorithms & C++20 Ranges</h1>
  <sub><algorithm>, transformations, sorting, and modern pipeline views</sub>
</div>

[<< Day 24: Templates](../24_Day_Templates_and_generic_programming/24_templates_and_generic_programming.md) | [Day 26: Lambdas >>](../26_Day_Lambdas_and_functional_programming/26_lambdas_and_functional_programming.md)

---

## Table of Contents
- [The STL Architecture: Iterators decouple Containers from Algorithms](#the-stl-architecture)
- [Non-Modifying Algorithms (`find`, `count`, `all_of`)](#non-modifying-algorithms)
- [Modifying Algorithms (`transform`, `replace`, `copy`)](#modifying-algorithms)
- [Sorting & Partitioning (`sort`, `stable_sort`)](#sorting--partitioning)
- [Numeric Algorithms (`accumulate`, `reduce`)](#numeric-algorithms)
- [Modern C++20 Ranges & Views (`|` Pipe Operator)](#modern-c20-ranges--views)
- [💻 Exercises - Day 25](#-exercises---day-25)

---

## Non-Modifying Algorithms
```cpp
#include <algorithm>
#include <vector>

std::vector<int> nums{10, 25, 40, 55, 70};

// Find first matching element
auto it = std::find_if(nums.begin(), nums.end(), [](int n) { return n > 50; });

// Predicate checks
bool all_positive = std::all_of(nums.begin(), nums.end(), [](int n) { return n > 0; });
```

---

## Modifying & Transforming Algorithms
```cpp
std::vector<int> squares;
squares.reserve(nums.size());

std::transform(nums.begin(), nums.end(), std::back_inserter(squares),
               [](int x) { return x * x; });
```

---

## Modern C++20 Ranges & Views
Instead of passing pairs of iterators (`begin()`, `end()`), C++20 Ranges operate directly on containers and allow lazy, composable pipelines with the pipe operator `|`:

```cpp
#include <ranges>

auto result = nums
    | std::views::filter([](int n) { return n % 2 == 0; })
    | std::views::transform([](int n) { return n * 10; });
```

---

## 💻 Exercises - Day 25

### Exercises: Level 1
1. Given a vector `{15, 3, 99, 42, 8, 27}`, sort it in ascending order with `std::sort`, then in descending order using `std::greater<int>()`.
2. Count how many strings in a vector have a length greater than 5 characters using `std::count_if`.
3. Compute the sum and product of all numbers in a vector using `std::accumulate` (`<numeric>`).

### Exercises: Level 2
1. Transform a vector of Celsius temperatures to Fahrenheit using `std::transform` and store the result in a new vector.
2. Binary Search: Verify if a number exists in a sorted vector using `std::binary_search`, and find its exact insertion index using `std::lower_bound`.

### Exercises: Level 3
1. C++20 Ranges Pipeline: Given a list of integers from 1 to 100, use `std::views::filter`, `std::views::transform`, and `std::views::take` to extract the squares of the first 10 even numbers.
2. Read `data/countries_data.json` or create a country list struct, and sort countries by population in descending order using `std::sort` with a custom lambda comparator.
