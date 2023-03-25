#include "Curr_Acct.hpp"

void Curr_acct::newCurrentAccount(void)
{
	int flag = 0;

	cout << "Enter customer name: ";
	cin >> customerName;
	cout << "Enter Account number: ";
	cin >> number;
	type = 'c';
	chequebook = true;

	ofstream file("currentaccount.dat", ios::binary | ios::app);
	if (file.is_open())
	{
		file.write((char*)this, sizeof(*this));
		flag = 1;
		file.close();
	}
	if (flag == 0)
		cout << "Error in writing to the database" << endl;
}

void Curr_acct::depositCurrentAccount(void)
{
	int flag = 0;
	fstream file;
	int num;
	double amt;

	cout << "Enter account number: ";
	cin >> num;

	file.open("currentaccount.dat", ios::in | ios::out | ios::binary | ios::ate);
	file.seekg(0);
	while (file.read(reinterpret_cast<char*>(this), sizeof(*this)))
	{
		if ((*this).number == num)
		{
			cout << "Enter amount to be deposited: ";
			cin >> amt;
			file.seekp(-sizeof(*this), ios::cur);
			(*this).deposit(amt);
			file.write(reinterpret_cast<char*>(this), sizeof(*this));
			flag = 1;
		}
	}
	if (flag == 0)
	{
		cout << "Account not found!" << endl;
	}
	
	file.close();
}

void Curr_acct::withdrawCurrentAccount(void)
{
	int flag = 0;
	fstream file;
	int num;
	double amt;

	cout << "Enter account number: ";
	cin >> num;

	file.open("currentaccount.dat", ios::in | ios::out | ios::binary | ios::ate);
	file.seekg(0);
	while (file.read(reinterpret_cast<char*>(this), sizeof(*this)))
	{
		if ((*this).number == num)
		{
			cout << "Enter amount to be withdrawn: ";
			cin >> amt;
			file.seekp(-sizeof(*this), ios::cur);
			(*this).withdraw(amt);
			file.write(reinterpret_cast<char*>(this), sizeof(*this));
			flag = 1;
		}
	}
	if (flag == 0)
	{
		cout << "Account not found!" << endl;
	}
	file.close();
}

void Curr_acct::checkBalanceCurrentAccount(void)
{
	int flag = 0, num;
	ifstream file("currentaccount.dat", ios::binary);
	if (!file.is_open())
	{
		cerr << "Error: failed to open file" << endl;
		return;
	}
	cout << "Enter Account number" << endl;
	cin >> num;
	while (file.read(reinterpret_cast<char*>(this), sizeof(*this)))
	{
		if ((*this).number == num)
		{
			cout << "Acc no:" << (*this).getNumber() << endl;
			cout << "Amount:" << (*this).balance <<endl;
			flag = 1;
			break;
		}
	}
	if (file.eof() && flag == 0)
	{
		cout << "Account not found" << endl;
	}
	file.close();
}

void Curr_acct::listCurrentAccount(void)
{
	int flag = 0;
	ifstream file("currentaccount.dat", ios::binary);
	if (!file.is_open())
	{
		cerr << "Error: failed to open file" << endl;
		return;
	}
	while (file.read(reinterpret_cast<char*>(this), sizeof(*this)))
	{
		(*this).display();
		cout << endl;
		flag = 1;
	}
}

void Curr_acct::deleteCurrentAccount(void)
{
	int flag = 0, num;
	ifstream file("currentaccount.dat", ios::binary);
	file.seekg(0, ios::beg);
	if (!file.is_open())
	{
		cerr << "Error: failed to open file" << endl;
		return;
	}
	cout << "Enter account number to delete: ";
	cin >> num;
	ofstream new_file("temp.dat", ios::binary | ios::app);
	while (file.read(reinterpret_cast<char*>(this), sizeof(*this)))
	{
		if((*this).number == num)
			flag++;
		else
			new_file.write(reinterpret_cast<char*>(this), sizeof(*this));
	}
	file.close();
	new_file.close();
	if (flag == 0)
	{
		remove("temp.dat");
		cout << "No such account in the database" << endl;
	}
	else
	{
		remove("currentaccount.dat");
		rename("temp.dat", "currentaccount.dat");
		cout << "Account successfully deleted" << endl;
	}
}

void Curr_acct::updateCurrentAccount(void)
{
	int flag = 0;
	fstream file;
	int num;
	double amt;
	char name[256];

	cout << "Enter account number: ";
	cin >> num;

	file.open("currentaccount.dat", ios::in | ios::out | ios::binary | ios::ate);
	file.seekg(0);
	while (file.read(reinterpret_cast<char*>(this), sizeof(*this)))
	{
		if ((*this).number == num)
		{
			cout << "Enter customer's new name: ";
			cin >> name;

			file.seekp(-sizeof(*this), ios::cur);
			(*this).setCustomerName(name);
			file.write(reinterpret_cast<char*>(this), sizeof(*this));
			flag = 1;
		}
	}
	if (flag == 0)
	{
		cout << "Account not found!" << endl;
	}
	
	file.close();
}
