// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

/** STEPS:
1. Constructor & Destructor
2. Static variable init & implement get-static-variable-value funcs
3. checkAmount
3. time stamp
4. displayAccountsInfos
5. makeDeposit
6. makeWithdrawal
7. displayStatus
*/

//initialize static variable
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

////CONSTRUCTOR
//member initialization list" or "constructor initialization list
Account::Account( int initial_deposit ):
_amount(initial_deposit),
_nbDeposits(0),
_nbWithdrawals(0)
{
    this->_accountIndex = _nbAccounts++;
    _totalAmount += initial_deposit;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "created" << std::endl;
}

////DESTRUCTOR
Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "closed" << std::endl;
}

////STATIC FUNCS
//get static variable values
int	Account::getNbAccounts( void )
{
    return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
    return _totalAmount;
}

int	Account::getNbDeposits( void )
{
    return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
    return _totalNbWithdrawals;
}

//display account info
void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";"
              << "amount:" << getTotalAmount() << ";"
              << "deposits:" << getNbDeposits() << ";"
              << "withdrawals:" << getNbWithdrawals() << std::endl;
}

///MEMBER FUNCS
/**makeDeposit
[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
*/
void	Account::makeDeposit( int deposit )
{
    this->_nbDeposits++; // Increments the number of deposits for this account
    _totalNbDeposits++; // Increments the total number of deposits for all accounts
    this->_amount += deposit; // Adds the deposit amount to the account balance
    _totalAmount += deposit; // Adds the deposit amount to the total amount for all accounts

    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
              << "p_amount" << (this->_amount - deposit) << ";"
              << "deposit:" << deposit << ";"
              << "amount:" << this->_amount << ";"
              << "nb_deposits:" << ":" << this->_nbDeposits << std::endl; 
}

/** makeWithdrawal
 * [19920104_091532] index:0;p_amount:47;withdrawal:refused
 * [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
*/
bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
              << "p_amount" << this->_amount << ":";

    // Checks if the account has enough money for withdrawal
    if (this->_amount >= withdrawal)
    {
        this->_amount -= withdrawal;//deduct withdrawal amount from account balance
        _totalAmount -= withdrawal;//deduct withdrawal amount from total amount for all accounts
        
        this->_nbWithdrawals++;// Increments the withdrawal count for this account
        _totalNbWithdrawals++;// Increments the total withdrawal count for all accounts
    
        //print withdrawl outcome
        std::cout << "withdrawal:" << withdrawal << ";"
                  << "amount:" << _amount << ";"
                  << "nb_withdrawals:" << _nbWithdrawals << std::endl;
        return true;
    }
    else
    {
        std::cout << "withdrawal:refused" << std::endl;
        return false;
    }
}

/** Check Amount -> How to check how to implement?:
-It's a simple getter method (marked as const which means it doesn't modify the object)
-Based on its name and the class context, it clearly returns the current account balance
*/
int Account::checkAmount(void) const
{
    return this->_amount;
}

/** display status*/
void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

////PRIVATE STATIC FUNC
/** time stamp
 * @note std::time_t std::time(nullptr);
 * -> std::time() Return current calendar time encoded as a time_t object,
 * -> which typically represented as seconds elapsed since the Unix epoch (January 1, 1970, 00:00:00 UTC).
 * -> nullptr (the value is only returned) / OR std::time_t std::time(arg); (Pointer to a time_t object to store the time value)
 * @note std::tm* timeinfo = std::localtime(&now);
 * -> tm structure containing the broken-down time! (ie. tm_sec, tm_min, tm_hour, tm_mday, tm_mon, tm_year)
 * @note struct tm* localtime(const time_t* timer);
 * -> converts a calendar time (stored as a time_t value) into a broken-down time structure, adjusted for the local timezone.
 * @note setfill()
 * -> fill character for padding when the field width is larger than the data to display.
*/
void	Account::_displayTimestamp( void )
{
    std::time_t now = std::time(NULL);// Get current time
    std::tm* timeinfo = std::localtime(&now);// Convert to local time components
    
    //format [19920104_091532]
    std::cout << "["
    //year&date
              << std::setfill('0') << std::setw(4) << (timeinfo->tm_year + 1900)
              << std::setfill('0') << std::setw(2) << (timeinfo->tm_mon + 1)
              << std::setfill('0') << std::setw(2) << timeinfo->tm_mday
              << "_"
    //hour,minute,second
              << std::setfill('0') << std::setw(2) << timeinfo->tm_hour
              << std::setfill('0') << std::setw(2) << timeinfo->tm_min
              << std::setfill('0') << std::setw(2) << timeinfo->tm_sec
              << "] ";
}
