#ifndef _CUR_ACCT_HPP_
#define _CUR_ACCT_HPP_

#include "Account.hpp"

class Curr_acct:private Account
{
	private:
	public:
		double getBalanceCurrAcct(void);
};

#endif
