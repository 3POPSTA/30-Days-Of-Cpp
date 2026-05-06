<div align="center">
  <h1>🚀 30 Days Of C++: Day 13 - Pointers & References</h1>
  <sub>Addresses, dereferencing, const-correctness, and memory fundamentals</sub>
</div>

[<< Day 12: Headers & Namespaces](../12_Day_Headers_and_namespaces/12_headers_and_namespaces.md) | [Day 14: Dynamic Memory & Smart Pointers >>](../14_Day_Dynamic_memory_and_smart_pointers/14_dynamic_memory_and_smart_pointers.md)

---

## Table of Contents
- [The Memory Model: Addresses & Bytes](#the-memory-model-addresses--bytes)
- [References (`&`)](#references-)
- [Pointers (`*`) and Address-of Operator (`&`)](#pointers--and-address-of-operator-)
- [Dereferencing Pointers](#dereferencing-pointers)
- [Null Pointers: `nullptr`](#null-pointers-nullptr)
- [Const Correctness with Pointers](#const-correctness-with-pointers)
- [Pointer Arithmetic](#pointer-arithmetic)
- [Pointers vs References: Decision Matrix](#pointers-vs-references-decision-matrix)
- [💻 Exercises - Day 13](#-exercises---day-13)

---

## The Memory Model: Addresses & Bytes
Every variable in C++ resides at a unique location in physical/virtual RAM. You can obtain a variable's memory address using the address-of operator `&`:

```cpp
int age = 30;
std::cout << "Value: " << age << "\n";
std::cout << "Memory Address: " << &age << "\n"; // e.g. 0x7ffd5342a1bc
```

---

## References (`&`)
A reference is an alias for an existing variable:
- Must be initialized when declared.
- Cannot be reassigned (reseated) to point to another object.
- Cannot be null.

```cpp
int original = 100;
int& ref = original; // ref is another name for original
ref = 200;           // original is now 200
```

---

## Pointers (`*`)
A pointer is a variable that stores the memory address of another variable:
- Can be re-assigned to different addresses.
- Can be null (`nullptr`).
- Access the underlying value using the dereference operator `*`.

```cpp
int x = 42;
int* ptr = &x; // ptr holds address of x

std::cout << "Address: " << ptr << "\n";
std::cout << "Value via dereference: " << *ptr << "\n"; // 42

*ptr = 99; // Modifies x directly through pointer
```

---

## Const Correctness with Pointers
Read from right to left:
1. `const int* p`: Pointer to a constant integer (value cannot change through `p`).
2. `int* const p`: Constant pointer to an integer (address in `p` cannot change).
3. `const int* const p`: Constant pointer to a constant integer (neither address nor value can change).

---

## 💻 Exercises - Day 13

### Exercises: Level 1
1. Declare an integer `val = 50`. Create a pointer `pVal` pointing to it. Print `val`, `&val`, `pVal`, and `*pVal`.
2. Demonstrate how changing a value through a reference affects the original variable.
3. Declare a pointer to `nullptr`. Check if it is null before attempting to dereference it.

### Exercises: Level 2
1. Write a function `void get_min_max(const int* arr, size_t size, int* out_min, int* out_max)` that finds the minimum and maximum elements in a C-style array using pointers.
2. Demonstrate pointer arithmetic: Declare an array of 5 integers. Use a pointer to traverse and print the elements using `*(ptr + i)`.

### Exercises: Level 3
1. Implement a custom string length function `size_t custom_strlen(const char* str)` using pointer arithmetic without any library functions.
2. Implement an in-place array reversal function using two pointers (`left` and `right`) meeting in the middle.
