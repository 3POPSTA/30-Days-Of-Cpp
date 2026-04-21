// Day 18: Regular Expressions with std::regex
// Compile: g++ -std=c++20 -Wall -Wextra regular_expressions.cpp -o regular_expressions

#include <iostream>
#include <string>
#include <regex>

int main() {
    std::cout << "=== Day 18: Regular Expressions ===\n\n";

    // 1. Full string match: email validation
    std::regex email_pattern(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    std::string test_email = "dev.master@cpp-lang.org";

    if (std::regex_match(test_email, email_pattern)) {
        std::cout << "'" << test_email << "' is a VALID email address.\n\n";
    }

    // 2. Substring search with capturing groups
    std::string log_entry = "2026-11-07 14:32:05 [ERROR] [CODE:404] Resource not found";
    std::regex log_pattern(R"((\d{4}-\d{2}-\d{2})\s+(\d{2}:\d{2}:\d{2})\s+\[(\w+)\]\s+\[CODE:(\d+)\]\s+(.*))");
    std::smatch match;

    if (std::regex_search(log_entry, match, log_pattern)) {
        std::cout << "--- Log Parser Breakdown ---\n";
        std::cout << "Date:     " << match[1] << "\n";
        std::cout << "Time:     " << match[2] << "\n";
        std::cout << "Level:    " << match[3] << "\n";
        std::cout << "Code:     " << match[4] << "\n";
        std::cout << "Message:  " << match[5] << "\n\n";
    }

    // 3. Iterating over all matches with std::sregex_iterator
    std::string text = "Prices: apple=$1.50, banana=$0.75, dragonfruit=$8.99";
    std::regex price_pattern(R"(\b(\w+)=\$(\d+\.\d{2}))");

    std::cout << "--- Extracted Price Items ---\n";
    auto words_begin = std::sregex_iterator(text.begin(), text.end(), price_pattern);
    auto words_end = std::sregex_iterator();

    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch m = *i;
        std::cout << "Item: " << m[1] << " | Price: $" << m[2] << "\n";
    }
    std::cout << "\n";

    // 4. Substitution with std::regex_replace
    std::string masked = std::regex_replace(text, std::regex(R"(\$(\d+\.\d{2}))"), "$$$$XX.XX");
    std::cout << "Masked output: " << masked << "\n";

    return 0;
}
