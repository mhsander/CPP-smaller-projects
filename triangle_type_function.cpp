//Martha Sander - 02-17-2017
//Sources: none.
/*
Define an enumeration type, triangleType that has the values scalene, isosceles, equilateral, and noTriangle.  Write a function, triangleShape that takes as parameters three numbers, each of which represents the length of a side of a triangle.  The function should return the shape of the triangle. (Note: In a triangle, the sum of the lengths of any two sides is greater than the length of the third side.)
*/

#include <iostream>
#include <string>

using namespace std;

//Define enum triangleType.
enum TriangleType { SCALENE, ISOSCELES, EQUILATERAL, NO_TRIANGLE };

//declare function triangleShape prototype.
TriangleType triangleShape (double side1, double side2, double side3);

//declare function to convert enum in order to output result.
string convertEnum (TriangleType triangle);

int main ()
{
	//define variables.
	double side1, side2, side3;
	TriangleType triangle;

	//get triangle sides input.
	cout << "Please enter side one lenght: " << endl;
	cin >> side1;
	cout << "Please enter side two lenght: " << endl;
	cin >> side2;
	cout << "Please enter side three lenght: " << endl;
	cin >> side3;
	
	//call triangleShape function and assign value to triangle variable.
	triangle = triangleShape (side1, side2, side3);

	//output triangleType.
	cout << "The shape is " << convertEnum (triangle) << endl;
 	
	return 0;
}
	
//Write function triangleShape.
TriangleType triangleShape (double side1, double side2, double side3)
{
	TriangleType triangle;
	
	//determine shape.
	if ((side1 + side2) < side3 || (side1 + side3) < side2 || (side2 + side3) < side1)
		triangle = NO_TRIANGLE;

	else if (side1 == side2 && side1 == side3)
		triangle = EQUILATERAL;
	
	else if (side1 != side2 && side1 != side3 && side2 != side3)
		triangle = SCALENE;

	else	
		triangle = ISOSCELES;

	return triangle;
}

//convert enum function.
string convertEnum (TriangleType triangle)
{
	switch (triangle)
	{
		case NO_TRIANGLE:
			return "not a triangle";
		case EQUILATERAL:
			return "a equilateral triangle";
		case SCALENE:
			return "a scalene triangle";
		case ISOSCELES:
			return "an isosceles triangle";
	}
}

