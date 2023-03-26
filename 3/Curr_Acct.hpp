#ifndef _CUR_ACCT_HPP_
#define _CUR_ACCT_HPP_

#define MIN_BALANCE 500
#define SURCHARGE 0.05

#include "Account.hpp"
#include <fstream>
#include <stdlib.h>

class Curr_acct:public Account
{
	public:
		void newCurrentAccount(void);
		void depositCurrentAccount(void);
		void withdrawCurrentAccount(void);
		void checkBalanceCurrentAccount(void);
		void listCurrentAccount(void);
		void deleteCurrentAccount(void);
		void updateCurrentAccount(void);
};

#endif
