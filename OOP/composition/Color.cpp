#include "Color.h"
#include <iostream>
using namespace std;

Color::Color()
{
	color = "#ffffff";
}

Color::~Color()
{
}

void Color::displayColor(Pattern pattern)
{
	if (pattern == DOTTED)
		cout << "Its pattern is in " << "DOTTED" << " " + color + " color." << endl;
	else if (pattern == SOLID)
		cout << "Its pattern is in " << "SOLID"  << " " + color + " color." << endl;
	else
		cout << "Please enter a valid pattern." << endl;
}
