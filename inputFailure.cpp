//This program demos input failure
//It also shows you how to use cin.clear() and cin.ignore()
#include <iostream>

using namespace std;

int main()
{
	//variables
	int num1 = 0;
	float num2 = 0;
	//input from the user
	cout << "Please enter a whole number:";
	cin >> num1;
	//check for input failure
	while (!cin)
	{
		//reset cin back to the original state
		cin.clear();
		//clear the content of the input buffer or the unwanted information that was entered before
		cin.ignore(100, '\n');
		cout << "Bad input! Please try again!!";
		cin >> num1;
	}
	
	cout << "Please enter a real number:";
	cin >> num2;
	//check for input failure
	while (!cin)
	{
		//reset cin back to the original state
		cin.clear();
		//clear the content of the input buffer or the unwanted information that was entered before
		cin.ignore(100, '\n');
		cout << "Bad input! Please try again!!";
		cin >> num2;
	}
	//echo the input
	cout << "You entered: num1 = " << num1 << " and num2 = " << num2 << endl;

	return 0;
}