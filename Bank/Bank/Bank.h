#ifndef Bank_h
#define Bank_h

#include "Account.h"
#include "Customer.h"
#include <vector>


class Bank
{
public:
	//Getters
	const std::vector<Customer*>& getCustomers() const; //Changed to const for iter
	std::vector<Account*> getAccounts();

	//Setters
	void setCustomer(Customer*);
	void setAccount(Account*);

	//Read Functions
	void readCustomers();
	//void readAccounts();
	//void readTransactions();

	//Creation Functions
	void new_customer_menu();

private:
	std::vector<Customer*> pCustomers;
	std::vector<Account*> pAccounts;
};

#endif