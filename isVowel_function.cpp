//Martha Sander - 02-10-2017.
//Sources: Nome.
/*
Write a value-returning function, isVowel that returns the value true if a given character is a vowel and otherwise returns false.  Write a program that prompts the user to input a sequence of characters and outputs the number of vowels.   It needs to handle both upper and lower case letters.
*/

#include <iostream>

using namespace std;

//Declare isVowel before main.
bool isVowel (char& character, int& numVowel);

int main ()
{
	//Declare variables, including for isVowel function.
	char character;
	int numVowels = 0;

	//Prompt the user to input a sequence of characters and exit condition.
	cout << "Please input a sequence of characters. To exit, enter 0." << endl;
	cin.get (character);
	
	//call isVowel.
	while (character != '0')
	{
		isVowel (character, numVowels);
		cin.get (character);
	}
	//Output the number of vowels.
		cout << "The number of vowels entered is " << numVowels << "." << endl;	

	return 0;
}

//Develop isVowel outside of main.
bool isVowel (char& character, int& numVowels)
{	
	switch (character)
	{
		case 'a': 
		case 'A':
		case 'e':
		case 'E':
		case 'i':
		case 'I':
		case 'o':
		case 'O':
		case 'u':
		case 'U':
			numVowels++;
			return true;
		default: 
			return false;	
	}
}
