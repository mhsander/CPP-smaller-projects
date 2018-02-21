// Martha Sander - 01-23-2017 - Assignment 2.
// Sources: none.
/*
Write a program to evaluate the fuel consumption of a car. The mileage at the start and end of the journey should be read, and also the fuel level in the tank at the start and end of the journey. Calculate fuel used, miles travelled, and hence the overall fuel consumption in miles travelled per gallon of fuel.
In many countries using the metric system, car fuel consumptions are measured in liters of fuel required to travel 100 kilometers. Modify your solution so that the output now specifies the distance travelled in kilometers as well as in miles, and the fuel consumed in liters as well as in gallons, and the consumption in liters per 100 kilometers as well as in miles per gallon. Use const for the conversion factors between miles and kilometers, and gallons and liters.
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


int main ()
{

	const double  MILE = 1.609;
	const double  GALLON = 3.785;
	double mileageStart = 0, mileageEnd = 0;
	double fuelStart = 0, fuelEnd = 0, fuelConsumption = 0, fuelUsed = 0;
	double milesTraveled = 0, milesUsed = 0;;

	//Format output to two decimal places.
	cout << fixed << showpoint << setprecision(2);

	//Get mileageStart and mileageEnd.
	cout << "Enter starting mileage: ";
	cin >> mileageStart;
	cout << "Enter ending mileage: ";
	cin >> mileageEnd;

	//Get fuelStar and fuelEnd in gallons.
	cout << "Enter fuel at the start in gallons: ";
	cin >> fuelStart;
	cout << "Enter fuel at the end in gallons: ";
	cin >> fuelEnd;
	cout << endl;

	//Calculate mileage traveled, fuel used and fuel consumption.
	milesTraveled = mileageEnd - mileageStart;
	fuelUsed = fuelStart - fuelEnd;
	fuelConsumption = milesTraveled / fuelUsed;
	
	//Print milesTraveled, fuelUsed and fuel consumption in miles.
	cout << "Total miles traveled: " << milesTraveled << " miles" << endl;
	cout << "Fuel used: " << fuelUsed << " gallons" << endl;
	cout << "The fuel consumption is " << fuelConsumption << " miles per gallon" << endl << endl;

	//Print values in liters and kms. Calculate the consumption in liters per 100 kilometers.
	cout << "Total kilometers traveled: " << milesTraveled * MILE << endl;
	cout << "Fuel used: " << fuelUsed * GALLON << " liters" << endl;
	cout << "Liters per 100 kilometers: " << (fuelUsed * GALLON) / (milesTraveled * MILE) * 100 << endl;

        return 0;
}
