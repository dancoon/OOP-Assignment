#ifndef _SAV_HPP_
#define _SAV_HPP_

#include "Account.hpp"
#include <iostream>
#include <fstream>

using namespace std;

class Sav_acct:public Account
{
	public:
		void newSavingAccount(void);
		void depositSavingAccount(void);
};
#endif
