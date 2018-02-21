//Martha Sander -02-27-2017.
//Sources: For cin.fail () in order to detect a non integer input,  http://www.cplusplus.com/forum/beginner/26821. For cin.ignore function, to ignore the entire line and not only one char, http://www.augustcouncil.com/~tgibson/tutorial/iotips.html.
/*
Write a C++ function, smallestIndex, that takes as parameters an int array and its size and returns the index of the smallest element in the array.  
*/


#include <iostream>
#include <cctype>
#include <limits>

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
	int numList [CAP] = {0};
	int smallest = 0, arraySize = 0;
	char userChoice = ' ';
	
	do
	{
		cout << "Please enter a list of " << CAP << " integers" << endl;	
 		
		//read index list by reference using cin.
		for (int i = 0; i < CAP; i ++)
		{
			cin >> numList [i];
		}
	
		//call bool isInputValid.
		if (isInputValid (numList) == true)
		{
			//call smallestIndex.
			smallest = smallestIndex (numList, CAP);
			cout << "The index of the smallest number for the (first) 10 integers entered is: " << smallest << endl;
		}
			//clear input if not valid or after smallestIndex so user can try again.		
			cin.clear ();
			cin.ignore (numeric_limits<streamsize>::max(),'\n');	
			cout << "Would you like to try again? enter y for yes, any other key to exit." << endl;
			cin >> userChoice;
	}
	while (tolower (userChoice) == 'y');
		
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
	if (cin.fail())
	{
		cout << "Please enter integers only." << endl;
		return  false;
	}
		return true;
}		
		
