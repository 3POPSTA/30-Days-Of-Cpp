<div align="center">
  <h1>🚀 30 Days Of C++: Day 5 - Arrays & Vectors</h1>
  <sub>C-arrays, std::array, dynamic contiguous storage with std::vector</sub>
</div>

[<< Day 4: Strings](../04_Day_Strings/04_strings.md) | [Day 6: Pairs & Tuples >>](../06_Day_Pairs_and_tuples/06_pairs_and_tuples.md)

---

## Table of Contents
- [Fixed-Size Arrays: C-Arrays vs `std::array`](#fixed-size-arrays-c-arrays-vs-stdarray)
- [Dynamic Contiguous Arrays: `std::vector`](#dynamic-contiguous-arrays-stdvector)
- [Vector Memory: Size vs Capacity](#vector-memory-size-vs-capacity)
- [Adding & Removing Elements](#adding--removing-elements)
- [Element Access & Bounds Checking](#element-access--bounds-checking)
- [Traversing Vectors (Iterators, Range-For)](#traversing-vectors-iterators-range-for)
- [Multidimensional Vectors](#multidimensional-vectors)
- [💻 Exercises - Day 5](#-exercises---day-5)

---

## Fixed-Size Arrays: C-Arrays vs `std::array`
Fixed-size arrays allocate memory on the stack:
- **C-Style Array**: `int arr[5] = {1, 2, 3, 4, 5};` (decays to pointer, does not know its own size, unsafe).
- **`std::array<T, N>`** (`#include <array>`): A zero-overhead wrapper over C-arrays that supports `.size()`, bounds checking `.at()`, and STL iterators:

```cpp
#include <array>
std::array<int, 5> numbers{10, 20, 30, 40, 50};
std::cout << "Size: " << numbers.size() << "\n";
```

---

## Dynamic Contiguous Arrays: `std::vector`
`std::vector<T>` (`#include <vector>`) is the workhorse container of C++. It holds elements contiguously in dynamically allocated heap memory and grows automatically as items are added.

```cpp
#include <vector>

std::vector<int> scores = {98, 85, 92};
scores.push_back(100); // Appends element
```

---

## Vector Memory: Size vs Capacity
- `size()`: Number of elements currently stored.
- `capacity()`: Total elements the vector can hold before needing to reallocate its internal buffer.
- `reserve(N)`: Pre-allocates memory for $N$ elements to avoid expensive reallocations.

```cpp
std::vector<int> v;
v.reserve(1000); // Allocates capacity for 1000 ints upfront!
```

---

## Adding & Removing Elements
- `push_back(val)`: Copies/moves element to back.
- `emplace_back(args...)`: Constructs element directly in place (avoids unnecessary temporary copies).
- `pop_back()`: Removes last element.
- `insert(pos, val)`: Inserts element at iterator position.
- `erase(pos)`: Removes element at iterator position.
- `clear()`: Removes all elements.

---

## Traversing Vectors
```cpp
std::vector<std::string> fruits{"Apple", "Banana", "Cherry"};

// Range-based for loop (preferred for read-only)
for (const auto& fruit : fruits) {
    std::cout << fruit << " ";
}
std::cout << "\n";
```

---

## 💻 Exercises - Day 5

### Exercises: Level 1
1. Declare an empty `std::vector<int>`. Add numbers from 1 to 10 using `push_back()`. Print its `size()` and `capacity()`.
2. Declare a `std::array<std::string, 5>` holding 5 programming languages. Print the first and last element.
3. Given a vector of integers `{5, 12, 9, 3, 21, 15}`, compute the sum, average, minimum, and maximum.

### Exercises: Level 2
1. Write a function `remove_duplicates(std::vector<int>& vec)` that removes duplicate adjacent elements.
2. Implement a program that prompts the user to input integers until they enter `-1`, stores them in a vector, and prints the numbers in reverse order.
3. Write a function that checks if a vector is sorted in ascending order.

### Exercises: Level 3
1. Matrix multiplication: Create a 2D vector `std::vector<std::vector<int>>` representing two 3x3 matrices. Compute their matrix product.
2. Dynamic sizing experiment: Create an empty vector, and in a loop from 1 to 100, push integers. Print every time `capacity()` changes to observe the growth factor.
