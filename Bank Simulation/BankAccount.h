/*
   This is the header file for the Bank Account base class.
   @author Nolan Nguyen
   @author Jordan Havelaar
   @version 1 - updated 05-06-2024
*/

#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>
#include <utility>
#include <iostream>
#include <vector>
#include<iomanip>

class BankAccount{
public:
   /**
      Constructs a bank account with a $2000 balance.
   */
   BankAccount();

   BankAccount(const std::string& id, double initial_balance);
   /**
      Deposits money into this account.
      @param amount the amount to deposit.
   */
   void deposit(double amount);
   /**
      Withdraws money from this account.
      @param amount the amount to withdraw.
   */
   virtual void withdraw(double amount);
   /**
      Gets the balance of this account.
      @return the balance
   */
   double get_balance() const;
   /**
     Gets the id of this account.
     @return the balance
  */
    std::string get_id() const;
   /**
     Set id for bank account.
  */
    void set_id(std::string id);

    virtual void displayMenu();

    void addTransaction(std::string description, double amount);
    void displayTransactions() const;

protected:
    std::string id;
    double balance;
    std::vector<std::pair<std::string, double>> transactions;
};


#endif