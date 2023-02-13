/*
10/4/18 class demo
Created by: gz
demonstrate the following concepts:
-Access modifier: public, private
-Define member functions (inline or standalone)
 -Constructor(default, with parameters)
 -Accessor(getter) and mutator(setter)

-How to create an object
-How to access to public members of an object, via dot notation

-Passing object to functions (pass by value, pass by reference, pass by const reference
-Returning an object from a function
*/
                             
#include <iostream>
#include <cmath>   //pow, MI_PI
#include <string>
                             
using namespace std;
class Circle {//class declaration
    private:
        double radius;//private, member variable
                  //we assume the value is in meters
                                 
    //member functions
    public:
        //constructor function: name is the same as the class name; must be public; no return type.
        Circle(){radius = 0;} //default constructor. inline functon
        Circle(double r) {radius = r;}//constructor with parameters. inline function
    //Note: function overloading
    
        ~Circle(){}//destructor.inline function. You may not need to declare a destructor. The compiler will create a default one for you.
                                 
        double getRadius() const {return radius;} // getter, accessor
                                 // const here is optional if you will not pass a const Circle object as parameter. However, it's extremely encouraged if you will always do so, because an accessor should only retrieve data and should not leave any loophole to modify the data
    
        void setRadius(double r){radius=r;} // setter, mutator
                                 
        double calcArea();
};

//member function definition                             
double Circle::calcArea(){
    return pow(radius,2)*M_PI;//pow( base, exp )
                              //M_PI    3.14159265358979323846
}

//function prototype                             
//passing object to function
void drawCircle(const Circle &, string color);//then let's add '&'
                             //then let's add const, so const Circle &

//returning an object from a function
Circle buildCircle(double);

int main() {
    Circle circle;//Implicitly calling the default constructor
    circle.setRadius(1.3); //calling member function setRadius()
                                 
    Circle circle1(2.3);//Implicitly caling constructor w parameter(s)
    cout << "circle1 radius is: " << circle1.getRadius() << endl;
    
    drawCircle(circle1, "red");//function call
    cout << "circle1 radius after calling drawCircle() is: " << circle1.getRadius() << endl;
                                 
    Circle circle2 = buildCircle(30.0);//assigning the return object of buildCircle() to circle2
    cout << "Circle2 radius is: " << circle2.getRadius() <<endl;
                                 
    return 0;
}

/*
 Params: const Circle & object, string color
 */
void drawCircle(const Circle & c, string color){ //see the difference if we add '&'
                                 //const Circle &c. This is the right implementation of passing obj in a function. In most cases, we do not want to modify any data of the original object
                                 
    cout << "I am drawing a " << color << " circle with radius " << c.getRadius() << endl;
    //c.setRadius(20);//by declaring "const" to Circle object, we can not modify member variables of the Circle object
    //cout << c.getRadius() << endl;
}

/*
 Params: double radius
 Return: Circle object
 */
Circle buildCircle(double r) {
    Circle circle;
    circle.setRadius(r); //or, simply: Circle circle(r);
    
    return circle;
}
