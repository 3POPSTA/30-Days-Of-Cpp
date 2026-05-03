// Day 14: Dynamic Memory and Modern Smart Pointers
// Compile: g++ -std=c++20 -Wall -Wextra smart_pointers.cpp -o smart_pointers

#include <iostream>
#include <memory>
#include <string>

struct Resource {
    std::string name;
    explicit Resource(std::string n) : name(std::move(n)) {
        std::cout << "[Resource Acquired] " << name << "\n";
    }
    ~Resource() {
        std::cout << "[Resource Destroyed] " << name << "\n";
    }
    void do_work() const {
        std::cout << "Resource " << name << " is working.\n";
    }
};

int main() {
    std::cout << "=== Day 14: Smart Pointers ===\n\n";

    // 1. std::unique_ptr (RAII in action)
    std::cout << "--- Unique Pointer Demo ---\n";
    {
        auto u_res = std::make_unique<Resource>("Database Connection");
        u_res->do_work();
        // Ownership transfer via std::move
        auto transferred = std::move(u_res);
        if (!u_res) {
            std::cout << "u_res is now null after std::move!\n";
        }
        transferred->do_work();
    } // 'transferred' goes out of scope here -> Destructor called!
    std::cout << "\n";

    // 2. std::shared_ptr and reference counting
    std::cout << "--- Shared Pointer Demo ---\n";
    std::shared_ptr<Resource> p1 = std::make_shared<Resource>("Audio Engine");
    std::cout << "Initial use count: " << p1.use_count() << "\n";
    {
        std::shared_ptr<Resource> p2 = p1; // Shared ownership
        std::cout << "Inner scope use count: " << p1.use_count() << "\n";
        p2->do_work();
    } // p2 destroyed, ref count drops to 1
    std::cout << "Back to outer scope, use count: " << p1.use_count() << "\n";

    return 0;
}
