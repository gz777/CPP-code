/*
10/4/18 class demo
demonstrate the following concepts:
  Access modifier: public, private
  Define member functions (inline or standalone)
  Constructor(default, with parameters)
  Accessor(getter) and mutator(setter)

  How to create an object
  How to access to public members of an object, via dot notation

  Passing object to functions
  Returning an object from a function
*/

#include <iostream>
#include <cmath>   //pow, MI_PI

using namespace std;
class Circle {
    double radius;//private, member variable
                  //we assume the value is in meters

  //member functions
  public:
    Circle(){radius = 0;}//default constructor. inline functon
    Circle(double r) {radius = r;}//constructor with parameters

    ~Circle(){}//destructor.inline function
    double getRadius() {return radius;}
    void setRadius(double r){radius=r;}
    void enlargeCircle();
    double calcArea();
};
void Circle::enlargeCircle(){
  radius *= 2;
}
double Circle::calcArea(){
  return pow(radius,2)*M_PI;//pow( base, exp )
                            //M_PI	3.14159265358979323846
}

//passing object to function
void drawCircle(Circle);//then let's add '&'
                        //then let's add const, so const Circle &
//returning an object from a function
Circle buildCircle(double);
int main() {
  Circle circle1(2.3);
  circle1.enlargeCircle();
  cout << circle1.getRadius() << endl;

  drawCircle(circle1);
  cout << circle1.getRadius() << endl;


  Circle circle2 = buildCircle(30.0);
  cout << "Circle 2: " << circle2.getRadius() <<endl;

  return 0;
}

void drawCircle(Circle c){ //see the difference if we add '&'
                           //const Circle &c
   cout << c.getRadius() << endl;
   c.setRadius(20);
   cout << c.getRadius() << endl;
}

Circle buildCircle(double r) {
  Circle circle;
  circle.setRadius(r); //or, simply: Circle circle(r);
  return circle;
}
