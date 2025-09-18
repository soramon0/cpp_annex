#include "Account.hpp"

Account::Account() {
	// _nbAccounts = 0;
	// _totalAmount = 0;
	// _totalNbDeposits = 0;
	// _totalNbWithdrawals = 0;

	_accountIndex = 0;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
}

Account::Account(int initial_deposit) {

	_accountIndex = 0;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
}

int Account::getNbAccounts() { return _nbAccounts; }
int Account::getTotalAmount() { return _totalAmount; }
int Account::getNbDeposits() { return _totalNbDeposits; }
int Account::getNbWithdrawals() { return _totalNbDeposits; }

void Account::displayAccountsInfos() {
	// Implmenet
}

void Account::_displayTimestamp() {
	// Implmenet
}
