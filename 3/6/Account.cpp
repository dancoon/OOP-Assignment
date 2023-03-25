#include "Account.hpp"

Account::Account()
{
	balance = 10;
}

Account::Account(char name[256], string number, char t, double balance, bool chqbook)
{
	strcpy(customerName, name);
	number = number;
	type = type;
	balance = balance;
	chequebook = chqbook;
}

void Account::deposit(int amt)
{
	balance += amt;
}
void Account::withdraw(int amt)
{
	balance -= amt;
}
string Account::getName(void)
{
	return customerName;
}
void Account::display(void)
{
	cout << "Customer's name: " << customerName << endl;
	cout << "Account number: " << number << endl;
	cout << "Account type: ";
	if (type == 's')
		cout << "Saving account" << endl;
	else 
		cout << "Current account" << endl;
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

void Account::setCustomerName(char* name)
{
	strcpy(customerName, name);
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

