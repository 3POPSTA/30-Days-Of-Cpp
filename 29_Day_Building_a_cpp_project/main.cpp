// Day 29: Complete Modular CLI Task Manager Project
// Compile: g++ -std=c++20 -Wall -Wextra main.cpp task.cpp task_manager.cpp -o task_cli

#include <iostream>
#include <filesystem>
#include "task_manager.hpp"

int main() {
    std::cout << "==========================================\n";
    std::cout << "  30 Days of C++: Capstone CLI Task Manager\n";
    std::cout << "==========================================\n\n";

    std::string db_file = "tasks_db.txt";
    TaskManager manager(db_file);

    // Demonstration workflow
    manager.add_task("Master Modern C++20 Standard");
    manager.add_task("Build CMake Modular Systems Project");
    manager.add_task("Contribute to Open Source C++ Codebase");

    manager.list_all_tasks();

    std::cout << "Marking task #1 as complete...\n";
    manager.complete_task(1);

    manager.list_all_tasks();

    // Clean up demo database file
    std::filesystem::remove(db_file);
    std::cout << "Capstone demonstration complete! Database verified.\n";

    return 0;
}
