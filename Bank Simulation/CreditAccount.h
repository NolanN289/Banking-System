/*
    This is a header file for the Credit Card Account derived class
    @author Nolan Nguyen
    @author Jordan Havelaar
    @version 1 - updated 05-06-2024
*/

#ifndef CREDITACCOUNT_H
#define CREDITACCOUNT_H

#include "BankAccount.h"

class CreditCardAccount : public BankAccount {
public:
    // Constructor
    CreditCardAccount(const std::string& id, double initial_balance, double credit_limit);

    // Override displayMenu() to implement credit card specific menu options
    void displayMenu() override;

    //  member functions specific to CreditCardAccount
    void makePurchase(double amount);

    void makePayment(double amount);

    void displayCreditLimit() const;

    void displayAvailableCredit() const;

private:
    double credit_limit;
};


#endif