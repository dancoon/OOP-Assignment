#include "main.hpp"

int main(void)
{
	int opt, n;

	Curr_acct currAcct;
	Sav_acct savAcct;
 
	opt = option();

	switch (opt)
	{
		case 1:
			n = typeAcc();
			if (n == 1)
				;
			else if (n == 2)
				savAcct.newSavingAccount();
			else
				cout << "Error in creating new customer!" << endl;
			break;
		case 2:
			n = typeAcc();
			if (n == 1)
				;
			else if (n == 2)
				searchSavingAccount(1);
			else
				cout << "Error in depositing amount!" << endl;
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		default:
			cout << "System error 104!!" << endl;
	}
}

