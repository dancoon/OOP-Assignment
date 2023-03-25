#ifndef _CUR_ACCT_HPP_
#define _CUR_ACCT_HPP_

#include "Account.hpp"
#include <fstream>

class Curr_acct:public Account
{
	private:
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
