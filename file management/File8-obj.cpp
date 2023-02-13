#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Student
{
  public:
	char name[70];
	int age;
	 
	Student(char *name = "no name", int age = 0){ strcpy(this->name, name); this->age = age; }
	void whoAmI() {
		cout << " I am " << name << " and I am "  << age << " years of age.\n";
	}
};


int main()
{
    const int SIZE = 2;
	Student students[SIZE] = {Student("John Smith", 20), Student("Jill Johnson", 30)};
    
    cout << sizeof(students[0]) << " "  << sizeof(Student) << endl;
 
    // Open the File
    ofstream out;
	out.open("students.dat", ios::out | ios::binary);
 
    // Write objects to file
    for(int i=0;i<SIZE;i++) {
    	out.write((char*) &students[i], sizeof(Student));
	}
   
    out.close();
    
    // Open the File
    ifstream in;
	in.open("students.dat", ios::in | ios::binary);
	
	Student st;
    in.read((char*)&st, sizeof(Student));  
    // Read objects from file
    while(!in.eof()) {
      st.whoAmI();
      in.read((char*)&st, sizeof(Student));  
    }
    
    in.close();

    return 0;
}
