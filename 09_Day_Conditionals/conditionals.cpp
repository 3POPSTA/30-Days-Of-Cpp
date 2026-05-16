// Day 9: Conditionals and Flow Control
// Compile: g++ -std=c++20 -Wall -Wextra conditionals.cpp -o conditionals

#include <iostream>
#include <string>
#include <unordered_map>
#include <type_traits>

enum class OrderStatus {
    Pending,
    Processing,
    Shipped,
    Delivered,
    Cancelled
};

template <typename T>
void print_type_category(T value) {
    if constexpr (std::is_floating_point_v<T>) {
        std::cout << "[Compile-Time Decision] Floating-point value: " << value << "\n";
    } else if constexpr (std::is_integral_v<T>) {
        std::cout << "[Compile-Time Decision] Integer value: " << value << "\n";
    } else {
        std::cout << "[Compile-Time Decision] Other type\n";
    }
}

int main() {
    std::cout << "=== Day 9: Conditionals ===\n\n";

    // 1. C++17 if with initializer
    std::unordered_map<std::string, int> user_ids{{"alice", 101}, {"bob", 102}};

    if (auto it = user_ids.find("alice"); it != user_ids.end()) {
        std::cout << "Found alice with ID: " << it->second << "\n";
    } else {
        std::cout << "Alice not found.\n";
    }
    std::cout << "\n";

    // 2. Scoped enum with switch
    OrderStatus status = OrderStatus::Shipped;
    std::cout << "Order status: ";
    switch (status) {
        case OrderStatus::Pending:
            std::cout << "Awaiting confirmation.\n";
            break;
        case OrderStatus::Processing:
            std::cout << "Being packed at warehouse.\n";
            break;
        case OrderStatus::Shipped:
            std::cout << "In transit with courier.\n";
            break;
        case OrderStatus::Delivered:
            std::cout << "Delivered to recipient.\n";
            break;
        case OrderStatus::Cancelled:
            std::cout << "Order cancelled.\n";
            break;
    }
    std::cout << "\n";

    // 3. Compile-time branching with if constexpr
    print_type_category(42);
    print_type_category(3.14159);
    print_type_category("Hello C++");

    return 0;
}
