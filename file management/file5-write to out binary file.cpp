//http://www.cplusplus.com/doc/oldtutorial/files/
// writing on a text file
#include <iostream>
#include <fstream> // std::ifstream, std::ofstream
#include <string>
using namespace std;

int main () {
  ofstream myfile ("out.bin", ios::out | ios::binary);
  string st1 = "This is a line.", st2 = "This is another line.";
  
  if (myfile.is_open())
  {
    myfile.write((char *)&st1, sizeof(st1)); //ostream& write (const char* s, streamsize n);
	myfile.write((char *)&st2, sizeof(st2));
    myfile.close();
  }
  else cout << "Unable to open file";
  return 0;
}
