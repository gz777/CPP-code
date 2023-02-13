#pragma once
#include <string>
using namespace std;

class Color
{
	string color;
public:
	enum Pattern { SOLID=1, DOTTED };
	Color();
	~Color();
	void setColor(string c) { color = c; }
	string getColor() { return color; }
	void displayColor(Pattern);//solid 's', dotted 'd'
};

