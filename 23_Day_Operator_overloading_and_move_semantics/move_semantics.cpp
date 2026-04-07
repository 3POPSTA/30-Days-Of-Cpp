// Day 23: Operator Overloading and Move Semantics (Rule of Five)
// Compile: g++ -std=c++20 -Wall -Wextra move_semantics.cpp -o move_semantics

#include <iostream>
#include <utility>
#include <cstring>

class DynamicString {
private:
    char* data;
    size_t length;

public:
    // 1. Parameterized Constructor
    explicit DynamicString(const char* str = "") {
        length = std::strlen(str);
        data = new char[length + 1];
        std::strcpy(data, str);
        std::cout << "[Constructed] '" << data << "'\n";
    }

    // 2. Destructor
    ~DynamicString() {
        if (data) {
            std::cout << "[Destroyed] '" << data << "'\n";
            delete[] data;
        }
    }

    // 3. Copy Constructor (Deep Copy)
    DynamicString(const DynamicString& other) : length(other.length) {
        data = new char[length + 1];
        std::strcpy(data, other.data);
        std::cout << "[Copy Constructed (Deep Copy)] '" << data << "'\n";
    }

    // 4. Copy Assignment Operator
    DynamicString& operator=(const DynamicString& other) {
        if (this != &other) {
            delete[] data;
            length = other.length;
            data = new char[length + 1];
            std::strcpy(data, other.data);
            std::cout << "[Copy Assigned] '" << data << "'\n";
        }
        return *this;
    }

    // 5. Move Constructor (Resource Stealing)
    DynamicString(DynamicString&& other) noexcept
        : data(other.data), length(other.length) {
        other.data = nullptr; // Nullify source
        other.length = 0;
        std::cout << "[Move Constructed (Zero-Copy Steal)]\n";
    }

    // 6. Move Assignment Operator
    DynamicString& operator=(DynamicString&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            length = other.length;
            other.data = nullptr;
            other.length = 0;
            std::cout << "[Move Assigned]\n";
        }
        return *this;
    }

    // Stream Output Overload
    friend std::ostream& operator<<(std::ostream& os, const DynamicString& ds) {
        return os << (ds.data ? ds.data : "[empty]");
    }
};

int main() {
    std::cout << "=== Day 23: Move Semantics & Rule of Five ===\n\n";

    DynamicString s1("High Performance C++");
    std::cout << "s1: " << s1 << "\n\n";

    // Copying s1 (Expensive deep copy)
    DynamicString s2 = s1;
    std::cout << "s2: " << s2 << "\n\n";

    // Moving s1 into s3 (Instant pointer transfer)
    DynamicString s3 = std::move(s1);
    std::cout << "s3: " << s3 << "\n";
    std::cout << "s1 after move: " << s1 << "\n\n";

    return 0;
}
