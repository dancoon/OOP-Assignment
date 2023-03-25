#include "Account.hpp"

Account::Account()
{
	balance = 10;
}

Account::Account(string name, string number, char t, double balance, bool chqbook)
{
	customerName = name;
	number = number;
	type = type;
	balance = balance;
	chequebook = chqbook;
}

void Account::deposit(void)
{
	int amt;

	cout << "Enter amount to deposit: ";
	cin >> amt;
	balance += amt;
}
void Account::display(void)
{
	cout << "Customer's name: " << customerName << endl;
	cout << "Account number: " << number << endl;
	cout << "Account type: ";
	if (type = 's')
		cout << "Saving account" << endl;
	else if (type == 'c')
		cout << "Current account" << endl;
	else
		cout << "" << endl;
	cout << "Balance: " << balance << endl;
}

double Account::getBalance(void)
{
	return balance;
}

int Account::getNumber(void)
{
	return number;
}

void Account::setCustomerName(string name)
{
	customerName = name;
}
void Account::setNumber(int number)
{
	number = number;
}
void Account::setType(char type)
{
	type = type;
}
void Account::setBalance(double balance)
{
	balance = balance;
}
void Account::setChequeBook(bool chequeBook)
{
	chequebook = chequeBook;
}

