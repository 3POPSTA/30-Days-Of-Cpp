// Day 28: Modern C++ Vocabulary Types & Features
// Compile: g++ -std=c++20 -Wall -Wextra modern_cpp.cpp -o modern_cpp

#include <iostream>
#include <optional>
#include <variant>
#include <string>

// 1. [[nodiscard]] attribute
[[nodiscard]] bool allocate_network_buffer(int size) {
    std::cout << "Allocating " << size << " KB network buffer...\n";
    return true; // Success
}

// 2. std::optional
std::optional<std::string> get_config_value(const std::string& key) {
    if (key == "host") return "127.0.0.1";
    if (key == "port") return "8080";
    return std::nullopt; // Key does not exist
}

// 3. std::variant (Type-safe union)
using JsonValue = std::variant<int, double, std::string, bool>;

void print_json_value(const JsonValue& j) {
    std::visit([](const auto& val) {
        std::cout << "[JSON Primitive] " << val << "\n";
    }, j);
}

int main() {
    std::cout << "=== Day 28: Modern C++ Features ===\n\n";

    // Calling [[nodiscard]] function with result capture
    bool ok = allocate_network_buffer(1024);
    std::cout << "Allocation status: " << std::boolalpha << ok << "\n\n";

    // Optional inspection
    auto host = get_config_value("host");
    auto secret = get_config_value("api_secret");

    std::cout << "Host: " << host.value_or("localhost") << "\n";
    std::cout << "API Secret: " << secret.value_or("[NOT_CONFIGURED]") << "\n\n";

    // Variant inspection with std::visit
    std::cout << "--- Variant Values ---\n";
    JsonValue v1 = 404;
    JsonValue v2 = 98.6;
    JsonValue v3 = "Payload Accepted";
    JsonValue v4 = true;

    print_json_value(v1);
    print_json_value(v2);
    print_json_value(v3);
    print_json_value(v4);

    return 0;
}
