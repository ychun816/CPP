// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include <vector>//for using std::vector
#include <algorithm>//for std::for_each
#include <functional>//for std::mem_fun_ref
#include "Account.hpp"

int		main( void ) {
    // Define type aliases for convenience
	typedef std::vector<Account::t>							  accounts_t;// Define type aliases for convenience
	typedef std::vector<int>								  ints_t;// Vector of integers
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;// Pair of iterators

	// Initialize an array of initial account balances
	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );// Calculate size of array

	// Create a vector of Account objects initialized with the amounts array
	accounts_t				accounts( amounts, amounts + amounts_size );
	accounts_t::iterator	acc_begin	= accounts.begin();// Iterator to beginning of accounts
	accounts_t::iterator	acc_end		= accounts.end();// Iterator to end of accounts

	// Initialize an array of deposit amounts
	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 };
	size_t const		d_size( sizeof(d) / sizeof(int) );// Calculate size of deposit array

	// Create a vector of deposits
	ints_t				deposits( d, d + d_size );
	ints_t::iterator	dep_begin	= deposits.begin();// Iterator to beginning of deposits
	ints_t::iterator	dep_end		= deposits.end();// Iterator to end of deposits

    // Initialize an array of withdrawal amounts
	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 };
	size_t const		w_size( sizeof(w) / sizeof(int) );// Calculate size of withdrawal array

	// Create a vector of withdrawals
	ints_t				withdrawals( w, w + w_size );
	ints_t::iterator	wit_begin	= withdrawals.begin();// Iterator to beginning of withdrawals
	ints_t::iterator	wit_end		= withdrawals.end(); // Iterator to end of withdrawals

	// Display all accounts' initial information
	// Display the status of each account
	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );
	// Iterate over accounts and deposit amounts, making deposits for each accountcs
	for ( acc_int_t it( acc_begin, dep_begin );
		  it.first != acc_end && it.second != dep_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeDeposit( *(it.second) );// Deposit the corresponding amount
	}

	// Display updated account information after deposits
	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );
	// Iterate over accounts and withdrawal amounts, making withdrawals for each account
	for ( acc_int_t it( acc_begin, wit_begin );
		  it.first != acc_end && it.second != wit_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeWithdrawal( *(it.second) );// Withdraw the corresponding amount
	}
	
	// Display updated account information after withdrawals
	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	return 0;
}


// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //
