#ifndef SALTXTMAKER_H
#define SALTXTMAKER_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <string>
#include <vector>

std::string genEmployeeID();
double genAnnualSalary();
void makeSalaryFile(int count);
std::string addComma(double num);

std::string genEmployeeID(){
    int idLength = 10;
    int i = 0;
    std::string employeeID;
    while (i < idLength){
        employeeID += std::to_string(rand() % 10); //Choose a random number and add it into string id
        ++i;
    }
    return employeeID;
}

double genAnnualSalary() {
    // Calculate random annual salary based on real-life average annual salary range in 2024
    double annualSalary = (rand() % 50001) + 40000;

    // Divide by 100 to convert to dollars
    //annualSalary /= 100.0;

    return annualSalary;
}

std::string addComma(double num) {
    std::string numberStr = std::to_string(num);
    size_t decimalPos = numberStr.find('.');

    size_t precisionPos = numberStr.find('.');
    if (precisionPos != std::string::npos && numberStr.size() > precisionPos + 3) {
        numberStr = numberStr.substr(0, precisionPos + 3); // Cut off excess decimals
    }
    
    // Insert commas starting from the first digit before the decimal point
    for (int i = decimalPos - 3; i >= 0; i -= 3) {
        numberStr.insert(i, ",");
    }

    return numberStr;
    
}

void makeSalaryFile(int count){
    std::ifstream input1;
    std::ofstream output1;
    std::string lastName, firstName;
    double salary;
    std::vector<std::string> lnVec, fnVec;
    std::vector<double> salVec;

    input1.open("employeeNames2.txt");
    output1.open("salary.txt");

      for(int i = 0; i < count; ++i){
        input1 >> lastName >> firstName;
        lnVec.push_back(lastName);
        fnVec.push_back(firstName);
    }

    output1 << "EmployeeID    LastName      FirstName      Salary" << std::endl;
    for(int j = 0; j < fnVec.size(); ++j){
        if( j !=0 ){
            output1 << std::endl;
        }
        output1 << genEmployeeID() << "     ";
        size_t maxFirstLength = 0;
        size_t maxLastLength = 0;
        for (const auto& firstName : fnVec) {
            maxFirstLength = std::max(maxFirstLength, firstName.length());
        }
        for (const auto& lastName : lnVec) {
            maxLastLength = std::max(maxLastLength, lastName.length());
        }
        size_t maxLength = std::max(maxFirstLength, maxLastLength);


        output1 << std::left << std::setw(maxLength + 2);

        output1 << lnVec[j];
        
        output1 << "   ";
        output1 << std::left << std::setw(maxLength + 2);
        output1 << fnVec[j];
        //output1 << std::left << std::setw(maxLength + 2);
        salary = genAnnualSalary();
        salVec.push_back(salary);
        if((int)salary % 1000 < 100){
            output1 << (int)salary / 1000 << ",0" << (int)salary % 1000;
        }else{
            output1 << (int)salary / 1000 << "," << (int)salary % 1000;
        }
        //output1 << salary;
        }
    input1.close();
    output1.close();
}
#endif