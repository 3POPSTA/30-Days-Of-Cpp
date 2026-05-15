<div align="center">
  <h1>🚀 30 Days Of C++: Day 10 - Loops & Iteration</h1>
  <sub>for, range-based for, while, do-while, and iterator mechanics</sub>
</div>

[<< Day 9: Conditionals](../09_Day_Conditionals/09_conditionals.md) | [Day 11: Functions >>](../11_Day_Functions/11_functions.md)

---

## Table of Contents
- [Traditional `for` Loops](#traditional-for-loops)
- [Modern Range-Based `for` Loops](#modern-range-based-for-loops)
  - [By-Value vs By-Reference vs Const-Reference](#by-value-vs-by-reference-vs-const-reference)
- [The `while` and `do-while` Loops](#the-while-and-do-while-loops)
- [Loop Control: `break` and `continue`](#loop-control-break-and-continue)
- [Under the Hood: Iterators](#under-the-hood-iterators)
- [💻 Exercises - Day 10](#-exercises---day-10)

---

## Traditional `for` Loops
Standard counter-based loop:
```cpp
for (int i = 0; i < 5; ++i) {
    std::cout << "i = " << i << "\n";
}
```

---

## Modern Range-Based `for` Loops
Introduced in C++11, range-for iterates cleanly over any sequence or container:

```cpp
std::vector<int> nums{1, 2, 3, 4, 5};

// 1. By-value: copies each element (use only for cheap primitive types)
for (auto x : nums) { ... }

// 2. By-reference: modifies elements in-place!
for (auto& x : nums) { x *= 2; }

// 3. By const-reference: avoids copying, read-only (RECOMMENDED for objects & strings)
for (const auto& x : nums) { std::cout << x << "\n"; }
```

---

## The `while` and `do-while` Loops
- `while`: Evaluates condition **before** entering loop body.
- `do-while`: Executes body at least **once** before checking condition.

```cpp
int attempts = 0;
do {
    std::cout << "Attempt: " << ++attempts << "\n";
} while (attempts < 3);
```

---

## Under the Hood: Iterators
Range-for compiles down to iterator traversal:
```cpp
for (auto it = nums.begin(); it != nums.end(); ++it) {
    std::cout << *it << "\n"; // Dereference iterator
}
```

---

## 💻 Exercises - Day 10

### Exercises: Level 1
1. Print numbers from 0 to 10 using a `for` loop, a `while` loop, and a `do-while` loop.
2. Print the multiplication table for number 7 (from 7 x 1 to 7 x 10).
3. Sum all even numbers between 1 and 100 using a loop.

### Exercises: Level 2
1. Write a program that prints an inverted right triangle pattern of stars (`*`) of height $N$.
2. Given a `std::vector<int>`, double every element using a range-based `for` loop with a mutable reference `auto&`.
3. Prime Number Checker: Write a loop to determine if a given number $N$ is prime.

### Exercises: Level 3
1. Implement the Fibonacci sequence up to $N$ terms using a loop.
2. Reverse a `std::vector<std::string>` in place using two-pointer index loop without using `std::reverse`.
