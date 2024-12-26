//lab01_2.cpp
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double diameter, pi = 3.14159, volume, surface_area, ratio;
	cout << "Enter the diameter of the sphere: ";
	cin >> diameter;
	double radius = diameter/2.0;
	volume = 4/3.0*pi*pow(radius,3);
	surface_area = 4*pi*pow(radius,2);
	ratio = volume/surface_area;
	cout << endl << "Volume of the sphere: " << volume << " cubic units";
	cout << endl << "Surface area of the sphere: " << surface_area << " square units";
	cout << endl << "Volume to Surface area ratio: " << ratio << " units" << endl;

	return 0;
}

