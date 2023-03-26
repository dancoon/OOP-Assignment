#include "Sav_Acct.hpp"

void Sav_acct::newSavingAccount(void)
{
	int flag = 0;

	system("cls");
	cout << "ADD NEW CUSTOMER:" << endl;
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
	else
		cout << "Account created !!!\nAccount number: "<< (*this).number << endl << "Customer's name: " << (*this).customerName << endl;
	system("pause");
}	

void Sav_acct::depositSavingAccount(void)
{
	int flag = 0, num;
	fstream file;
	double amt;

	system("cls");
	cout << "DEPOSIT AMOUNT !!!" << endl;
	cout << "Enter account number: ";
	cin >> num;

	file.open("savingaccount.dat", ios::in | ios::out | ios::binary | ios::ate);
	if (file.is_open())
	{
		file.seekg(0);
		while (file.read(reinterpret_cast<char*>(this), sizeof(*this)))
		{
			if ((*this).number == num)
			{
				system("cls");
				cout << "Customer name: " << (*this).customerName << endl;
				cout << "Account number: " << (*this).number << endl;
				cout << "Enter amount to be deposited: ";
				cin >> amt;
				file.seekp(-sizeof(*this), ios::cur);
				(*this).deposit(amt);
				file.write(reinterpret_cast<char*>(this), sizeof(*this));
				flag = 1;
			}
		}
		file.close();
	}
	if (flag == 0)
		cout << "Error!!! Account not found!" << endl;
	else
		cout << "Amount deposited !!!" << endl;
	system("pause");
}

void Sav_acct::withdrawSavingAccount(void)
{
	int flag = 0;
	fstream file;
	int num;
	double amt;

	system("cls");
	cout << "WITHDRAW AMOUNT FROM ACCOUNT !!!" << endl;
	cout << "Enter account number: ";
	cin >> num;

	file.open("savingaccount.dat", ios::in | ios::out | ios::binary | ios::ate);
	if (!file.is_open())
	{
		cout << "Could not open file !!!" << endl;
		return;
	}
	file.seekg(0);
	while (file.read(reinterpret_cast<char*>(this), sizeof(*this)))
	{
		if ((*this).number == num)
		{
			system("cls");
			cout << "Customer name: " << (*this).customerName << endl;
			cout << "Account number: " << (*this).number << endl;
			cout << "Enter amount to be withdrawn: ";
			cin >> amt;
			(*this).setBalance(amt);
			file.seekp(-sizeof(*this), ios::cur);
			file.write(reinterpret_cast<char*>(this), sizeof(*this));
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		cout << "Account not found!" << endl;
	else
		cout << "Amount withdrawn !!!" << endl << "New balance: " << (*this).balance << endl;
	file.close();
	system("pause");
}

void Sav_acct::checkBalanceSavingAccount(void)
{
	int flag = 0, num;
	ifstream file("savingaccount.dat", ios::binary);
	if (!file.is_open())
	{
		cerr << "Error: failed to open file" << endl;
		return;
	}
	system("cls");
	cout << "CHECK BALANCE !!!" << endl;
	cout << "Enter Account number" << endl;
	cin >> num;
	while (file.read(reinterpret_cast<char*>(this), sizeof(*this)))
	{
		if ((*this).number == num)
		{
			cout << "Customer's name: " << (*this).customerName << endl;
			cout << "Account no: " << (*this).getNumber() << endl;
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
	system("pause");
}

void Sav_acct::listSavingAccount(void)
{
	int flag = 0;
	ifstream file("savingaccount.dat", ios::binary);
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

void Sav_acct::deleteSavingAccount(void)
{
	int flag = 0, num;
	ifstream file("savingaccount.dat", ios::binary);
	file.seekg(0, ios::beg);
	if (!file.is_open())
	{
		cerr << "Error: failed to open file" << endl;
		return;
	}
	system("cls");
	cout << "DELETE ACCOUNT !!!";
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
		remove("savingaccount.dat");
		rename("temp.dat", "savingaccount.dat");
		cout << "Account successfully deleted" << endl;
	}
}

void Sav_acct::updateSavingAccount(void)
{
	int flag = 0;
	fstream file;
	int num;
	double amt;
	char name[256];

	system("cls");
	cout << "UPDATE CUSTOMER'S DETAILS !!!" << endl;
	cout << "Enter account number: ";
	cin >> num;

	file.open("savingaccount.dat", ios::in | ios::out | ios::binary | ios::ate);
	if (file.is_open())
	{
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
		file.close();
	}
	if (flag == 0)
		cout << "Account not found!" << endl;
}
