// This is the modified version of the book example code
// Basically we removed the duplicate code block and make the program cleaner
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	// Constants for membership rates
	const double ADULT_RATE  = 120.0;
	const double CHILD_RATE  =  60.0;
	const double SENIOR_RATE = 100.0;

	int choice;           // Menu choice
	int months;           // Number of months
	double charges;       // Monthly charges
	double rate;

	// Display the menu and get the user's choice
	cout << "   Health Club Membership Menu\n\n";
	cout << "1. Standard Adult Membership\n";
	cout << "2. Child Membership\n";
	cout << "3. Senior Citizen Membership\n";
	cout << "4. Quit the Program\n\n";
	cout << "Enter your choice: ";
	cin  >> choice;
   
	// Set the numeric output formatting
	cout << fixed << showpoint << setprecision(2);

	// Use the menu selection to execute the correct set of actions 
	if (choice == 1)
		rate = ADULT_RATE;
	else if (choice == 2)
		rate = CHILD_RATE;
	else if (choice == 3)
		rate = SENIOR_RATE;
	else if (choice != 4) {
		cout << "\nThe valid choices are 1 through 4.\n"
		     << "Run the program again and select one of those.\n";
	}
	
	if(choice < 4) {
		cout << "For how many months? ";
		cin  >> months;
		charges = months * rate;
		cout << "\nThe total charges are $" << charges << endl;
	}
	
	return 0;
}


