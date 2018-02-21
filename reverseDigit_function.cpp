//Martha Sander - 02-10-2017.
//Sources: None.
/*
Write a function, reverseDigit that takes an integer as a parameter and returns the number with its digits reversed. For example, the value of reverseDigit(12345) is 54321; the value of reverseDigit (5600) is  65; the value of  reverseDigit (7008) is  8007; and the value of reverseDigit (-532) is -235.
*/

#include <iostream>

using namespace std;

//declare function prototype reserveDigit before main.
int reverseDigit (int x);

int main ()
{
	//declare variables needed to execute main.
	int num, x;
	
	//ask for user input, calculate reversedDigit and output result.
	cout << "Please enter an integer: " << endl;
	cin >> x;
	num = reverseDigit (x);
	cout << "The reversed number of the integer entered is: " << num << endl;

	return 0;
}

//function definition.
int reverseDigit (int x)
{	
	y = (x % 10);
	
	while (x / 10 != 0) 
	{
		x = (x / 10);
		y = (y * 10) + (x % 10);
	}		
	return y;
}
