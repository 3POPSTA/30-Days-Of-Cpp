<div align="center">
  <h1>🚀 30 Days Of C++: Day 6 - Pairs, Tuples & Structured Bindings</h1>
  <sub>std::pair, std::tuple, and modern C++17 structured bindings</sub>
</div>

[<< Day 5: Arrays & Vectors](../05_Day_Arrays_and_vectors/05_arrays_and_vectors.md) | [Day 7: Sets >>](../07_Day_Sets/07_sets.md)

---

## Table of Contents
- [Pairs (`std::pair`)](#pairs-stdpair)
- [Tuples (`std::tuple`)](#tuples-stdtuple)
- [Accessing Elements: `std::get`](#accessing-elements-stdget)
- [C++17 Structured Bindings](#c17-structured-bindings)
- [Unpacking with `std::tie` & `std::ignore`](#unpacking-with-stdtie--stdignore)
- [Returning Multiple Values from Functions](#returning-multiple-values-from-functions)
- [💻 Exercises - Day 6](#-exercises---day-6)

---

## Pairs (`std::pair`)
Defined in `<utility>`, `std::pair<T1, T2>` couples two heterogeneous values:

```cpp
#include <utility>
#include <string>

std::pair<std::string, int> user{"Alice", 30};
std::cout << "Name: " << user.first << ", Age: " << user.second << "\n";

// Construction helper
auto p = std::make_pair("Score", 99.5);
```

---

## Tuples (`std::tuple`)
Defined in `<tuple>`, `std::tuple<Types...>` generalizes `std::pair` to hold any number of heterogeneous elements:

```cpp
#include <tuple>
#include <string>

// A tuple holding string (name), int (id), double (gpa)
std::tuple<std::string, int, double> student{"Bob", 101, 3.85};
```

---

## Accessing Elements: `std::get`
Tuple elements are indexed at compile-time using `std::get<Index>`:

```cpp
std::string name = std::get<0>(student);
int id = std::get<1>(student);
double gpa = std::get<2>(student);

// Can also access by unique type:
double also_gpa = std::get<double>(student);
```

---

## C++17 Structured Bindings
Structured bindings make working with pairs and tuples exceptionally clean:

```cpp
auto [name, id, gpa] = student;
std::cout << name << " (ID: " << id << ") has GPA: " << gpa << "\n";
```

---

## Returning Multiple Values from Functions
```cpp
std::tuple<int, int, double> compute_stats(const std::vector<int>& data) {
    int min_val = 10, max_val = 50;
    double avg = 30.0;
    return {min_val, max_val, avg};
}

int main() {
    auto [min_val, max_val, avg] = compute_stats({10, 20, 30, 40, 50});
}
```

---

## 💻 Exercises - Day 6

### Exercises: Level 1
1. Create a `std::pair<std::string, double>` to store the name of a city and its current temperature. Print both members using `.first` and `.second`.
2. Create a `std::tuple<std::string, int, std::string, bool>` storing book details (Title, Pages, ISBN, Available). Access each field using `std::get<I>()`.
3. Use C++17 structured bindings to unpack the book tuple from Exercise 2 into meaningful variable names.

### Exercises: Level 2
1. Write a function `divide_with_remainder(int numerator, int denominator)` that returns a `std::pair<int, int>` containing quotient and remainder. Handle division by zero.
2. Write a function `find_min_max(const std::vector<int>& numbers)` that returns a `std::pair<int, int>` containing both minimum and maximum values.
3. Use `std::tie` and `std::ignore` to extract only the name and GPA from a student tuple while ignoring the ID.

### Exercises: Level 3
1. Create a coordinate system program using a vector of `std::tuple<std::string, double, double, double>` (Location Name, X, Y, Z). Write a function to calculate the Euclidean distance between any two locations.
2. Implement a database record simulator using `std::vector<std::tuple<int, std::string, double>>` (ID, Name, Salary). Sort the records in descending order of salary using structured bindings and `std::sort`.
