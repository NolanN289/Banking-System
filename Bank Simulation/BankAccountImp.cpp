/*

    This is the Implementation file for the Bank Account base class.

*/


#include "BankAccount.h"


BankAccount::BankAccount(){
    balance = 2000.0;
}

BankAccount::BankAccount(const std::string& id, double initial_balance)
    : id(id), balance(initial_balance) {
}

void BankAccount::deposit(double amount) {
    balance += amount;
    addTransaction("Deposit", amount);
}

void BankAccount::withdraw(double amount){
    if (balance >= amount) {
        balance -= amount;
        addTransaction("Withdrawal", -amount); // Negative amount indicates withdrawal
        std::cout << "Withdrawal successful!\n" << std::endl;
    } else {
        std::cout << "Insufficient funds!\n" << std::endl;
    }
}

double BankAccount::get_balance() const{
    return balance;
}

std::string BankAccount::get_id() const{
    return id;
}

void BankAccount::set_id(std::string id){
    this->id = id;
}

void BankAccount::displayMenu(){

    std::cout << "Bank Account Menu for Account " << id << ":" << std::endl;
    std::cout << "1. Deposit" << std::endl;
    std::cout << "2. Withdraw" << std::endl;
    std::cout << "3. View Balance" << std::endl;
    std::cout << "4. View Transaction History" << std::endl;
    std::cout << "5. Exit" << std::endl << std::endl;


}   

void BankAccount::addTransaction(std::string description, double amount) {
    transactions.push_back(std::make_pair(description, amount));
    }

void BankAccount::displayTransactions() const {
    std::cout << "Transaction History for Account " << id << ":" << std::endl;
    for (const auto& transaction : transactions) {
        std::cout << "- " << transaction.first << ": $" << std::fixed << std::setprecision(2) << transaction.second << std::endl;
        }
        std::cout << std::endl;
    }
