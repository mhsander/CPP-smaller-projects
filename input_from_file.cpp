// Martha Sander - 01-21-2017
//Sources: none.

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

int main ()
{

	ifstream inFile;
	ofstream outFile;

	//Define variables.

	string firstName = "";
	string lastName = "";
	int payIncrease = 0;
	double currentSalary = 0;
	double updatedSalary = 0;

	//Define file input and file output.

	inFile.open ("Ch3_Ex6Data.txt");
	outFile.open ("Ch3_Ex6Output.dat");

	outFile << fixed << showpoint;
	outFile << setprecision (2);

	//Get input and output first name, last name and updated salary.

	inFile >> lastName >> firstName >> currentSalary >> payIncrease;

	//Make calculation to determine updatedSalary.
	updatedSalary = currentSalary * (static_cast<double>(payIncrease) / 100) + currentSalary; 

	//Output file.
	outFile << " " << firstName << " " << lastName << " " << updatedSalary << endl;
	
	//Repeat for the other employees.
	inFile >> lastName >> firstName >> currentSalary >> payIncrease;

	updatedSalary = currentSalary * (static_cast<double>(payIncrease) / 100) + currentSalary; 

	outFile << " " << firstName << " " << lastName << " " << updatedSalary << endl;

	inFile >> lastName >> firstName >> currentSalary >> payIncrease;

	updatedSalary = currentSalary * (static_cast<double>(payIncrease) / 100) + currentSalary; 

	outFile << " " << firstName << " " << lastName << " " << updatedSalary << endl;

    return 0;
}
