#include <iostream>
#include <math.h>
#define RATE 0.16

using namespace std;

int menu(string name, string reg);
double simpleInterest(double deposit, int years);
double getDeposit(void);
int getYear(void);
double compoundFormula(double deposit, int years);

int main(void)
{	
	int option, years;
	string name, reg;
	double deposit, amount, interest;
	
	cout << "Enter student's name: " << endl;
	getline(cin, name);
	cout << "Enter student's registration number: " << endl;
	cin >> reg;
	do 
	{
		option = menu(name, reg);

		switch (option)
		{
			case 1:
				deposit = getDeposit();
				years = getYear();
				interest = simpleInterest(deposit, years);
				amount = deposit + interest;
				break;
			case 2:
				deposit = getDeposit();
				years = getYear();
				amount = compoundFormula(deposit, years); 
				interest = amount - deposit;
				break;
			default:
				cout << "\n Invalid choice!" << endl;
				break;
		}
	} while (option > 2 || option < 1);

	cout << "The Principle: " << deposit << endl;
	cout << "Acrued Amount: " << amount << endl;
	cout << "Interest Earned: " << interest << endl;

	return (0);
}

int menu(string name, string reg)
{
	int opt;
	
	cout << endl << "-------------------------------------------" << endl;
	cout << name + " " + reg << endl;
	cout << "-------------------------------------------" << endl;
	cout << "1. Saving Account" << endl;
	cout << "2. Fixed deposit" << endl;
	cout << "Enter your choice: ";
	cin >> opt;
	cout << endl;

	return (opt);
}

double simpleInterest(double deposit, int years)
{
	int interest;

	interest = deposit * RATE * years;
	return (interest);
}

double getDeposit(void)
{
	int dep;
	
	cout << "Enter amount deposited: ";
	cin >> dep;

	return (dep);
}

int getYear(void)
{
	int yr;

	cout << "Enter period in years: ";
	cin >> yr;
	cout << endl;
	return (yr);
}

double compoundFormula(double deposit, int years)
{
	int amt;

	amt = deposit * pow((1 + RATE), years);
	return (amt);
}
