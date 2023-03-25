#ifndef _ACCOUNT_HPP_
#define _ACCOUNT_HPP_

#include <iostream>

using namespace std;

class Account
{
	protected:
		string customerName;
		int number;
		char type;
		double balance;
		bool chequebook;
	public:
		Account();
		Account(string name, string number, char t, double balance, bool chqbook);
		void deposit(void);
		void display(void);
		int getNumber(void);
		double getBalance(void);
		void setCustomerName(string name);
		void setNumber(int number);
		void setType(char type);
		void setBalance(double balance);
		void setChequeBook(bool chequeBook);
};

#endif
