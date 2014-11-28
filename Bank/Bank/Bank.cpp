#include "Bank.h"
#include <fstream>
#include <iostream>

//Getters
const vector<Customer*>& Bank::getCustomers() const { return pCustomers; } //Changed to const for iter

const vector<Account*>& Bank::getAccounts() const { return pAccounts; } //Changed to const for

const vector<Transaction*>& Bank::getTransactions() const { return pTransactions; }

//Setters
void Bank::setCustomer(Customer* Customer) { pCustomers.push_back(Customer); }

void Bank::setAccount(Account* Account) { pAccounts.push_back(Account); }

void Bank::setTransaction(Transaction* Transaction){ pTransactions.push_back(Transaction); }


//Functions

//Read customers file and store information into bank's customers vector
void Bank::readCustomers() {
	ifstream customer_file("customer_input.txt");
	if (!customer_file) {
		cout << "customer_input.txt not found." << endl;
	}
	while (!customer_file.eof()) {
		customer_file >> pCustomers;
	}
}

//Read account file and store information into bank's accounts vector
void Bank::readAccounts() {
	ifstream account_file("accounts_input.txt");
	if (!account_file) {
		cout << "accounts_input.txt not found." << endl;
	}
	while (!account_file.eof()) {
		account_file >> pAccounts;
	}
}

//Read transaction file and store transactions into proper account
void Bank::readTransactions() {
	ifstream transaction_file("transactions_input.txt");
	if (!transaction_file) {
		cout << "transactions_input.txt not found." << endl;
	}
	while (!transaction_file.eof()) {
		transaction_file >> pTransactions;
	}
}

//Menu Functions
void Bank::main_menu() {
	cout << "--Main Menu--" << endl;
	cout << "Enter 1 to add a new customer." << endl;
	cout << "Enter 2 to add a new account." << endl;
	cout << "Enter 3 to add a transaction to an existing account." << endl;
	cout << "Enter 4 to view customer Information" << endl;
	cout << "Enter 5 to print customer account statements" << endl;
	cout << "Enter 0 to exit application." << endl;
	int option = get_input();
	switch (option) {
	case 0:
		exit(0);
	case 1:
		customer_input_menu();
	case 2:
		account_input_menu();
	case 3:
		transaction_input_menu();
	case 4:
		customer_info_menu();
	case 5:
		print_customer_statements();
	}
}

//Get Input
int Bank::get_input() {
	int option;
	cin >> option;
	return option;
}

//Customer Input
void Bank::customer_input_menu() {
	cout << "--Customer Input Menu--" << endl << endl;
	int new_id, new_ssn;
	string new_first, new_last, new_address;
	cout << "First Name: "; cin >> new_first;
	cout << "Last Name: "; cin >> new_last;
	cout << "Social Security Number: "; cin >> new_ssn;
	cout << "Address: "; getline(cin, new_address); getline(cin, new_address);
	//We should check if ID is valid and unused
	cout << "Customer ID Number: "; cin >> new_id;
	Customer* new_customer = new Customer(new_id, new_ssn, new_first, new_last, new_address);
	pCustomers.push_back(new_customer);
	cout << "Successfully added customer." << endl;
	cout << "Enter 1 to add another customer." << endl;
	cout << "Enter 0 to return to the main menu." << endl;

	int option = get_input();
	switch (option) {
	case 0:
		main_menu();
	case 1:
		customer_input_menu();
	}
}

//Transaction Input
void Bank::transaction_input_menu() {
	cout << "Here you can input a transaction to an account." << endl;
	system("pause");
	cout << endl << endl << endl;
	main_menu();
}

//Account Input
void Bank::account_input_menu() {
	cout << "--Account Input Menu--" << endl;
	int number;
	double balance;
	Date date;
	cout << "Account Number: "; cin >> number;
	cout << "Opening Balance: "; cin >> balance;
	cout << "Date: "; cin >> date;
	Account* new_account = new Account(number, balance, date);
	pAccounts.push_back(new_account);
	cout << "Successfully added account." << endl;
	cout << "Enter 1 to add another account." << endl;
	cout << "Enter 0 to return to the main menu." << endl;
	int option = get_input();
	switch (option) {
	case 0:
		main_menu();
	case 1:
		account_input_menu();
	}
}

//Customer Info
void Bank::customer_info_menu() {
	cout << "--Customer Information Menu--" << endl << endl;
	vector<Customer*>::const_iterator iter;
	for (iter = pCustomers.begin();
		iter != pCustomers.end(); ++iter) {
		// We could probably overload an operator for this long bit
		cout << (*iter)->getId() << " " << (*iter)->getSocial() << " " <<
			(*iter)->getFirst() << " " << (*iter)->getLast() << (*iter)->getAddress() << endl;
	}
	main_menu();
}

//Print Customer Statements
void Bank::print_customer_statements() {
	int account_number;
	cout << "--Print a Customer Account--" << endl;
	cout << "Enter Account Number: " << endl;
	cin >> account_number;
	vector<Account*>::const_iterator iter;
	for (iter = pAccounts.begin();
		iter != pAccounts.end(); ++iter) {

	}
	// if this account list customer's account
	// on selection print that account (CD, Checking, Savings)
}