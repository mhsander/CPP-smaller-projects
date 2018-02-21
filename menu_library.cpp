//Martha Sander - 03-05-2017.
//Sources: for searching a string within an array (function strstr): https://www.tutorialspoint.com/cplusplus/cpp_strings.htm.

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>

using namespace std;

const int ARRAY_SIZE = 1000;

//declare arrays at file scope.
string bookTitle [ARRAY_SIZE];
string bookAuthor [ARRAY_SIZE];

//declare functions prototypes.
void showAll (int count);

int loadData (string pathname);

void showBooksByAuthor (int count, string name);

void showBooksByTitle (int count, string title);

int main ()
{
	string pathname, name, title;
	int count = 0;
	char userChoice = ' ', menuChoice = ' ';

	//prompt the user to enter the file name with the path on disk.
	do	
	{
		cout << "Please enter file name with path on disk: " << endl;
		getline (cin, pathname);
		
		//call loadDate to check for file.
		count = loadData (pathname);
					
		if (count == -1)
		{
			cout << "The file is not open. Would you like to try again? Enter y for yes, any other to exit." << endl;
			cin >> userChoice;
			cin.clear();
			cin.ignore();
		}
	}	

	while (tolower(userChoice) == 'y' && count == -1);
	
	//open menu choice.	
	if (count != -1)	
	{
		cout << " " << count << " records loaded successfully." << endl << endl;
		do
		{
			cout << "Enter Q to (Q)uit, Search (A)uthor, Search (T)itle, (S)how All" << endl;
			cin >> menuChoice;
			
			switch (toupper(menuChoice))
			{	
				case 'Q':
					return 0;
				case 'A':
					cout << "Search Author: ";
					cin >> name;
					showBooksByAuthor (count, name);
					cin.ignore (1000, '\n');
					break;
				case 'T':
					cout << "Search Title: ";	
					cin >> title;
					showBooksByTitle (count, title);
					cin.ignore (1000, '\n');
					break;
				case 'S':
					cout << "Showing all titles" << endl;
					showAll (count);
					cin.ignore (1000, '\n');
					break;
				default:
					cout << "Please select a valid option" << endl;
					cin.clear();
					cin.ignore (1000, '\n');
					break;
			}
		}	
		while (toupper(menuChoice != 'Q'));
	}
    return 0;
}

//write int loadData (string pathname);
int loadData (string pathname)
{	
	int count = 0;
	ifstream inFile;

	//open file with c-string conversion in order to be null terminated.
	inFile.open (pathname.c_str());
	
	//Check if file opens and print error message if it doesn't.
	if (! inFile.is_open())
	{
		return -1;
	}
	else
	{
		// read the data in the file into the two parallel arrays, and return the number of book records that it read.	
		getline (inFile, bookTitle [count]); 
		getline (inFile, bookAuthor [count]);
		
		while (count < ARRAY_SIZE && !inFile.eof())
		{
			count ++;
			getline (inFile, bookTitle [count]); 
			getline (inFile, bookAuthor [count]);
		}
	}
	inFile.close();

	return count;
}

//write function showAll.
void showAll (int count)
{
	int x = 0;
	int y = 0;
	
	while (x < count) 
	{
		cout << " " << bookTitle [x] << " (" << bookAuthor [x] << ")" << endl;
		x ++;
	}
	y = x / 2;
	cout << " " << y << " records found" << endl;
}

//write function showBooksByAuthor.
void showBooksByAuthor (int count, string name)
{
	int y = 0;
	
	for (int x = 0; x < count; x++)
	{
		//search string name withing bookAuthor, ignoring upper or lower cases.
		if (strcasestr(bookAuthor[x].c_str(), name.c_str()))
		{
			cout << " " << bookTitle [x] << " (" << bookAuthor [x] << ")" << endl;
			y++;
		}
	}
	cout << " " << y << " records found" << endl;
}
void showBooksByTitle (int count, string title)
{
	int y = 0;
	
	for (int x = 0; x < count; x++)
	{
		if (strcasestr(bookTitle[x].c_str(), title.c_str()))
		{
			cout << " " << bookAuthor [x] << " (" << bookTitle [x] << ")" << endl;
			y++;
		}
	}
	cout << " " << y << " records found" << endl;
}
