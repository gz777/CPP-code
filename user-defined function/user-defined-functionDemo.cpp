/**
Class demo code
Date: 9/11/2018
Theme: user-defined function, pass-by-value v.s. pass-by-reference
Author: GZ
*/

#include <iostream>
using namespace std;

//prototypes
//pass-by-reference solution
int updateNums(int&, int&);

//pass-by-value solutions
int doubleNum(int);
int increNum(int);
int total(int,int);

int main() {

	int num1 = 1;
	int num2 = 2;
	int total = 0;
	cout << "Original value is: " << num1 << ", " << num2 << endl;

  //Round 1 of updating numbers
	total = updateNums(num1, num2);
	//num1 = doubleNum(num1);
	//num2 = increNum(num2);
	//total = total(num1,num2);

	cout << "Round 1 updated value is: " << num1 << ", " << num2 << " Total is: " << total << endl;

  //Round 2 of updaing numbers
	total = updateNums(num1, num2);
	//num1 = doubleNum(num1);
	//num2 = increNum(num2);
	//total = total(num1,num2);
	cout << "Round 2 updated value is: " << num1 << ", " << num2 << " Total is: " << total << endl;

	system("pause");

	return 0;
}

/*
	function name: updateNums
	description: The function updates first number by doubling it, updates the second number by incrementing it by 1. The function then returns the total of the two numbers of updated values.
	param: int& num1, int& num2
	return: int total
*/
int updateNums(int& num1, int& num2) {
	num1 = num1 * 2; //num1 *= 2;
	num2 = num2 + 1; //num2++; // num2 +=1;
	return num1 + num2;
}

//here are the pass-by-value solutions
int doubleNum(int num) {
	return num*2;
}

int increNum(int num) {
	return num+1;
}

int total(int num1, int num2) {
	return num1 + num2;
}
