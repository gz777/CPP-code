// operator overloading via friend function 
// 11/13/18 gz
#include <iostream>
#include <string>
using namespace std;  
  
class Student  
{  
    int age;
	string name;  
public:  
    Student(int age, string name)  
    {  
        this->age = age;
		this->name = name; 
    }  
    friend ostream& operator<<(ostream& os, const Student& st);  
};  
  
ostream& operator<<(ostream& os, const Student& st)  
{  
    os << "Name: " << st.name << "; age: " << st.age << endl;  
    return os;  
}  
  
int main()  
{  
    Student st(18, "Mary");  
    cout << st;
	
	return 0;  
}  

