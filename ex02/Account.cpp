// ************************************************************************** //
//                                                                            //
//                Account.cpp for GlobalBanksters United                      //
//                Created on  : Thu Jan 08 10:54:00 2025                      //
//                Last update : Wed Jan 09 21:33:00 2025                      //
//       Made by : Alexy "aheitz" Heitz <aheitz@student.42mulhouse.fr>        //
//                                                                            //
// ************************************************************************** //

#include "./Account.hpp"

#include <ctime>
#include <iomanip>
#include <iostream>

/********************************************************************************/

#define	MONTH_OFFSET	1
#define	YEAR_OFFSET		1900

/********************************************************************************/
/*						Definitions of static members							*/
/********************************************************************************/

int	Account::_nbAccounts			= 0;
int	Account::_totalAmount			= 0;
int	Account::_totalNbDeposits		= 0;
int	Account::_totalNbWithdrawals	= 0;

/********************************************************************************/
/*			Functions to recover the cumulative data from the bank				*/
/********************************************************************************/

int	Account::getNbAccounts(void)	{ return _nbAccounts; }
int	Account::getTotalAmount(void)	{ return _totalAmount; }
int	Account::getNbDeposits(void)	{ return _totalNbDeposits; }
int	Account::getNbWithdrawals(void)	{ return _totalNbWithdrawals; }

/********************************************************************************/
/*					The constructor and destructor of account					*/
/********************************************************************************/

/**
 * @brief Construct a new Account object.
 * 
 * @param initial_deposit The initial customer deposit in the bank.
 */
Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts++), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	_totalAmount += _amount;

	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ';'
		<< "amount:" << _amount << ';'
		<< "created" << std::endl;
}

/**
 * @brief Destroy the Account object.
 * 
 */
Account::~Account(void) {
	--_nbAccounts;
	_totalAmount -= _amount;

	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ';'
		<< "amount:" << _amount << ';'
		<< "closed" << std::endl;
}

/********************************************************************************/
/*						Private function of the bank							*/
/********************************************************************************/

/**
 * @brief Displays the current time (in the format [YYMMDD.HHMMSS]).
 * 
 */
void	Account::_displayTimestamp(void) {
	std::time_t	current	= std::time(NULL);
	std::tm		*local	= std::localtime(&current);

	if (!local) {
		std::cerr << "[ERROR: Unable to retrieve local time] ";
		return;
	}

	std::cout << '['
		<< local->tm_year + YEAR_OFFSET
		<< std::setw(2) << std::setfill('0') << local->tm_mon + MONTH_OFFSET
		<< std::setw(2) << std::setfill('0') << local->tm_mday
		<< '_'
		<< std::setw(2) << std::setfill('0') << local->tm_hour
		<< std::setw(2) << std::setfill('0') << local->tm_min
		<< std::setw(2) << std::setfill('0') << local->tm_sec
		<< "] ";
}

/********************************************************************************/
/*						Public functions of the bank							*/
/********************************************************************************/

/**
 * @brief Displays all of the bank's information.
 * 
 */
void	Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout
		<< "accounts:" << getNbAccounts() << ';'
		<< "total:" << getTotalAmount() << ';'
		<< "deposits:" << getNbDeposits() << ';'
		<< "withdrawals:" << getNbWithdrawals() << std::endl;
}

/**
 * @brief Adds a deposit to the customer's account.
 * 
 * @param deposit The sum of the deposit.
 */
void	Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ';'
		<< "p_amount:" << _amount << ';'
		<< "deposit:" << deposit << ';'
		<< "amount:" << _amount + deposit << ';'
		<< "nb_deposits:" << ++_nbDeposits << std::endl;
	_amount			+= deposit;
	_totalAmount	+= deposit;
}

/**
 * @brief Withdraw a sum of a customer's account.
 * 
 * @param withdrawal The sum to be withdraw.
 * @return true: if the sum could have been withdrawn.
 * @return false: if the funds are insufficient.
 */
bool	Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	if (_amount >= withdrawal) {
		std::cout
			<< "index:" << _accountIndex << ';'
			<< "p_amount:" << _amount << ';'
			<< "withdrawal:" << withdrawal << ';'
			<< "amount:" << _amount - withdrawal << ';'
			<< "nb_withdrawals:" << ++_nbWithdrawals << std::endl;
		_amount			-= withdrawal;
		_totalAmount	-= withdrawal;
		return (true);
	}
	std::cout
		<< "index:" << _accountIndex << ';'
		<< "p_amount:" << _amount << ';'
		<< "withdrawal:refused" << std::endl;
	return (false);
}

/**
 * @brief Displays the information of a private customer.
 * 
 */
void	Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ';'
		<< "amount:" << _amount << ';'
		<< "deposits:" << _nbDeposits << ';'
		<< "withdrawals:" << _nbWithdrawals << std::endl;
}