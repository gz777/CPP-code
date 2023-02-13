// 10/22/18 demo code for switch
#include <iostream>
#include <string>
using namespace std;

int main()
{
  char grade = ' ';
  cout << "what is your grade (A,B,C,D,F)? ";
  cin >> grade;
  
  //without break keyword -- fallthrough
  cout << "without break keyword -- fallthrough\n";
  switch(grade) {
    case 'A':
      cout << "A\n";
    case 'B':
      cout << "B\n";
    case 'C':
      cout << "C\n";
    case 'D':
      cout << "D\n";
    case 'F':
      cout << "You failed\n";
    default:
      cout << "Please enter a valid grade.\n"; 
  }
  cout << endl;
  
  //with break -- behavior is the same as if..else if..else if... ...else
  cout <<"with break -- behavior is the same as if..else if..else if... ...else\n";
  switch(grade) {
    case 'A':
      cout << "A\n"; break;
    case 'B':
      cout << "B\n"; break;
    case 'C':
      cout << "C\n"; break;
    case 'D':
      cout << "D\n"; break;
    case 'F':
      cout << "You failed\n"; break;
    default:
      cout << "Please enter a valid grade.\n"; 
  }
  cout << endl;
      
  //mix fallthrough and break
  cout << "mix fallthrough and break\n";
  switch(grade) {
    case 'A':
    case 'B':
    case 'C':
      cout << "Not bad\n"; break;
    case 'D':
    case 'F':
      cout << "You failed\n"; break;
    default:
      cout << "Please enter a valid grade.\n"; 
  }
  cout << endl;
  
     
  //mix fallthrough and break example 2
  cout << "fallthrough example 2\n";
  int serviceLevel = 0;
  cout << "Please enter your service level (1-4, 1 is the lowest, 4 is the highest): ";
  cin >> serviceLevel;
  
  switch(serviceLevel) {
    case 4: cout << "You have a free two-person meal coupon." << endl;
    case 3: cout << "You have a lux giftset." << endl;
    case 2: cout << "Your breakfast is on us." << endl;
    case 1: cout << "Welcome to our center. Have a good one." << endl; break;
    default:
        cout << "Please enter a valid entry." << endl;
      
  }
  
  return 0;    
}