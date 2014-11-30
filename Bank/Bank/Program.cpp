#include "Account.h"
#include "Bank.h"
#include "Customer.h"
#include "Date.h"
#include "Transaction.h"

int main() {
	Bank bank = Bank();

	//Read text files
	bank.readCustomers();
	bank.readAccounts();
	bank.readTransactions();
	bank.readAssociation();

	//Display main menu
	bank.main_menu();
	return 0;
}
