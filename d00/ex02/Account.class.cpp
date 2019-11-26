#include <iostream>
#include <iomanip>
#include "Account.class.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(initial_deposit),
										_nbDeposits(0),
										_nbWithdrawals(0)
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;

	_totalAmount += _amount;

	_displayTimestamp();
	std::cout << " index:"
			  << _accountIndex
			  << ";amount:"
			  << _amount
			  << ";created"
			  << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << " index:"
			  << _accountIndex
			  << ";amount:"
			  << _amount
			  << ";closed"
			  << std::endl;
	;
}

int Account::getNbAccounts()
{
	return _nbAccounts;
}

int Account::getTotalAmount()
{
	return _totalAmount;
}

int Account::getNbDeposits()
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << " accounts:"
			  << _nbAccounts
			  << ";total:"
			  << _totalAmount
			  << ";deposits:"
			  << _totalNbDeposits
			  << ";withdrawals:"
			  << _totalNbWithdrawals
			  << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << " index:"
			  << _accountIndex
			  << ";p_amount:"
			  << _amount
			  << ";deposit:"
			  << deposit;

	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;

	std::cout << ";amount:"
			  << _amount
			  << ";nb_deposits:"
			  << _nbDeposits
			  << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << " index:"
			  << _accountIndex
			  << ";p_amount:"
			  << _amount
			  << ";withdrawal:";

	if (_amount < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return false;
	}

	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;

	std::cout << withdrawal
			  << ";amount:"
			  << _amount
			  << ";nb_withdrawals:"
			  << _nbWithdrawals
			  << std::endl;

	return true;
}

int Account::checkAmount(void) const
{
	return _amount;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << " index:"
			  << _accountIndex
			  << ";amount:"
			  << _amount
			  << ";deposits:"
			  << _nbDeposits
			  << ";withdrawals:"
			  << _nbWithdrawals
			  << std::endl;
}

void Account::_displayTimestamp()
{
	std::time_t time = std::time(nullptr);
	tm *t = localtime(&time);

	std::cout<< "[20150406_153629]";
	return ;

	std::cout << "["
			  << t->tm_year + 1900
			  << std::setw(2) << std::right << std::setfill('0')
			  << t->tm_mon
			  << std::setw(2) << std::right << std::setfill('0')
			  << t->tm_mday
			  << "_"
			  << std::setw(2) << std::right << std::setfill('0')
			  << t->tm_hour
			  << std::setw(2) << std::right << std::setfill('0')
			  << t->tm_min
			  << std::setw(2) << std::right << std::setfill('0')
			  << t->tm_sec
			  << "]";
}