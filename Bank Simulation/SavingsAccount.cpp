#include "SavingsAccount.h"
#include <cmath>

SavingsAccount::SavingsAccount() : BankAccount("Savings", 2000.0) {}

SavingsAccount::SavingsAccount(double initial_balance) : BankAccount("Savings", initial_balance) {}

void SavingsAccount::displayMenu() {
    std::cout << "Savings Account Menu" << std::endl;
    std::cout << "1. Deposit" << std::endl;
    std::cout << "2. View Balance" << std::endl;
    std::cout << "3. View Transaction History" << std::endl;
    std::cout << "4. Deposit Interest" << std::endl;
    std::cout << "5. Calculate Future Value" << std::endl;
    std::cout << "6. Exit" << std::endl << std::endl;
}

void SavingsAccount::deposit_interest() {
    double interest_rate = 0.05; // Example interest rate (5%)
    double interest = balance * interest_rate;
    balance += interest;
    addTransaction("Interest Deposit", interest);
}

void SavingsAccount::withdraw(double amount) {
    // Override the withdraw function to prevent direct withdrawals from a savings account
    std::cout << "Cannot withdraw directly from a savings account." << std::endl;
}

double SavingsAccount::calculateFutureValue(double amount, double months, double interest) {
    double monthlyInterestRate = interest / 12.0 / 100.0; // Convert annual interest rate to monthly
    double futureValue = amount * pow((1 + monthlyInterestRate), months);
    return futureValue - amount; // Return the interest gained
}