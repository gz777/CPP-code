/*
	BCS230
	Class demo 4/25/19
	gz copyright
*/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Car{
    char make[10];
    int year;
 public:
     Car(const char* m = "n/a", int y=0){
         year = y;
         strcpy(make, m);
     }
     char* getMake() { return make;}
     int getYear() {return year;}

};

class Student
{
  public:
	char name[30];
	int age;
	float gpa;
	Car car;

	Student(const char *name = "no name", int age = 0, float gpa =  0, const char* make="n/a", int year=0):car(make,year){ //const here is necessary, otherwise, it threw deprecation warning
	    strcpy(this->name, name);
	    this->age = age;
	    this->gpa = gpa;
    }
	void whoAmI() {
		cout << "I am " << name << " and I am "  << age << " years of age. "
             << "My GPA is: " << gpa  << ". I have a "  << car.getYear() << " year "
             << car.getMake() << endl;
	}
};

int main()
{
    const int SIZE = 3;
	//Student students[SIZE] = {Student("John Smith", 20), Student("Jill Johnson", 30)};
    Student students[SIZE] = {{"John Smith", 20, 4.0, "toyota", 2019}, {"Jill Johnson", 30, 3.5, "Nissan", 2018}, {"Samuel Smith", 100, 4.0, "Tesla", 2017}};


    // Open the File
    ofstream out;
	out.open("students.dat", ios::out | ios::binary);

    // Write objects to file
    for(int i=0;i<SIZE;i++) {
    	out.write((char*) &students[i], sizeof(Student));
	}
	//cout << "sizeof: " << sizeof(students[0]) << " "  << sizeof(Student) << endl;

    out.close();


    // Open the File
    ifstream in;
	in.open("students.dat", ios::in | ios::binary);

	Student obj;//default constructor call
    // Read objects from file
    //while(!in.eof()) { //Don't use .eof() or .good() as loop condition. It almost always produces buggy code (as it does in this case).
    while(in.read((char*)&obj, sizeof(Student))) {
      obj.whoAmI();
    }

    in.close();


    return 0;
}
