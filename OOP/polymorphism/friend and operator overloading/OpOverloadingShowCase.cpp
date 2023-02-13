/* operator overloading via member|friend function
   - unary operator overloading
   - binary operator overloading
   - prefix, postfix unary operator overloading
   - friend operator overloading
   
   Created: 11/13/18 gz All rights reserved.
   Modified 2/10/19 gz
 
 Updates 9/15/2020:
   Function signature rules -
     <friend function>
     - binary operator:
       function (arg1, arg2)

     - unary operator:
       function (arg1)
     -------------
     <Member method>
     ("this" object is reserved as the left operand)

     - binary operator:
       function (arg)

     - unary operator:
       function ()

     ------------
     prefix, postfix unary operator
      <prefix>
        function()
      <postfix>
        function(0)

    ---------------
    ofstream<<, ifstream>>
    must be "friend" function


*/

#include <iostream>
#include <string>
#include <cmath> //abs()
using std::cout;
using std::endl;

  
class Student
{
  int age;
    std::string name;
public:
    Student(int age, std::string name)  //constructor
    {
        this->age = age;
        this->name = name;
    }
    
    //friend operator overloading
    friend std::ostream& operator<<(std::ostream& os, const Student& st);
    
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
  
   //lab question: can you write the stream extraction operator >> overloading function?
   //friend istream & operator>> (istream &, Student &);
    
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
std::ostream& operator<<(std::ostream& os, const Student& st) {
    os << "Name: " << st.name << "; age: " << st.age << endl;
    return os;
}



int main()  {
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
    
    
    return 0;
}

