// obtaining file size
#include <iostream>
#include <fstream>
using namespace std;

int main () {
  long begin,end;
  ifstream myfile ("out.bin");
  begin = myfile.tellg();//get current byte position
  myfile.seekg (0, ios::end);
  end = myfile.tellg();
  myfile.close();
  cout << "end is: " << end << endl
       << "begin is: " << begin << endl;
  cout << "size is: " << (end-begin) << " bytes.\n";
  return 0;
}



