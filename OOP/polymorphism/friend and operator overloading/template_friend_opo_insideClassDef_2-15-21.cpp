/******************************************************************************

 BCS370 Class Demo 2/15/21 gz
 templated class with friend function, operator overloading
 - friend function defined inline

*******************************************************************************/

#include <iostream>
using std::string;
using std::ostream;

// templated class with friend operator overloading function
template <class T> 
class Student {
    private:
       T grade;// A, A+, 3, 4, 3.5
       string name;
    
    public:
       Student(T g=0, string n = ""):grade(g),name(n) {}
    
       friend ostream& operator<<(ostream & c_out, const Student<T> & student1 ) { //const is a must in this case
            c_out << student1.grade << " " << student1.name;
            return c_out;
        } 
    
};


int main()
{
    Student<int> matt(100, "john");
    std::cout << matt;
    

    return 0;
}
