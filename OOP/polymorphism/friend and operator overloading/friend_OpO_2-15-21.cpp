/******************************************************************************

 BCS370 Class Demo 2/15/21 gz
 friend function, operator overloading

*******************************************************************************/

#include <iostream>
using std::string;

class Student {
    private:
       int age;
       std::string name;
    
    public:
       Student(int a=0, std::string n = ""):age(a),name(n) {}
       void operator+(int numOfYearPast) { age += numOfYearPast; }
    
       friend std::ostream& operator<<(std::ostream & c_out, const Student student1 ) {
           c_out << student1.age << " " << student1.name;
           return c_out;
       }
};

/*
cout << student1;

cin >> student1; //name, age
*/

int main()
{
    Student matt(20, "Matt");
    std::cout << matt << std::endl;
    
    matt + 2;
    
    std::cout << matt;
    

    return 0;
}
