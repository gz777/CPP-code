// Class demo code - implicit/explicit casting between datatypes
// 10/1/18

#include <iostream>
using namespace std;
int main()
{
  //Let us try to make the bmi value in two decimal place.
  double bmi = 4.2378; // assuming we have a bmi value as 4.2378
  cout <<"Original value of bmi: " << bmi << endl;
  
  
  bmi = bmi * 100; // First step, we multiply the bmi value by 100.
  cout <<"After multiply by 100: " << bmi << endl;
  
  ///* uncomment this line, if you want to run method 2
  //Method 1: coersion - implicit casting
  //Second step, we declare an int variable and assign the value bmi over.
  int int_bmi = bmi; 
  cout << "After implicit casting as an int value - int_bmi: " << int_bmi << endl;
    
  //Third setp, we divid the value by 100 and keep the value as a double (decimal value)
  bmi = int_bmi / 100.0;// we will need to put 100.0 to coerce the evaluation between two double values,so that it can give a correct decimal value. If we put 100 here, it means an integer value, then the compiler will do arithmetic operation between two integers and give an integer result. It will have informatin loss. We will not get a decimal value.
  cout <<"After dividing by a double value 100.0, the new value of bmi: " << bmi << endl;
  //*/ // uncomment this line, if you want to run method 2
  
  /*comment out this line to run method 2
  
  //Method 2: explicit casting using static_cast<dt>
  //Second step, we cast the bmi value with <int> type
  bmi = static_cast<int>(bmi*100);
  cout << "bmi after multiply by 100 with static_cast<int>: " << bmi << endl;
  
  //Third setp, we divid the value by 100 and keep the value as a double (decimal value)
  bmi = bmi/100;
  cout << "bmi after diving back by 100: " << bmi << endl;
  */ //comment out this line to run method 2
  
  return 0;
}