// Day 19: File Streams and std::filesystem
// Compile: g++ -std=c++20 -Wall -Wextra file_handling.cpp -o file_handling

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

int main() {
    std::cout << "=== Day 19: File Handling & Filesystem ===\n\n";

    fs::path test_dir = "temp_storage";
    fs::path test_file = test_dir / "sample_log.txt";

    // 1. Filesystem: Create directory if it doesn't exist
    if (!fs::exists(test_dir)) {
        fs::create_directories(test_dir);
        std::cout << "Created directory: " << test_dir << "\n";
    }

    // 2. Writing text file via std::ofstream
    {
        std::ofstream out(test_file);
        if (!out.is_open()) {
            std::cerr << "Failed to create " << test_file << "\n";
            return 1;
        }
        out << "Timestamp: 2026-11-07 15:00:00\n";
        out << "Status: SUCCESS\n";
        out << "Message: 30 Days of Modern C++ file handling verified.\n";
    } // File automatically flushed and closed here by RAII!

    std::cout << "Successfully written to " << test_file << "\n";
    std::cout << "File size: " << fs::file_size(test_file) << " bytes\n\n";

    // 3. Reading line-by-line via std::ifstream
    std::cout << "--- Reading Back Contents ---\n";
    std::ifstream in(test_file);
    if (in.is_open()) {
        std::string line;
        int line_no = 1;
        while (std::getline(in, line)) {
            std::cout << line_no++ << ": " << line << "\n";
        }
    }
    std::cout << "\n";

    // 4. Directory iteration
    std::cout << "--- Directory Iterator ---\n";
    for (const auto& entry : fs::directory_iterator(test_dir)) {
        std::cout << "Found: " << entry.path().filename() << "\n";
    }

    // Clean up
    fs::remove_all(test_dir);
    std::cout << "\nCleaned up temporary directory.\n";

    return 0;
}
