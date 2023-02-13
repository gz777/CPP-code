/* operator overloading via member|friend function 
   Created: 11/13/18 gz All rights reserved.
   Modified 2/10/19 gz 
*/

#include <iostream>
#include <string>
#include <cmath> //abs()
using namespace std;  
  
class Student  
{  
    int age;
	string name;  
public:  
    Student(int age, string name)  //constructor
    {  
        this->age = age;
		this->name = name; 
    }
    
    //friend operator overloading
    friend ostream& operator<<(ostream& os, const Student& st);
	
	/* We now overload operator- */
	//case 1: member unary operator overloading
	/*void operator-() {
      age--;
    }*/
    
    //case 2: non-member unary opeartor overloading
    friend Student operator-(Student &); //unary operator loading
   
    //case 3: member binary operator overloading
    int operator-(Student &);
   
   
   /* Now let's now take a look at unary incremental operator ++ */
   //member prefix ++x
    void operator++() { ++age;};
    
   //member postfix x++
    void operator++(int) {age++;} 
   ////non-member postfix signature: void operator++(Student&, int) { };
  
    friend istream & operator>> (istream &, Student &);

	
};

//friend/non-member function -Student
Student operator-(Student & s1) {
	s1.age -= 10; //note, direct access to privte member variable age.
	return s1;
}

//member binary operator overloading
int Student::operator-(Student & s1) {
	return abs(age - s1.age);//note, directly accessing private member age
}


//friend function  
ostream& operator<<(ostream& os, const Student& st)  
{  
    os << "Name: " << st.name << "; age: " << st.age << endl;  
    return os;  
}  

//friend function
istream& operator>>(istream& is, Student & st) { 
    cout << "Enter student age: "; 
    is >> st.age; 
    cout << "Enter student name: "; 
    is >> st.name; 
    
    return is; 
} 


int main()  
{  
    Student st(18, "Mary");  
    cout << "first student " << st << endl;
	
	-st;//unary function call (both member and non-member function can be called like this)
	cout << "After operator-. " << st << endl;
	
    // explicit call for -st
    /*operator-(st); //no-member function call
    st.operator-(); //member function call
    cout << st << endl;*/
    
    
	Student st2(17, "Smith");
	cout << endl << st << st2 << "The two's age difference is: " << ( st - st2) << endl;
	
	cin >> st2;
	cout << "second student became. " << st2 << endl;
	
	return 0;
}
