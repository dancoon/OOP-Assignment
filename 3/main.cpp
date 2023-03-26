#include "main.hpp"

int main(void)
{
	int opt, n;
	char f;
	bool run = true;

	Curr_acct currAcct;
	Sav_acct savAcct;
 
	while (run)
	{
		opt = option();
		system("cls");
		switch (opt)
		{
			case 1:
				n = typeAcc();
				if (n == 1)
					currAcct.newCurrentAccount();
				else 
					savAcct.newSavingAccount();
				break;
			case 2:
				n = typeAcc();
				if (n == 1)
					currAcct.depositCurrentAccount();
				else 
					savAcct.depositSavingAccount();
				break;
			case 3:
				n = typeAcc();
				if (n == 1)
					currAcct.withdrawCurrentAccount();
				else
					savAcct.withdrawSavingAccount();
				break;
			case 4:
				n = typeAcc();
				if (n == 1)
					currAcct.checkBalanceCurrentAccount();
				else 
					savAcct.checkBalanceSavingAccount();
				break;
			case 5:
				system("cls");
				savAcct.listSavingAccount();
				currAcct.listCurrentAccount();
				system("pause");
				break;
			case 6:
				n = typeAcc();
				if (n == 1)
					currAcct.deleteCurrentAccount();
				else 
					savAcct.deleteSavingAccount();
				break;
			case 7:
				n = typeAcc();
				if (n == 1)
					currAcct.updateCurrentAccount();
				else 
					savAcct.updateSavingAccount();
				break;
			case 8:
				cout << "Are you sure you want to exit ?!" << endl;
				cout << "Enter y(yes) or n(no)" << endl;
				cin >> f;
				(f == 'y' || f == 'Y')? run = false: run = true;
				break;
			default:
				cout << "System error 104!!!" << endl;
				exit(1);
		}
	}
}
