
//9-17 main() function, comments, cin, cout
/*
File Name: main.cpp
Description: Assignment 2 - Simple calculator
Author: Grace
Date: 9/17/18
*/

//grey color: preprocessor
//blue color: ket words
//red color: library
//black color: programmer's code

#include "stdafx.h" //This is Visual studio specific line
#include <iostream> //include library called iostream
                    // preprocessor
#include <string>
using namespace std;//namespace. to replace std::xx

// This is the main function
int main() //blue-colored word is called keyword
{
	string myName;
	cout << "Please enter your name ";
  cin >> myName;
	cout << "hello " << myName <<endl; // print "hello world" to the screen
	return 0;//line, finish w ;
}



//9-17 hello world
#/*
File name: HelloWorld.cpp
Program description: Assignment 3 - hello world demo code
Author: grace
Date: 9/17/18
*/

#include <iostream>
#include <string>
using namespace std;

//This is the main() function
int main()
{
	string yourName;
	cout << "What is your name? ";
	cin >> yourName;

	cout << "Hello, there " << yourName <<endl;
	system("pause");
	return 0;
}


//demo 9-19-18 variable, mathematic operations
#include <iostream>
#include <string>
using namespace std;

int main() {
	// int
	int num;//declaration
	num = 10;//initiation

	//char
	char letter = 'a';


	//double
	double num1 = 11.5; //declaration + initialization
	double num2 = 10;

	double total = num1 + num2;
	double product = num1 * num2;
	double result = num1 / num2 /num2;

	cout << " Total is: " << total << endl;
	cout << " Product is: " << product << endl;

	//string
	string word;
	cout << "Please enter a word: "; //output
	cin >> word; //input

	cout << word << endl;

	system("pause"); //custom code to make the screen stay. Window OS specific command
	//cin.get();
	return 0;
}
