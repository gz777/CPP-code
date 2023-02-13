//Modified from java version created by Evan Korth New York University
// 4/8/19
#include <iostream>
using namespace std;

void upAndDown (int n) 
{
	static int count = 0; //so that you can see how many times the function gets called
    count++;
	
    cout << "\nLevel: " <<  n;
		if (n < 4)
			upAndDown (n+1);

	  cout <<"\n" << count << "\nLEVEL: " << n;
}

int main() {
  upAndDown(1);
  return 0;
}
