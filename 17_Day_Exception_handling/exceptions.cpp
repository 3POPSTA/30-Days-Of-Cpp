// Day 17: Exception Handling in Modern C++
// Compile: g++ -std=c++20 -Wall -Wextra exceptions.cpp -o exceptions

#include <iostream>
#include <stdexcept>
#include <string>

// Custom domain exception
class InsufficientFundsException : public std::runtime_error {
    double shortfall;
public:
    InsufficientFundsException(const std::string& msg, double balance, double requested)
        : std::runtime_error(msg), shortfall(requested - balance) {}

    double get_shortfall() const noexcept { return shortfall; }
};

class BankAccount {
    double balance;
public:
    explicit BankAccount(double initial) : balance(initial) {
        if (initial < 0.0) {
            throw std::invalid_argument("Initial balance cannot be negative.");
        }
    }

    void withdraw(double amount) {
        if (amount <= 0.0) {
            throw std::invalid_argument("Withdrawal amount must be positive.");
        }
        if (amount > balance) {
            throw InsufficientFundsException("Withdrawal rejected: funds insufficient.", balance, amount);
        }
        balance -= amount;
        std::cout << "Successfully withdrew $" << amount << ". New balance: $" << balance << "\n";
    }

    double get_balance() const noexcept { return balance; }
};

int main() {
    std::cout << "=== Day 17: Exception Handling ===\n\n";

    try {
        BankAccount account(150.0);
        account.withdraw(50.0);
        account.withdraw(200.0); // Will throw InsufficientFundsException!
    } catch (const InsufficientFundsException& e) {
        std::cerr << "[Caught Custom Exception] " << e.what() << "\n";
        std::cerr << "Shortfall: $" << e.get_shortfall() << "\n\n";
    } catch (const std::invalid_argument& e) {
        std::cerr << "[Argument Error] " << e.what() << "\n";
    } catch (const std::exception& e) {
        std::cerr << "[Standard Exception] " << e.what() << "\n";
    } catch (...) {
        std::cerr << "[Unknown Exception caught]\n";
    }

    std::cout << "Program recovered and continues execution cleanly.\n";
    return 0;
}
