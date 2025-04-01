#include <iostream>
#include <iomanip>
#include "Employee.h"

Employee::Employee(std::string id, std::string ln, std::string fn, double s, BankAccount* a){ //Pass arguments into Employee constructor
    Eid = id;
    lname = ln;
    fname = fn;
    salary = s;
    account = a;
}
void Employee::deposit_monthly_salary(){
    double monthlySalary = salary / 12.0;
    account->deposit(monthlySalary); //deposits into account since the -> operation has to do with pointers? : function of the BankAcc Class
}

std::string Employee::get_id() const {
    return Eid;
}

std::string Employee::get_last_name() const {
    return lname;
}

std::string Employee::get_first_name() const {
    return fname;
}

double Employee::get_salary() const {
    return salary;
}

BankAccount* Employee::get_account() const {
    return account;
}

void Employee::print() const{

}