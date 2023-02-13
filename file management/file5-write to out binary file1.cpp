//http://www.eecs.umich.edu/courses/eecs380/HANDOUTS/cppBinaryFileIO-2.html

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

struct Person
{
  string name;
  int age;
};

int main()
{
  Person me = {"Robert", 28};
  Person book[3] = {me, {"mary", 29}, {"smith", 99}};

  ofstream outfile("test.dat");
  for(int i=0;i<30;i++){
  	outfile << book[i].name << "|" << book[i].age <<endl;
  }
  
  outfile.close();
}
