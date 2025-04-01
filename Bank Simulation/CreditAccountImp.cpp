#include "CreditAccount.h"

CreditCardAccount::CreditCardAccount(const std::string& id, double initial_balance, double credit_limit)
    : BankAccount(id, initial_balance), credit_limit(credit_limit) {
        
    }

void CreditCardAccount::displayMenu() {
    std::cout << "Credit Card Menu:" << std::endl;
    std::cout << "1. Make a purchase" << std::endl;
    std::cout << "2. Make a payment" << std::endl;
    std::cout << "3. Display credit limit" << std::endl;
    std::cout << "4. Display available credit" << std::endl;
    std::cout << "5. Display transactions" << std::endl;
    std::cout << "6. Exit" << std::endl << std::endl;
}

void CreditCardAccount::makePurchase(double amount) {
    if (balance + amount <= credit_limit) {
        deposit(amount);
        addTransaction("Purchase", -amount);
        std::cout << "Purchase successful." << std::endl;
    } else {
        std::cout << "Insufficient credit available." << std::endl;
    }
}

void CreditCardAccount::makePayment(double amount) {
    if (amount <= balance) {
        withdraw(amount);
        addTransaction("Payment", amount);
        std::cout << "Payment successful." << std::endl;
    } else {
        std::cout << "Payment amount exceeds balance." << std::endl;
    }
}

void CreditCardAccount::displayCreditLimit() const {
    std::cout << "Credit Limit: $" << credit_limit << std::endl;
}

void CreditCardAccount::displayAvailableCredit() const {
    double available_credit = credit_limit - balance;
    std::cout << "Available Credit: $" << available_credit << std::endl;
}