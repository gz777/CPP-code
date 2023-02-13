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
	//cin.get();//mac users use this code
	return 0;
}