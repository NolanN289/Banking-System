/*
    This is a utility file : handles some functions in the menu and login page.
    @author Nolan Nguyen
    @author Jordan Havelaar
    @version 1 - updated 05-06-2024

*/

#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>


enum class Option{
    NONE,
    CREATE_ACC,
    LOGIN,
    VIEW_BANKACC,
    EXIT
};

enum class Option1{
    NONE,
    CHECKING_ACC,
    SAVINGS_ACC,
    CREDIT_ACC,
    EXIT
};

std::unordered_map<std::string, std::string> users;

std::string optionToString(Option o);
void menu();
void menu1();
void showBanner();
void createUser(const std::string& username, const std::string& password);
bool authenticateUser(const std::string& username, const std::string& password);


std::string optionToString(Option o){ //setting the options to string, for the menu
    switch(o){
        case Option::NONE:
            return "None";
        case Option::CREATE_ACC:
            return "Create Account";
        case Option::LOGIN:
            return "Login";
        case Option::VIEW_BANKACC:
            return "View Bank Account";
        case Option::EXIT:
            return "Exit";
        default:
            return "Invalid Option";
    }
}

std::string option1ToString(Option1 o){ //setting the options to string, for the menu
    switch(o){
        case Option1::NONE:
            return "None";
        case Option1::CHECKING_ACC:
            return "Checking Account";
        case Option1::SAVINGS_ACC:
            return "Savings Account";
        case Option1::CREDIT_ACC:
            return "Credit Card Account";
        case Option1::EXIT:
            return "Exit";
        default:
            return "Invalid Option";
    }
}

void menu(){
    showBanner();
    for(Option op = Option::CREATE_ACC; op <= Option::EXIT; op = static_cast<Option>((static_cast<int>(op) + 1))){// display the menu in the console
        std::cout << static_cast<int>(op) << ". " << optionToString(op) << std::endl;
    }

}

void menu1(){
    for(Option1 op = Option1::CHECKING_ACC; op <= Option1::EXIT; op = static_cast<Option1>((static_cast<int>(op) + 1))){// display the menu in the console
        std::cout << static_cast<int>(op) << ". " << option1ToString(op) << std::endl;
    }

}

void showBanner(){
    std::cout << "\n*******************************************************\n";
    std::cout << "*                                                     *\n";
    std::cout << "*              BANKING COMPANY MENU                   *\n"; //banner for presentability of our menu
    std::cout << "*                                                     *\n";
    std::cout << "*******************************************************\n\n";
}




void createUser(const std::string& username, const std::string& password) {
    users[username] = password; // Store username and password in the map
    std::cout << "User created successfully!\n";
}

bool authenticateUser(const std::string& username, const std::string& password) {
    auto it = users.find(username);
    if (it != users.end() && it->second == password) {
        return true; // Username and password match
    }
    return false; // Username not found or password is incorrect
}

#endif