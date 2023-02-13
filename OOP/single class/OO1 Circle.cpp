// Example program
//10/2/18 OO, private, publc, setter, getter, constructor

#include <iostream>
#include <string>
using namespace std;

//classs delcaration
class Circle {
   //private: by default if no access modifer is specified
   double radius; //member variable
 public:
   Circle(); //default constructor
   void setRadius(double r) { radius = r;}; //member function, setter function; inline function
   double area(); // member function
};

//member function definition
Circle::Circle(){
  radius = 0.0;
}

double Circle::area(){//member function
 return radius * radius * 3.14;
}

// client code
int main()
{
  Circle circle1, circle2;//instantiating two objects, evoking default constructor

  circle1.setRadius(22.4);
  cout << circle1.area() << endl;

  circle2.setRadius(10);
  cout << circle2.area();

  return 0;
}
