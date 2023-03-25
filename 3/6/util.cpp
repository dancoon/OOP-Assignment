#include "main.hpp"

int option(void)
{
	int opt = -1;
	do
	{
		cout << "BANKING SERVICES" << endl;
		cout <<"1. New Customer\n2. Deposit\n3. Withdraw\n4. Check Balance\n5. List Customers\n6. Delete Customer\n7. Update Customer Details\n8. Exit System" << endl; 
		cout << "Choose your option: ";
		cin >> opt;
	} while (opt < 1 || opt > 8);

	return (opt);
}

int typeAcc(void)
{
	int n;
	do
	{
		cout << "Choose type of account\n1. Current account\n2. Saving account\nOption: ";
		cin >> n;
	} while (n != 1 && n != 2);

	return n;
}

int searchSavingAccount(int num)
{
	Sav_acct acc;

	ifstream file("savingaccount.dat", ios::binary);
	if (!file.is_open())
	{
		cerr << "Error: failed to open file" << endl;
		return (-1);
	}
	while (file.read(reinterpret_cast<char*>(&acc), sizeof(acc)))
	{
		if (acc.getNumber() == num)
		{
			cout << "Acc no:" << acc.getNumber() << endl;
			break;
		}
		/* code */
	}
	if (file.eof())
	{
		cout << "Account not found" << endl;
	}
	file.close();
	return (0);
}

int searchCurrentAccount(int num)
{
	Curr_acct acc;

	ifstream file("currentaccount.dat", ios::binary);
	if (!file.is_open())
	{
		cerr << "Error: failed to open file" << endl;
		return (-1);
	}
	while (file.read(reinterpret_cast<char*>(&acc), sizeof(acc)))
	{
		if (acc.getNumber() == num)
		{
			cout << "Acc no:" << acc.getNumber() << endl;
			break;
		}
		/* code */
	}
	if (file.eof())
	{
		cout << "Account not found" << endl;
	}
	file.close();
	return (0);
}
