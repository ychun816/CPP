// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include "Account.hpp"

static int	Account::getNbAccounts( void )
{}
static int	Account::getTotalAmount( void )
{}
static int	Account::getNbDeposits( void )
{}
static int	Account::getNbWithdrawals( void )
{}
static void	Account::displayAccountsInfos( void )
{}

Account::Account( int initial_deposit )
{
    initial_deposit = 0;
}

Account::~Account()
{}


static int	_nbAccounts;
static int	_totalAmount;
static int	_totalNbDeposits;
static int	_totalNbWithdrawals;

static void	Account::_displayTimestamp( void )
{}

Account::Account( void )
{}