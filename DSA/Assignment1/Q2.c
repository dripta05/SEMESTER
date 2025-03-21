#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SavingsAccount {
    char accountHolderName[50];
    int accountNumber;
    double balance;
};

int nextAccountNumber = 1;

void initializeAccount(struct SavingsAccount* account, const char* name, double initialBalance) {
    strncpy(account->accountHolderName, name, 50 - 1);
    account->accountHolderName[50 - 1] = '\0';
    account->accountNumber = nextAccountNumber++;
    account->balance = initialBalance;
}

void deposit(struct SavingsAccount* account, double amount) {
    if (amount > 0) {
        account->balance += amount;
    }
}

int withdraw(struct SavingsAccount* account, double amount) {
    if (amount > 0 && (account->balance - amount) >= 1000.0) {
        account->balance -= amount;
        return 1;
    }
    return 0;
}

double calculateInterest(const struct SavingsAccount* account) {
    return account->balance * 0.04;
}

void applyInterest(struct SavingsAccount* account) {
    double interest = calculateInterest(account);
    account->balance += interest;
}

double getRandomBalance() {
    return 1000.0 + (rand() / (double)RAND_MAX) * (100000.0 - 1000.0);
}

int main() {
    struct SavingsAccount accounts[100];
    double totalInterest = 0;
    char *name = " ";


    for (int i = 0; i < 10; i++) { //change 10 to 100
        initializeAccount(&accounts[i], name, getRandomBalance());
    }

    for (int i = 0; i < 10; i++) { // change 10 to 100
        double initialBalance = accounts[i].balance;
        double interest = calculateInterest(&accounts[i]);
        applyInterest(&accounts[i]);
        totalInterest += interest;

        printf("Account %d - %s:\n", accounts[i].accountNumber, accounts[i].accountHolderName);
        printf("  Initial Balance: Rs. %.2f\n", initialBalance);
        printf("  Interest: Rs. %.2f\n", interest);
        printf("  New Balance: Rs. %.2f\n\n", accounts[i].balance);
    }

    printf("Total interest paid to all accounts: Rs. %.2f\n", totalInterest);

    return 0;
}

