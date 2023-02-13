#pragma once ////Include guard. This is a non-standard but widely supported preprocessor directive designed to cause the current source file to be included only once in a single compilation.

#include <iostream>
#include <cmath>
#include <string>

#define _USE_MATH_DEFINES // add this line if using visual studio. Math Constants were defined as macro in math.h <cmath>
#include <math.h>

#include "Color.h" //object composition

using namespace std;

class Circle
{
	double radius;
	Color color;
public:
	Circle();
	Circle(double);
	void setRadius(double r) { radius = r; }
	double getRadius() { return radius; }
	void setColor(Color c) { color = c; }
	Color getColor() { return color; }
	~Circle();
	double calcArea();
};


