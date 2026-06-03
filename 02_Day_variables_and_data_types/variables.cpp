// Day 2: Variables, Built-in Data Types, and Basic I/O
// Compile: g++ -std=c++20 -Wall -Wextra variables.cpp -o variables

#include <iostream>
#include <string>
#include <limits>
#include <cstdint>

int main() {
    std::cout << "=== Day 2: Variables & Data Types ===\n\n";

    // 1. Primitive data types with modern brace initialization
    int age{28};
    double hourly_rate{45.50};
    char grade{'A'};
    bool is_student{false};
    std::string full_name{"Ada Lovelace"};

    std::cout << "Name: " << full_name << "\n";
    std::cout << "Age: " << age << "\n";
    std::cout << "Rate: $" << hourly_rate << "/hr\n";
    std::cout << "Grade: " << grade << "\n";
    std::cout << "Is student: " << std::boolalpha << is_student << "\n\n";

    // 2. Memory sizes (bytes)
    std::cout << "--- Memory Footprints ---\n";
    std::cout << "sizeof(bool):        " << sizeof(bool) << " byte\n";
    std::cout << "sizeof(char):        " << sizeof(char) << " byte\n";
    std::cout << "sizeof(int):         " << sizeof(int) << " bytes\n";
    std::cout << "sizeof(double):      " << sizeof(double) << " bytes\n";
    std::cout << "sizeof(std::string): " << sizeof(std::string) << " bytes\n\n";

    // 3. Fixed-width integer types (<cstdint>)
    int32_t account_id{100249};
    uint64_t large_counter{18446744073709551615ULL};
    std::cout << "account_id (int32_t):   " << account_id << "\n";
    std::cout << "counter (uint64_t max): " << large_counter << "\n\n";

    // 4. Limits
    std::cout << "--- Numeric Limits ---\n";
    std::cout << "int min: " << std::numeric_limits<int>::min() << "\n";
    std::cout << "int max: " << std::numeric_limits<int>::max() << "\n";
    std::cout << "double max: " << std::numeric_limits<double>::max() << "\n\n";

    // 5. Const & Constexpr
    const double TAX_RATE{0.075};
    constexpr int DAYS_IN_WEEK{7};
    std::cout << "TAX_RATE (const): " << TAX_RATE << "\n";
    std::cout << "DAYS_IN_WEEK (constexpr): " << DAYS_IN_WEEK << "\n\n";

    // 6. Safe explicit casting with static_cast
    double pi_precise{3.14159265};
    int pi_truncated = static_cast<int>(pi_precise);
    std::cout << "Original double: " << pi_precise << ", Truncated int: " << pi_truncated << "\n";

    return 0;
}
