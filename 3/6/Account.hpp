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
		Account(char* name, string number, char t, double balance, bool chqbook);
		void deposit(int amt);
		void withdraw(int amt);
		void display(void);
		int getNumber(void);
		string getName(void);
		double getBalance(void);
		void setCustomerName(char* name);
		void setNumber(int number);
		void setType(char type);
		void setBalance(double balance);
		void setChequeBook(bool chequeBook);
};

#endif
