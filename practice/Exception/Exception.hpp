#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <iostream>
#include <string>
#include <vector>


class BankAccount
{
    private:
        double balance;

    // public:
        class Transaction
        {
            public:
                std::string type;
                double amount;

                Transaction(std::string transac, double amount);
                ~Transaction();
                void display() const;
        };
    
    std::vector<Transaction> history; // Stores transaction history

    public:
        BankAccount();
        BankAccount(double initialBalance);
        ~BankAccount();

        void deposit(double amount);
        void withdraw(double amount);
        void showHistory();
};


#endif