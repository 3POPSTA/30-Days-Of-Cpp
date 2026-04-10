// Day 21: Classes and Objects in Modern C++
// Compile: g++ -std=c++20 -Wall -Wextra classes.cpp -o classes

#include <iostream>
#include <string>
#include <utility>

class BankAccount {
private:
    std::string account_holder;
    std::string account_number;
    double balance;

    // Static member shared by all instances
    static inline int total_accounts{0};

public:
    // Parameterized constructor with member initializer list
    BankAccount(std::string holder, std::string acc_num, double initial_balance)
        : account_holder(std::move(holder)),
          account_number(std::move(acc_num)),
          balance(initial_balance) {
        ++total_accounts;
        std::cout << "[Opened Account] " << account_holder << " (#" << account_number << ")\n";
    }

    // Destructor
    ~BankAccount() {
        std::cout << "[Closed Account] " << account_holder << "\n";
    }

    // Mutator (non-const)
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited $" << amount << ". New balance: $" << balance << "\n";
        }
    }

    // Inspector (const: promises not to mutate object)
    double get_balance() const { return balance; }
    const std::string& get_holder() const { return account_holder; }

    static int get_total_accounts() { return total_accounts; }
};

int main() {
    std::cout << "=== Day 21: Classes & Objects ===\n\n";

    {
        BankAccount acc1("Ada Lovelace", "ACC-101", 1500.0);
        BankAccount acc2("Alan Turing", "ACC-102", 2200.0);

        std::cout << "Active accounts: " << BankAccount::get_total_accounts() << "\n\n";

        acc1.deposit(350.0);
        std::cout << acc1.get_holder() << " Balance: $" << acc1.get_balance() << "\n";
    } // Both accounts go out of scope and destructors trigger here!

    std::cout << "\nExited account scope.\n";
    return 0;
}
