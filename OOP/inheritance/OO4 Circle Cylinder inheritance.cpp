/*
inheritance.cpp
The program is to demo how basic c++ inheritance works.
I did not separate files into .cpp, .h, and client code, so that it's easier for me to demo the code and easier for you to read the code in one place.
However, you should practice to separate the files.
*/

#include <iostream>
#include <cmath>
#include <string>

#define _USE_MATH_DEFINES // add this line if using visual studio. Math Constants were defined as macro in math.h <cmath>
#include <math.h>

using namespace std;

class Circle //the base class
{
  private:
	  double radius;
  protected:
	  string color;
  public:
	  
	  Circle(double r=0){radius = r; color="white";} //default constructor with parameters. You may write the constructor like this(syntatic difference): Circle(double r):radius(r), color("white");
                                                 //for no obvious reason that I did not pass color in the parameter but hard-coded in the constructor body. It just demos that so long there is a reason for doing it, no rules are set to stone that you have to obey in any situation.

    void setRadius(double r) { radius = r; }
	  double getRadius() const { return radius; }
	  void setColor(string c) { color = c; }
	  string getColor() const { return color; }
	  ~Circle(){}
	  double calcArea() {return pow(radius, 2)*M_PI;}//pi*r^2
};

class Cylinder: public Circle{//the derived class
  private:
     double height;
  public:
     Cylinder(double radius =0.0, double height):Circle(radius) {color="blue"; this->height = height;}//note we can directly access color, but not radius
     double getHeight() const {return height;}
     void setHeight(double h) {height = h;}
     double calcArea() {return 2*M_PI*getRadius()*height + 2*Circle::calcArea();}//area=2*pi*r*h+2*pi*r^2//function override
     double calcVolume() {return Circle::calcArea() * height;}//Pi*r^2*h

     /*void setColor(string c) {Circle::setColor(c);}
     string getColor() {return Circle::getColor();}
     double getRadius() {return Circle::getRadius();}*/
};



int main()
{
  //Cylinder cylinder; // calling default constructor
  Cylinder cylinder(23.5, 11.54); //calling constructor with parameters
  cylinder.setColor("red");
  cout << cylinder.calcVolume() << endl;
  cout << cylinder.getRadius() << endl;
  cout << cylinder.getHeight() << endl;
  cout << cylinder.getColor() << endl;

  cin.get();

  return 0;


}
