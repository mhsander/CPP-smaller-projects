//Martha Sander - 01-27-2017 - Lab4 activity 2,
//Sources: none.
/*
In a right triangle, the square of the length of one side is equal to the sum of the squares of the lengths of the other two sides. Write a program that prompts the user to enter the lengths of three sides of a triangle and then outputs a message indicating whether the triangle is a right triangle.  Assume the user does not know the hypotenuse.  Meaning, you have to check all 3 sides to verify that it is a right-angled triangle.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main ()
{

	//Define variables.
	double side1 = 0, side2 = 0, side3 = 0;
 
	//Ask user to input the lengths of three sides of a triangle.
	cout << "Please enter each lenght of a triangle and click enter in between: " << endl;
	cout << "Lenght 1: " << endl;
	cin >> side1;
	cout << "Lenght 2: " << endl;
	cin >> side2;
	cout << "Lenght 3: " << endl;
	cin >> side3;
	cout << endl;

	//If else with calculation for each side to determine if triangle is a right triangle. 
	if (side1 * side1 + side2 * side2 == side3 * side3)
		cout << "This triangle is a right side triangle" << endl;
	else if (side1 * side1 + side3 * side3 == side2 * side2)
		cout << "This triangle is a right side triangle" << endl;
	else if (side2 * side2 + side3 * side3 == side1 * side1)
		cout << "This triangle is a right side triangle" << endl;
	else
		cout << "This triangle is not a right side triangle" << endl;

        return 0;
}
