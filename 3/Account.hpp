#ifndef _ACCOUNT_HPP_
#define _ACCOUNT_HPP_

#include <iostream>
#include <string.h>

using namespace std;

class Account
{
	protected:
		char customerName[256];
		int number;
		char type;
		double balance;
		bool chequebook;
	public:
		Account();
		void deposit(int amt);
		void withdraw(int amt);
		void display(void);
		int getNumber(void);
		void setCustomerName(char* name);
		void setBalance(double balance);
};

#endif
