#include <iostream>
#include <math.h>

using namespace std;

#define MIN_CHARGE 50.00

double charges(int units);

int main(void)
{
	int units;
	double amount;
	string name;

	cout << "Enter username: ";
	getline(cin, name);
	cout << "Enter number of units consumed: ";
	cin >> units;
	cout << endl;

	amount =  charges(units);
	cout << "Electricity Bill Charges" << endl;
	cout << "---------------------------" << endl;
	cout << "User: " + name << endl;
	cout << "Charges: " << amount << endl;
	
	return (0);
}

double charges(int units)
{
	int rem;
	double amount;

	rem = units - 100;
	amount = (rem < 0) ? units * 60 : 60 * 100;
	
	if (rem > 0)
	{
		rem -= 200;
		amount += (rem < 0) ? (200 + rem) * 80 : 200 * 80;
	}
	if (rem > 0)
	{
		rem -= 300;
		amount += (rem < 0) ? (300 + rem) * 90 : rem * 90;
	}
	if (amount > 300)
		amount += 0.15 * amount;
	if (units == 0)
		amount = 50.00;
	
	return (amount);
}

