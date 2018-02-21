//Martha Sander - 03-07-2017.
//Sources: none.
//Program to read file wth students names and scores and to output file with last name, first name, score and grade.

#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

//declare const for student number so it can be easily changed if needed.
const int NUM_STUDENTS = 20;

//declare struct before any function prototype, to become available during any part of the program.
struct StudentType
{
	string studentFName;
	string studentLName;
	int testScore;
	char grade;
} student;

//function to open file and read data into an array.
int loadData (StudentType studentList[]);

//function to assign the relevant grade to each student.
void assignGrade (StudentType studentList[], int actualStudents);

void saveFile (StudentType studentList[], int actualStudents);

int main ()
{
	//declare variables.
	StudentType studentList[NUM_STUDENTS];
	int actualStudents = 0;

	actualStudents = loadData (studentList);
	
	assignGrade (studentList, actualStudents);

	saveFile (studentList, actualStudents);
 			
    return 0;
}

//write int loadData (string pathname);
int loadData (StudentType studentList[])
{	
	int count = 0, actualStudents = 0;
	ifstream inFile;
	char userChoice = ' ';
	string pathname;

	do 
	{		
		cout << "Please enter file name with pathname" << endl;
		getline (cin, pathname);

		inFile.open(pathname.c_str());
		
		if (! inFile.is_open())
		{
			cout << "The file is not open. Would you like to try again? Enter y for yes, any other to exit." << endl;
			cin >> userChoice;
			cin.clear();
			cin.ignore(100, '\n');
		
			if (tolower(userChoice) != 'y')
				return 0;;
 		}
		else	
		{	
			inFile >> studentList[count].studentFName >> studentList[count].studentLName >> studentList[count].testScore;
			count++;
	
			while (count < NUM_STUDENTS && !inFile.eof())
			{
				inFile >> studentList[count].studentFName >> studentList[count].studentLName >> studentList[count].testScore;
				count++;
				actualStudents++;
			}	
		}
	}
	while (tolower (userChoice) == 'y' && (! inFile.is_open()));

	inFile.close();
	inFile.clear();

	return actualStudents;
}
//write assignGrade function.
void assignGrade (StudentType studentList[], int actualStudents)
{
	for (int count = 0; count < actualStudents; count++)
	{
		if (studentList[count].testScore >= 90)
			studentList[count].grade = 'A';
		else if (studentList[count].testScore >= 80)
			studentList[count].grade = 'B';
		else if (studentList[count].testScore >= 70)	
			studentList[count].grade = 'C';
		else if (studentList[count].testScore >= 60)
			studentList[count].grade = 'D';
		else studentList[count].grade = 'F';
	}
}
//write function to output to file.
void saveFile (StudentType studentList[], int actualStudents)
{
	ofstream outFile; 
	int count = 0;
	string outFileName;

	cout << "Please enter the file name to safe the results" << endl;
	getline (cin, outFileName);

	outFile.open (outFileName.c_str());

	for (count = 0; count < actualStudents; count++)
	{
	outFile << studentList[count].studentLName << ", " << studentList[count].studentFName << " " << studentList[count].testScore << " " << studentList[count].grade << endl;
	}

	outFile.close();
}
	
