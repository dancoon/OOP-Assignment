#include "Sav_Acct.hpp"

void Sav_acct::newSavingAccount(void)
{
	int flag = 0;

	cout << "Enter customer name: ";
	cin >> customerName;
	cout << "Enter Account number: ";
	cin >> number;
	type = 's';
	chequebook = false;

	ofstream file("savingaccount.dat", ios::binary | ios::app);
	if (file.is_open())
	{
		file.write((char*)this, sizeof(*this));
		flag = 1;
		file.close();
	}
	if (flag == 0)
		cout << "Error in writing to the database" << endl;
}

void Sav_acct::depositSavingAccount(void)
{
	deposit();
}
 
