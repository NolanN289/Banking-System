#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <algorithm>

#include "Employee.h"
#include "BankAccount.h"
#include "saltxtMaker.h"
#include <iomanip>

using namespace std;

//Function protoypes
ofstream leftAlignNames(const vector<string>& firstNames, const vector<string>& lastNames);

int main(){
    ifstream inputFile;
    ofstream outputFile;
    string buffer, employeeID, lastName, firstName, salary,fullName;
    double salary2;

    srand(time(NULL));

    vector<Employee> employeeVec;

    //generate salary.txt

    
     int count = 0;
     cout << "How many employees? ";
     cin >> count;
     makeSalaryFile(count);


     cout << "Salary file made! \n\n\n\n\n";
    
    
    inputFile.open("salary.txt");
    while(getline(inputFile,buffer) && buffer.find("EmployeeID") == std::string::npos){} //Not read first line
    while (inputFile >> employeeID >> lastName >> firstName >> salary){
        salary.erase(remove(salary.begin(), salary.end(), ','), salary.end()); // Remove commas from salary
        salary2 = stod(salary);
        BankAccount* account = new BankAccount();
        account->set_id(employeeID);
        employeeVec.push_back(Employee(employeeID, lastName, firstName, salary2, account)) ;
    }
    inputFile.close();
    outputFile.open("monthly_salary.txt");


    outputFile << std::left << std::setw(12) << "Employee ID" << std::setw(12) << "Last Name" << std::setw(12) << "First Name"
               << std::setw(16) << "Annual Salary" << std::setw(16) << "Monthly Salary" << std::setw(12) << "  Balance" << std::endl;
    //outputFile << employeeVec << std::endl;
     for (int i = 0; i < employeeVec.size(); ++i){
        auto& employee = employeeVec[i];
        if(i != 0){
            outputFile << std::endl;
        }
        employee.deposit_monthly_salary();
        outputFile << std::left << std::setw(12) << employee.get_id()
        << std::setw(12) << employee.get_last_name()
        << std::setw(12) << employee.get_first_name() << "$"
        << std::setw(16) << std::fixed << std::setprecision(2) << addComma(employee.get_salary()) << "$"
        << std::setw(16) << std::fixed << std::setprecision(2) << addComma(employee.get_salary() / 12.0) << "$"
        << std::setw(12) << std::fixed << std::setprecision(2) << addComma(employee.get_account()->get_balance());
     }
    outputFile.close();
    return 0;
}