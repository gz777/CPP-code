//
//  Account.h
//  cpp_demo
//  Abstract class demo
//
//  Created by gz on 9/8/20.
//  Copyright © 2020 gz. All rights reserved.
//

#ifndef Account_h
#define Account_h

//abstract class
class Account {
public:
   Account( double balance ) { _balance = balance; } //constructor, inline definition
   virtual double getBalance() const { return _balance; }
   virtual void printBalance() const = 0;//pure virtual function
private:
    double _balance; //another way of writing member variable naming convention
};

// derived class
class CheckingAccount : public Account {
public:
   CheckingAccount(double balance) : Account(balance) {} //parameterized constructor
    void printBalance() const {
        std::cout << "Checking account balance: " << getBalance() << std::endl;
    }
};

//derived class
class SavingsAccount : public Account {
   double interest;
public:
   SavingsAccount(double balance, double i) : Account(balance) { interest = i;}
   double getBalance() const {
       return Account::getBalance() * (1 + interest);
   } //override
   void printBalance() const {
       std::cout << "Savings account balance: " << getBalance() << std::endl;
   } //overrid. which GetBalance() call, base or derived?
};
#endif /* Account_h */
