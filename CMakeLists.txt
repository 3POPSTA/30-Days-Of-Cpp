cmake_minimum_required(VERSION 3.20)
project(ThirtyDaysOfCpp VERSION 1.0.0 LANGUAGES CXX)

# Enforce Modern C++20 Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compiler Warnings Configuration
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
elseif (MSVC)
    add_compile_options(/W4 /EHsc)
endif()

# Day 01 - Introduction
add_executable(day01 01_Day_Introduction/helloworld.cpp)

# Day 02 - Variables and Data Types
add_executable(day02 02_Day_Variables_and_data_types/variables.cpp)

# Day 03 - Operators
add_executable(day03 03_Day_Operators/operators.cpp)

# Day 04 - Strings
add_executable(day04 04_Day_Strings/strings.cpp)

# Day 05 - Arrays and Vectors
add_executable(day05 05_Day_Arrays_and_vectors/vectors.cpp)

# Day 06 - Pairs and Tuples
add_executable(day06 06_Day_Pairs_and_tuples/tuples.cpp)

# Day 07 - Sets
add_executable(day07 07_Day_Sets/sets.cpp)

# Day 08 - Maps and Dictionaries
add_executable(day08 08_Day_Maps_and_dictionaries/maps.cpp)

# Day 09 - Conditionals
add_executable(day09 09_Day_Conditionals/conditionals.cpp)

# Day 10 - Loops
add_executable(day10 10_Day_Loops/loops.cpp)

# Day 11 - Functions
add_executable(day11 11_Day_Functions/functions.cpp)

# Day 12 - Headers and Namespaces
add_executable(day12 
    12_Day_Headers_and_namespaces/main.cpp 
    12_Day_Headers_and_namespaces/math_utils.cpp
)
target_include_directories(day12 PRIVATE 12_Day_Headers_and_namespaces)

# Day 13 - Pointers and References
add_executable(day13 13_Day_Pointers_and_references/pointers.cpp)

# Day 14 - Dynamic Memory & Smart Pointers
add_executable(day14 14_Day_Dynamic_memory_and_smart_pointers/smart_pointers.cpp)

# Day 15 - Errors and Debugging
add_executable(day15 15_Day_Errors_and_debugging/debugging.cpp)

# Day 16 - Chrono and Date Time
add_executable(day16 16_Day_Chrono_and_datetime/chrono_datetime.cpp)

# Day 17 - Exception Handling
add_executable(day17 17_Day_Exception_handling/exceptions.cpp)

# Day 18 - Regular Expressions
add_executable(day18 18_Day_Regular_expressions/regular_expressions.cpp)

# Day 19 - File Handling
add_executable(day19 19_Day_File_handling/file_handling.cpp)

# Day 20 - Build Systems & CMake
add_executable(day20 20_Day_Build_systems_and_cmake/main.cpp)

# Day 21 - Classes and Objects
add_executable(day21 21_Day_Classes_and_objects/classes.cpp)

# Day 22 - Inheritance and Polymorphism
add_executable(day22 22_Day_Inheritance_and_polymorphism/polymorphism.cpp)

# Day 23 - Operator Overloading & Move Semantics
add_executable(day23 23_Day_Operator_overloading_and_move_semantics/move_semantics.cpp)

# Day 24 - Templates and Generic Programming
add_executable(day24 24_Day_Templates_and_generic_programming/templates.cpp)

# Day 25 - STL Algorithms
add_executable(day25 25_Day_STL_algorithms/algorithms.cpp)

# Day 26 - Lambdas and Functional Programming
add_executable(day26 26_Day_Lambdas_and_functional_programming/lambdas.cpp)

# Day 27 - Concurrency and Multithreading
find_package(Threads REQUIRED)
add_executable(day27 27_Day_Concurrency_and_multithreading/concurrency.cpp)
target_link_libraries(day27 PRIVATE Threads::Threads)

# Day 28 - Modern C++ Features
add_executable(day28 28_Day_Modern_cpp_features/modern_cpp.cpp)

# Day 29 - Capstone CLI Task Manager
add_executable(day29 
    29_Day_Building_a_cpp_project/main.cpp 
    29_Day_Building_a_cpp_project/task.cpp 
    29_Day_Building_a_cpp_project/task_manager.cpp
)
target_include_directories(day29 PRIVATE 29_Day_Building_a_cpp_project)

# Day 30 - Final Challenge & Verification
add_executable(day30 30_Day_Conclusions/final_challenge.cpp)

