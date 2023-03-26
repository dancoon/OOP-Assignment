#include "Account.hpp"

Account::Account()
{
	balance = 0;
}

void Account::deposit(int amt)
{
	balance += amt;
}
void Account::withdraw(int amt)
{
	balance -= amt;
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
int Account::getNumber(void)
{
	return number;
}
void Account::setCustomerName(char* name)
{
	strcpy(customerName, name);
}
void Account::setBalance(double balance)
{
	balance = balance;
}
