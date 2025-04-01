#include "util.h"
#include "BankAccount.h"
#include "SavingsAccount.h"
#include "CreditAccount.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>


using namespace std;


bool loggedin;
string username, pass;

int main(){
    srand(time(NULL));
    while(true){
        menu();
        int choice;
        cout << "\nChoice: ";
        cin >> choice;
        switch(static_cast<Option>(choice)){
            case Option::CREATE_ACC:
                cout << "Enter Username: ";
                cin >> username;
                cout << "Enter Password: ";
                cin >> pass;
                createUser(username,pass);
                break;
            case Option::LOGIN:
                while (!loggedin) {
                    std::cout << "Enter Password: ";
                    std::cin >> pass;
                    loggedin = authenticateUser(username, pass);
                    if (!loggedin) {
                        std::cout << "Incorrect password. Try again.\n";
                    }
                }
                std::cout << "Login successful!\n";
                break;
            case Option::VIEW_BANKACC:
                if(loggedin){
                    cout << "\nWelcome!\n";
                    while(1){
                        int choice2;
                        menu1(); 
                        cout << "\nChoice: ";
                        cin >> choice2;
                        BankAccount account;
                        account.set_id(username);
                        SavingsAccount account2;
                        CreditCardAccount account3("123456789", 1000.0, 5000.0);
                        
                        switch(static_cast<Option1>(choice2)){
                            case Option1::CHECKING_ACC:
                                int choice3;
                                double amount;
                                do{
                                    account.displayMenu();
                                    cout <<"Enter choice: ";
                                    cin >> choice3;
                                    switch(choice3){
                                        case 1:
                                            cout << "Enter deposit amount: ";
                                            cin >> amount;
                                            account.deposit(amount);
                                            cout << "Deposit successful!\n" << endl;
                                            break;
                                        case 2:
                                            cout << "Enter withdrawal amount: ";
                                            cin >> amount;
                                            account.withdraw(amount);
                                            break;
                                        case 3:
                                            cout <<  "Current balance: $" << account.get_balance() << endl << endl;
                                            break;
                                        case 4:
                                            account.displayTransactions();
                                            break;
                                        case 5:
                                            cout << "Goodbye.\n\n";
                                    }
                                if(choice3 == 5)
                                    break;
                                } while (choice3 !=6 );
                                break;
                            case Option1::SAVINGS_ACC:
                                int choice4;
                                double amount2;
                                do{
                                    account2.displayMenu();
                                    cout <<"Enter choice: ";
                                    cin >> choice4;
                                    switch(choice4){
                                        case 1:
                                            cout << "Enter deposit amount: ";
                                            cin >> amount2;
                                            account2.deposit(amount2);
                                            cout << "Deposit successful!\n" << endl;
                                            break;
                                        case 2:
                                            cout <<  "Current balance: $" << account2.get_balance() << endl << endl;
                                            break;
                                        case 3:
                                            account2.displayTransactions();
                                            break;
                                        case 4:
                                            account2.deposit_interest();
                                            break;
                                        case 5:
                                            double amount, howMany,interestRate;

                                            cout << "Initial Deposit: ";
                                            cin >> amount;

                                            cout << "Maturity Period (in months): ";
                                            cin >> howMany;

                                            cout << "Rate: ";
                                            cin >> interestRate;
                                            cout << endl;

                                            cout << "Total Money Accrued: " << account2.calculateFutureValue(amount,howMany,interestRate) << endl << endl;
                                            break;
                                        case 6:
                                            cout << "Back to Menu.\n\n" ;
                                    }
                                if(choice4 == 6)
                                    break;
                                } while (choice4 !=7);
                                break;
                            case Option1::CREDIT_ACC:
                                int choice5;
                                double amount3,amount4;
                                do{
                                    account3.displayMenu();
                                    cout <<"Enter choice: ";
                                    cin >> choice5;
                                    switch(choice5){
                                        case 1:
                                            cout << "How much? : ";
                                            cin >> amount3;
                                            account3.makePurchase(amount3);
                                            break;
                                        case 2:
                                            cout << "How much of balance to pay?: ";
                                            cin >> amount4;
                                            account3.makePayment(amount4);
                                            break;
                                        case 3:
                                            account3.displayCreditLimit();
                                            break;
                                        case 4:
                                            account3.displayAvailableCredit();
                                            break;
                                        case 5:
                                            account3.displayTransactions();
                                            break;
                                        case 6:
                                            cout << "Back to Account Menu.\n";
                                            break;
                                    }
                                    if(choice5 == 6)
                                    break;
                                } while(choice5 != 7);
                                break;
                            case Option1::EXIT:
                                break;
                        }
                        if (static_cast<Option1>(choice2) == Option1::EXIT)
                            break; // Exit the inner loop and return to main menu
                    }
                }else{
                    cout << "\nMust be logged in first.\n";
                }
                break;
            case Option::EXIT:
                cout << "Thank you for using our program\n";
                exit(0);
                break;
            default:
                break;
        }
    }
    return 0;
}