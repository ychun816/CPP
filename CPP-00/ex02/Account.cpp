// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include "Account.hpp"

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

// Constructor
Account::Account( int initial_deposit ):
//member initialization list" or "constructor initialization list
_accountIndex(_nbAccounts),
_amount(initial_deposit),
_nbDeposits(0),
_nbWithdrawals(0)
{
    _nbAccounts++;
    _totalAmount = _totalAmount + initial_deposit;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "created" << std::endl;
}

// Destructor
Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "closed" << std::endl;
}

//initialize static variable
static int	Account::_nbAccounts = 0;
static int	Account::_totalAmount = 0;
static int	Account::_totalNbDeposits = 0;
static int	Account::_totalNbWithdrawals = 0;

//get static variable values
static int	Account::getNbAccounts( void )
{
    return _nbAccounts;
}

static int	Account::getTotalAmount( void )
{
    return _totalAmount;
}

static int	Account::getNbDeposits( void )
{
    return _totalNbDeposits;
}

static int	Account::getNbWithdrawals( void )
{
    return _totalNbWithdrawals;
}

//Check Amount -> How to check how to implement?:
//-It's a simple getter method (marked as const which means it doesn't modify the object)
//-Based on its name and the class context, it clearly returns the current account balance
int Account::checkAmount(void) const
{
    return _amount;
}

/** time stamp
@note std::time_t std::time(nullptr);
-> std::time() Return current calendar time encoded as a time_t object,
-> which typically represented as seconds elapsed since the Unix epoch (January 1, 1970, 00:00:00 UTC).
-> nullptr (the value is only returned) / OR std::time_t std::time(arg); (Pointer to a time_t object to store the time value)
@note std::tm* timeinfo = std::localtime(&now);
-> tm structure containing the broken-down time! (ie. tm_sec, tm_min, tm_hour, tm_mday, tm_mon, tm_year)
@note struct tm* localtime(const time_t* timer);
-> converts a calendar time (stored as a time_t value) into a broken-down time structure, adjusted for the local timezone.
@note setfill()
-> fill character for padding when the field width is larger than the data to display.
*/
static void	Account::_displayTimestamp( void )
{
    // Get current time
    std::time_t now = std::time(nullptr);
    // Convert to local time components
    std::tm* timeinfo = std::localtime(&now);
    
    //format [19920104_091532]
    std::cout "[";
    //year&date
    std::cout << std::setfill('0') << std::setw(4) << (timeinfo->tm_year + 1900);//why +1900??
    std::cout << std::setfill('0') << std::setw(2) << (timeinfo->tm_mon + 1);//why + 1??cuz start frm jan(1)?
    std::cout << std::setfill('0') << std::setw(2) << timeinfo->tm_mday;
    std::cout "_";
    //hour,minute,second
    std::cout << std::setfill('0') << std::setw(2) << timeinfo->tm_hour;
    std::cout << std::setfill('0') << std::setw(2) << timeinfo->tm_min;
    std::cout << std::setfill('0') << std::setw(2) << timeinfo->tm_sec;
    std::cout "] ";
}

//display account info
static void	Account::displayAccountsInfos( void )
{
    std::cout << "accounts:" << getNbAccounts() << ";";
    std::cout << "amount:" << getTotalAmount() << ";";
    std::cout << "deposits:" << getNbDeposits() << ";";
    std::cout << "withdrawals:" << getNbWithdrawals() << ";";
}

//makeDeposit
//[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
void	makeDeposit( int deposit )
{
    int p_amount = _amount;

    
    //record the deposit
    //single amount&times
    _amount = _amount + deposit;
    _nbDeposits++;
    //total amount&times
    _totalAmount = _totalAmount + deposit;
    _totalNbDeposits++;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount" << p_amount << ";";
    std::cout << "deposit:" << deposit << ";"; 
    std::cout << "amount:" << _amount << ";";
    std::cout << "nb_deposits:" << ":" << nb_deposits << std::endl;
}

//makeWithdrawal
//[19920104_091532] index:0;p_amount:47;withdrawal:refused
//[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
bool	makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount" << _amount << ";";
    if (_amount < withdrawal)
    {
        std::cout << "withdrawal:refused" << std::endl;
        return false;
    }
    //record the withdrawal
    //single amount&times
    _amount = _amount - withdrawal;
    _nbWithdrawals++;
   //total amount&times
    _totalAmount = _totalAmount - withdrawal;
    _totalNbWithdrawals++;

    //print withdrawl outcome
    std::cout << "withdrawal:" << withdrawal << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}

//display status
void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "deposits:" << _nbDeposits << ";";
    std::cout << "withdrawals:" << _nbWithdrawals << ";";
}


///////
/** some notes
The syntax you're asking about is the initialization list in a C++ constructor. Let me break it down:

```cpp
Account::Account(int initial_deposit) : 
    _accountIndex(_nbAccounts), 
    _amount(initial_deposit), 
    _nbDeposits(0), 
    _nbWithdrawals(0) {
    // Constructor body
}
```

This is a constructor for the `Account` class that takes an `initial_deposit` parameter. The part after the colon (`:`) but before the opening curly brace `{` is called the "member initialization list" or "constructor initialization list."

Here's what it does:

1. It initializes class member variables directly, before the constructor body executes
2. The syntax is `member_variable(initial_value)`
3. Multiple initializations are separated by commas

In your specific example:
- `_accountIndex(_nbAccounts)` - Initializes `_accountIndex` with the current value of `_nbAccounts` (static class variable)
- `_amount(initial_deposit)` - Initializes `_amount` with the value passed to the constructor
- `_nbDeposits(0)` - Initializes `_nbDeposits` to 0
- `_nbWithdrawals(0)` - Initializes `_nbWithdrawals` to 0

This initialization happens before the code in the constructor body executes. Using the initialization list is:
- More efficient than assigning values in the constructor body
- Required for initializing constant members and reference members
- The only way to call base class constructors or other constructors of the same class

The constructor body (code inside the curly braces) then proceeds with other operations like incrementing counters and displaying information.

*/