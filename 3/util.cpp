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
	Sav_acct acc, search_acc;

	search_acc.setNumber(num);
	ifstream file("savingaccount.dat", ios::binary);
	file.seekg(0, ios::beg);

	if (!file.is_open())
		cout << "Error opening File!" << endl;
	else
	{
		while (file.read(reinterpret_cast<char*>(&acc), sizeof(acc)))
		{
			if (acc.getNumber() == search_acc.getNumber())
			{
				cout << "Found object!" << endl;
				break;
			}
			//if (acc.getNumber() == num)
			//{
				//acc.display();
			//	break;
			//}
		}
		if (!file.eof())
			cout << "No such record!" << endl;
		file.close();
	}
	return (0);
}
