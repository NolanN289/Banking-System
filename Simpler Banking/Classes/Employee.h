#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "BankAccount.h"

class Employee{
public:
   /**
      Constructs an employee with a id, given name, salary, and
      bank account.
      @param id the id
      @param ln
      @param fn the name
      @param s the annual salary
      @param a a pointer to the bank account
   */
   Employee(std::string id, std::string ln, std::string fn, double s, BankAccount* a);
   /**
      Deposits one month's salary into the bank account.
   */
   void deposit_monthly_salary();
   /**
      Prints this employee's information to cout.
   */
   std::string get_id() const;

   std::string get_last_name() const;

   std::string get_first_name() const;

   double get_salary() const;

   BankAccount* get_account() const;  

   void print() const;
private:
   std::string Eid;
   std::string lname;
   std::string fname;
   double salary;
   BankAccount* account;
};

#endif