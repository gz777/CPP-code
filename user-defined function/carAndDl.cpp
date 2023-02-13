//http://cpp.sh/8sceg
// 10/22 class demo
// in this demo, we try to give different ways of designing a computer program based on the business requirements.
// The business requirements are: if the person has a car and the person has a driver's license, then he/she can drive a car.

#include <iostream>
#include <string>
using namespace std;


int main()
{
  //so we have two variables here: a car and the driver's license.
  

  //solution one using string as variable data type
  string car, dl;
  cout << "do you have a car? write \"yes\" if you do, \"no\" if you don't."<<endl;
  cin >> car;
  cout << "do you have a valid driver's license? write \"yes\" if you do, \"no\" if you don't."<<endl;
  cin >> dl;
  
  if(car == "yes" && dl == "yes") {
      
      cout << "congrats! you can drive!" << endl;
      
  } else {
      
      cout << "either you will need to buy a car or need to get your driver's license. at least right now, you can not drive." << endl;
  }
  
  
  //solution two using int as variable data type
  int i_car, i_dl;
  cout << "do you have a car? enter 1 if you do, 0 if you don't."<<endl;
  cin >> i_car;
  cout << "do you have a valid driver's license? write \"yes\" if you do, \"no\" if you don't."<<endl;
  cin >> Idl;
  
  if(i_car == 1 && i_dl == 1) {
      
      cout << "congrats! you can drive!" << endl;
      
  } else {
      
      cout << "either you will need to buy a car or need to get your driver's license. at least right now, you can not drive." << endl;
  }
  
  
  //solution three using bool as variable data type
  bool b_car, b_dl;
  cout << "do you have a car? enter 1 if you do, 0 if you don't."<<endl;
  cin >> b_car;
  cout << "do you have a valid driver's license? write \"yes\" if you do, \"no\" if you don't."<<endl;
  cin >> b_dl;
  
  if(b_car && b_dl) {//the expressions are equivalent to if (b_car == 1 && b_dl == 1), since you've already assign true (or 1) to b_car and b_dl, in other words, they value of the variables are already true, you do not need to re-compare it again against the value - true or 1.
      
      cout << "congrats! you can drive!" << endl;
      
  } else {
      
      cout << "either you will need to buy a car or need to get your driver's license. at least right now, you can not drive." << endl;
  }
  
  return 0;
}