#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

class SavingsAccount {
private:
    std::string name;
    int accountNumber;
    double balance;
    static int nextAccountNumber;
    static double interestRate;
    static const double minBalance;

public:
    // Constructor
    SavingsAccount(const std::string &name, double initialBalance) : name(name) {
        accountNumber = nextAccountNumber++;
        balance = (initialBalance >= minBalance) ? initialBalance : minBalance;
    }

    // Deposit method
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    // Withdraw method
    void withdraw(double amount) {
        if (amount > 0 && balance - amount >= minBalance) {
            balance -= amount;
        } else {
            std::cout << "Insufficient funds or below minimum balance!" << std::endl;
        }
    }

    // Method to calculate and deposit interest for one year
    void addInterest() {
        double interest = balance * interestRate;
        balance += interest;
    }

    // Method to get balance
    double getBalance() const {
        return balance;
    }

    // Method to get interest for one year
    double calculateInterest() const {
        return balance * interestRate;
    }

    // Static method to get the interest rate
    static double getInterestRate() {
        return interestRate;
    }

    // Static method to get the total interest paid for all accounts
    static double calculateTotalInterest(const std::vector<SavingsAccount> &accounts) {
        double totalInterest = 0;
        for (size_t i = 0; i < accounts.size(); ++i) {
            totalInterest += accounts[i].calculateInterest();
        }
        return totalInterest;
    }

    // Display account information
    void displayAccountInfo() const {
        std::cout << "Account Number: " << accountNumber
                  << ", Name: " << name
                  << ", Balance: " << balance << std::endl;
    }
};

// Initialize static members
int SavingsAccount::nextAccountNumber = 1;
double SavingsAccount::interestRate = 0.04; // Example interest rate of 4%
const double SavingsAccount::minBalance = 1000.0;

int main() {
    std::srand(static_cast<unsigned int>(std::time(0))); // Seed for random number generation
    std::vector<SavingsAccount> accounts;

    // Create 100 SavingsAccount objects with random initial balances
    for (int i = 0; i < 100; ++i) {
        double randomBalance = 1000 + (std::rand() % 99001); // Random balance between 1000 and 100000
        accounts.push_back(SavingsAccount("AccountHolder" + std::to_string(i + 1), randomBalance));
    }

    // Calculate and deposit interest for each account
    for (size_t i = 0; i < accounts.size(); ++i) {
        accounts[i].addInterest();
    }

    // Calculate total interest paid
    double totalInterest = SavingsAccount::calculateTotalInterest(accounts);

    // Display account information
    for (size_t i = 0; i < accounts.size(); ++i) {
        accounts[i].displayAccountInfo();
    }

    std::cout << "Total interest paid to all accounts: " << totalInterest << std::endl;

    return 0;
}
