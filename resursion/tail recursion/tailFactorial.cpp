//tail recursion illustrate
//4/10/19 gz
#include <iostream>

//not tail
int findFactorial (int number) 
{
   if ((number == 1) || (number == 0))
	return 1;
   else
	return (number * findFactorial (number-1));
}

//tail
int findFactorial_t (int number, int result=1) 
{
   if ((number == 1) || (number == 0))
	return result;
   else
	return findFactorial_t(number-1, number*result);
}


int main() {

  std::cout << findFactorial_t(5) << "\n";
  std::cout << findFactorial(5) << "\n";
}