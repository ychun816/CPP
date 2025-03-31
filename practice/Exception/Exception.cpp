#include "Exception.hpp"

//bank account constructor
BankAccount::BankAccount() : balance(0.0){};

BankAccount::BankAccount(double initialBalance) : balance(initialBalance)
{
    if (initialBalance >= 0)
    {
        // balance = initialBalance;
        std::cout << "Account created with initial balance of " << initialBalance << std::endl;
    }
    else
        throw std::invalid_argument("ARE U THIS POOR? NO NEGATIVE FIGURES");
}

BankAccount::~BankAccount(){};

////////////////////////////
//nested class - Transaction
BankAccount::Transaction::Transaction(std::string transac, double amount) : type(transac), amount(amount){};
BankAccount::Transaction::~Transaction(){};
void BankAccount::Transaction::display() const
{
    std::cout << "Transaction type: " << type << ", Amount: " << amount << std::endl;
}
////////////////////////////

void BankAccount::deposit(double amount)
{
    if (amount < 0) throw std::runtime_error("WHY U THINK U CAN DEPOSIT NEGATIVE AMMOUNT?");
    balance += amount;
    history.push_back(Transaction("Deposit", amount));//Stores Transaction History
    std::cout << "Deposited $" << amount
              << ", Current Balance: $" << balance << std::endl;
}

// Withdraw method with exception handling
void BankAccount::withdraw(double amount)
{
    try//two exceptions scenarios
    {
        if (amount > balance) throw std::runtime_error("U TOO GREEDY! INSUFFICIENT SAVINGS");
        if (amount < 0) throw std::runtime_error("CANNOT WITHDRAW NEGATIVE AMMOUNT");

        balance -= amount;
        history.push_back(Transaction("Withdraw", amount));
        std::cout << "Withdraw $" << amount
                  << ", Current balance: $" << balance << std::endl;
    }
    catch (const std::exception& except)//if transaction fails
    {
        //what() is a member function of std::exception that returns the error message
        std::cout << "Error: " << except.what() << std::endl;
    }
}

//for (const auto& transaction : history)
//auto → Compiler automatically deduces the type (Transaction) -> C++11
//std::vector<Transaction>::const_iterator is C++98-compliant.
//it->display(); calls display() on the Transaction object
void BankAccount::showHistory()
{
    std::cout << "\n=== Transaction History ===" << std::endl;
    for (std::vector<Transaction>::const_iterator it = history.begin(); it != history.end(); ++it)
        it->display();
}


int main() 
{
    BankAccount myAccount(100.0); // Create account with initial $100 balance

    try 
    {
        std::cout << "\ndeposit(50)" << std::endl;
        myAccount.deposit(50);   // Valid deposit
        std::cout << "\nwithdraw(30)" << std::endl;
        myAccount.withdraw(30);  // Valid withdrawal
        std::cout << "\nwithdraw(200)" << std::endl;
        myAccount.withdraw(200); // Will cause an exception (insufficient funds)
        std::cout << "\ndeposit(-10)" << std::endl;
        myAccount.deposit(-10);  // Will cause an exception (invalid deposit)
    }
    catch (const std::exception& except) 
    {
        std::cout << "Error: " << except.what() << std::endl;
    }

    myAccount.showHistory(); // Show all transactions

    return 0;
}