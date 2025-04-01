#include "BankAccount.h"
#include <iostream>
#include <string>

BankAccount::BankAccount(){
    balance = 2000.0;
}

void BankAccount::deposit(double amount) {
    balance += amount;
}

void BankAccount::withdraw(double amount){
    balance -= amount;
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