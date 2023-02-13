/*
  A simple recursion
  4/8/19 gz 
*/
#include <iostream>
using namespace std;

void echoMe(char a) {
     if(a != '0')  {
        cout << a << endl;
        cin >> a;
        echoMe(a);
   }
}
int main() {
  echoMe('a');

  return 0;

}