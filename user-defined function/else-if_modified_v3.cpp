// this is a loop version of the program

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
	cout << "Please enter your choice: ";
	cin  >> choice;

	//input validation, in case user did not enter a number
	while (!cin.good()) {//set buffer flag to false indicating there is an error
       cin.clear(); //reset the buffer flag
       cin.ignore(100,'\n'); //skip input stream upto 100 characters or to \n, whichever comes first
       cout << "Please enter a valid choice: ";
       cin >> choice;
    }
	// Set the numeric output formatting
	cout << fixed << showpoint << setprecision(2);

	// Use the menu selection to execute the correct set of actions
	while(choice > 4 || choice <1) {
		cout << "\nThe valid choices are 1 through 4.\n"
		     << "Run the program again and select one of those.\n";
	}

	if (choice == 4)
		cout << "Thank you and see you next time!\n";
	else {
		if (choice == 1)
			rate = ADULT_RATE;
		else if (choice == 2)
			rate = CHILD_RATE;
		else if (choice == 3)
			rate = SENIOR_RATE;

		cout << "For how many months? ";
		cin  >> months;
		charges = months * rate;
		cout << "\nThe total charges are $" << charges << endl;
	}

	return 0;
}
