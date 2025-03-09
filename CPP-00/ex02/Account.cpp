// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include "Account.hpp"

/**
1. Constructor & Destructor
2. Static variable init & implement get-static-variable-value funcs
3. 

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



//time stamp
static void	Account::_displayTimestamp( void )
{
    
}






//display account info
static void	Account::displayAccountsInfos( void )
{
    std::cout << "accounts:" << getNbAccounts() << ";";
    std::cout << "amount:" << getTotalAmount() << ";";
    std::cout << "deposits:" << getNbDeposits() << ";";
    std::cout << "withdrawals:" << getNbWithdrawals() << ";";
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