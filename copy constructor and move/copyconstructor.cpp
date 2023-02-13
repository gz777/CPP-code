/* regular copy constructor
https://www.geeksforgeeks.org/copy-constructor-in-cpp/

Modified version
dynamic memory (shallow copy, deep copy)
*/

#include<iostream>
using namespace std;

class Point
{
private:
    int * x, * y;
public:
    Point(int x1, int y1) { x=new int; y=new int; *x = x1; *y = y1; } //Cartesian coordinates, x-axis, y-axis

    // Copy constructor
    //Point(const Point &p2) {x = p2.x; y = p2.y; } //member-wise copy, shallow copy

    Point(const Point &p2) {x=new int; y=new int; *x = *(p2.x); *y = *(p2.y); } //member-wise copy, deep copy

    // Destructor
    ~Point(){delete x; delete y;}

    int getX()            {  return *x; }
    int getY()            {  return *y; }
};

int main()
{
    Point p1(10, 15); // Normal constructor is called here
    Point p2 = p1; // Copy constructor is called here

    // Let us access values assigned by constructors
    cout << "p1.x = " << p1.getX() << ", p1.y = " << p1.getY();
    cout << "\np2.x = " << p2.getX() << ", p2.y = " << p2.getY();

    return 0;
}
