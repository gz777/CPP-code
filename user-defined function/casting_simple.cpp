/#include <iostream>
using namespace std;
int main()
{
  //Let us try to make the bmi value in two decimal place.
  double bmi = 4.2378; // assuming we have a bmi value as 4.2378

  //one line solution using casting
  cout << static_cast<int>(bmi * 100)/100.0 << endl;
  
  return 0;
}