// Example program
#include <iostream>
#include <string>
using namespace std;
int main()
{
  //Different ways to skip number 15
  
  //method 1 - for loop 
  for (int i=1;i<=20;i++) {
    if(i == 15)
        continue;
    cout << i << endl;
  }
  cout << endl;
  
  //method 2 - pre-test while loop
  int i = 0;
  while(i < 20) {
    i++;
    if(i == 15)
        continue;
    cout << i << endl;
  }
  cout << endl;
  
  //method 3 - post-test while loop
  int j = 0;
  do {
    j++;
    if(j == 15)
        continue;
    cout << j << endl;
  }while(j<20);
   
 
  return 0;
}
