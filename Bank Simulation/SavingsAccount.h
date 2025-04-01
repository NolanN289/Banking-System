/*
    This is the header file for the Savings Account derived class.
    @author Nolan Nguyen
    @author Jordan Havelaar
    @version 1 - updated 05-06-2024
*/

#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include "BankAccount.h" // Include the base class header
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

class SavingsAccount : public BankAccount {
public:
    /**
      Constructs a savings account with a $2000 balance.
    */
    SavingsAccount();
    
    /**
      Constructs a savings account with a specified initial balance.
      @param initial_balance the initial balance of the account.
    */
    SavingsAccount(double initial_balance);
    
    /**
      Deposits interest into this account.
    */
    virtual void deposit_interest();
    
    /**
      Overrides the withdraw function to prevent direct withdrawals from a savings account.
    */
    virtual void withdraw(double amount) override;

    double calculateFutureValue(double amount, double months,double interest);

    void displayMenu() override;

private:
  double interestRate;
};

#endif