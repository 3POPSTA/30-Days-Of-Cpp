// Day 4: Strings and String Views in C++
// Compile: g++ -std=c++20 -Wall -Wextra strings.cpp -o strings

#include <iostream>
#include <string>
#include <string_view>
#include <sstream>
#include <cctype>

void inspect_string_view(std::string_view sv) {
    std::cout << "[Zero-Copy View] '" << sv << "' (Length: " << sv.length() << ")\n";
}

int main() {
    std::cout << "=== Day 4: Strings & String Views ===\n\n";

    // 1. String construction & manipulation
    std::string text = "Modern C++ Programming";
    std::cout << "Original: " << text << "\n";
    std::cout << "Length:   " << text.length() << "\n";
    std::cout << "Substr:   " << text.substr(7, 3) << "\n"; // "C++"

    // 2. Searching
    size_t pos = text.find("Programming");
    if (pos != std::string::npos) {
        std::cout << "'Programming' found at index: " << pos << "\n";
    }

    // 3. Modifying
    text.replace(0, 6, "Mastering"); // Replace "Modern" with "Mastering"
    std::cout << "Replaced: " << text << "\n\n";

    // 4. std::string_view (C++17) - Zero allocations
    std::string large_string = "High performance zero-overhead strings";
    inspect_string_view(large_string);
    inspect_string_view("Direct literal string"); // Also works without creating std::string!

    // 5. Stringstream parsing
    std::cout << "\n--- Stringstream Parsing ---\n";
    std::string csv_record = "SensorA,23.5,1013";
    std::stringstream ss(csv_record);
    std::string sensor_name;
    double temp;
    int pressure;

    std::getline(ss, sensor_name, ',');
    std::string temp_str, pres_str;
    std::getline(ss, temp_str, ',');
    std::getline(ss, pres_str, ',');

    temp = std::stod(temp_str);
    pressure = std::stoi(pres_str);

    std::cout << "Sensor:   " << sensor_name << "\n";
    std::cout << "Temp:     " << temp << " C\n";
    std::cout << "Pressure: " << pressure << " hPa\n";

    return 0;
}
