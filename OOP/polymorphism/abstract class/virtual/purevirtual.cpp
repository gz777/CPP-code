/*
  pure virtual function/abstract class
  Modified from
 https://docs.microsoft.com/en-us/cpp/cpp/virtual-functions?view=vs-2017
  gz 3/3/19
*/

/*
  pure virtual function/abstract class
  Modified from
 https://docs.microsoft.com/en-us/cpp/cpp/virtual-functions?view=vs-2017
  gz 3/3/19
*/

#include <iostream>
using namespace std;

class Account {
public:
   Account( double d ) { _balance = d; }
   virtual double GetBalance() { return _balance; }
   virtual void PrintBalance()=0;
private:
    double _balance;
};

class CheckingAccount : public Account {
public:
   CheckingAccount(double d) : Account(d) {}
   void PrintBalance() { cout << "Checking account balance: " << GetBalance() << endl; }
};

class SavingsAccount : public Account {
   double interest;
public:
   SavingsAccount(double d, double i) : Account(d) { interest = i;}
   double GetBalance() { return Account::GetBalance() * (1 + interest); }
   void PrintBalance() { cout << "Savings account balance: " << GetBalance(); } //which GetBalance() call, base or derived?
};

int main() {
   // Create objects of type CheckingAccount and SavingsAccount.
   CheckingAccount *pChecking = new CheckingAccount( 100.00 ) ;
   SavingsAccount  *pSavings  = new SavingsAccount( 1000.00, 0.02 );

   pChecking -> PrintBalance();
   pSavings -> PrintBalance();
    
   delete pChecking, pSavings;
   
   return 0;
}
