// writing on a text file
#include <iostream>
#include <fstream>
using namespace std;

int main () {
  ofstream myfile ("out.txt", ios::app );
  if (myfile.is_open())
  {
    myfile << "This is the third line.\n";
    myfile << "This is the fourth line.\n";
    myfile.close();
  }
  else cout << "Unable to open file";
  return 0;
}
