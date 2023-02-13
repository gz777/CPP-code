#include "Circle.h"

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif
Circle::Circle()
{
	radius = 0;
}

Circle::Circle(double r) {
	radius = r;
}

Circle::~Circle()
{
}

double Circle::calcArea() {
	return pow(radius, 2)*M_PI;
}
