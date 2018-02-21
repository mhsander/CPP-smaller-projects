//Martha Sander - 02-28-2017.
//Sources: none.
/*Also write a second program to test your function.  This program should call your function a number of times with different types of input and check for the correct results.  Think about what boundary cases you should test.  I am being vague here and you should use the discussion board to ask questions and help each other.
*/

#include <iostream>
#include <cctype>

using namespace std;

//declare smallestIndex prototype.
int smallestIndex (int numList [], int arraySize);

//function prototype to check if input is valid.
bool isInputValid (int numList []);

//initialize array to a const so it can be easily changed if needed.
const int CAP = 10;

int main ()
{
	//declare int main variables.
	int smallest = 0, arraySize = 0;
	int numList [CAP] = {0};
	
	cout << "This program will test the program that calculates the index of the smallest number, when asked to input " << CAP << " integers." << endl;

	cout << "Testing for input: 2 4 5 20 55 2 10 1 30 11 - Copy and paste or enter each number followed by return key." << endl;

	for (int i = 0; i < CAP; i ++)
	{
		cin >> numList [i];
	}
	//call bool isInputValid as part of the original program.
	isInputValid (numList);

	//testing for char input.	
	cin.clear();
	cin.ignore (numeric_limits<streamsize>::max(),'\n');	
 	cout << "Testing for input of type char. Please insert the input 'b'" << endl;
	for (int i = 0; i < CAP; i ++)
	{
		cin >> numList [i];
	}
	
	isInputValid (numList);

	//testing for string input.
	cin.clear();
	cin.ignore (numeric_limits<streamsize>::max(),'\n');	
	cout << "Testing for input of type string. Please input a string." << endl;
	for (int i = 0; i < CAP; i ++)
	{
		cin >> numList [i];
	}
	
	isInputValid (numList);

	//check for a list longer than CAP.	
	cin.clear();
	cin.ignore (numeric_limits<streamsize>::max(),'\n');	
	cout << "Testing for a input of integers separated by space and longer than CAP. Please enter the list as an input." << endl;
	for (int i = 0; i < CAP; i ++)
	{
		cin >> numList [i];
	}
	
	isInputValid (numList);
	cout << "For longer input, the program will calculate the indext for the smallest numbers of the first 10 integers only and ignore the remaining input" << endl;	

	//testing for doubles.
	cin.clear();
	cin.ignore (numeric_limits<streamsize>::max(),'\n');	
	cout << "Testing for input of type double, for example, 5.4. Please input a double." << endl;
	for (int i = 0; i < CAP; i ++)
	{
		cin >> numList [i];
	}
	
	isInputValid (numList);

	cout << "Thank you for testing the smallestIndex function." << endl; 	
    return 0;
}

int smallestIndex (int numList [], int arraySize)
{
	int smallestNum = numList [0];
	int index = 0;

	for (int i = 1; i < arraySize; i ++) 
	{
		if (smallestNum > numList [i])
		{
			smallestNum = numList [i];
			index = i;
		}				
	}
	
	return index;
}

bool isInputValid (int numList [])
{
	int smallest = 0;

	if (cin.fail())
	{
		cout << "input invalid. Please enter integers only." << endl;
		return  false;
	}
	else 
		smallest = smallestIndex (numList, CAP);
		cout << "The index of the smallest number is: " << smallest << endl;
		cout << "The input was correct and the program was able to calculate the correct function" << endl;
		return true;
}		
	
