#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0, Account::_totalAmount = 0,
    Account::_totalNbDeposits = 0, Account::_totalNbWithdrawals = 0;


int	Account::getNbAccounts( void ) {
    return (Account::_nbAccounts);
};
int	Account::getTotalAmount( void ) {
    return (Account::_totalAmount);
};
int	Account::getNbDeposits( void ) {
    return (Account::_totalNbDeposits);
};
int	Account::getNbWithdrawals( void ) {
    return (Account::_totalNbWithdrawals);
};
void	Account::displayAccountsInfos( void ) {
    // [19920104_091532] accounts:8;total:21524;deposits:8;withdrawals:0
    Account::_displayTimestamp();
    std::cout << ' ';
    std::cout << "accounts:" << Account::getNbAccounts() << ';';
    std::cout << "total:" << Account::getTotalAmount() << ';';
    std::cout << "deposits:" << Account::getNbDeposits() << ';';
    std::cout << "withdrawals:" << Account::getNbWithdrawals();
    std::cout << std::endl;
};


Account::Account( int initial_deposit ) {
    // [19920104_091532] index:2;amount:957;created
    this->_accountIndex = Account::getNbAccounts();
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    Account::_nbAccounts++;
    Account::_totalAmount += initial_deposit;
    Account::_displayTimestamp();
    std::cout << ' ';
    std::cout << "index:" << this->_accountIndex << ';';
    std::cout << "amount:" << this->_amount << ';';
    std::cout << "created" << std::endl;
};
Account::~Account( void ) {
    // [19920104_091532] index:0;amount:47;closed
    Account::_displayTimestamp();
    std::cout << " ";
    std::cout << "index:" << this->_accountIndex << ';';
    std::cout << "amount:" << this->_amount << ';';
    std::cout << "closed";
    std::cout << std::endl;
};

void	Account::makeDeposit( int deposit ) {
    // [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
    Account::_displayTimestamp();
    std::cout << " ";
    std::cout << "index:" << this->_accountIndex << ';';
    std::cout << "p_amount:" << this->_amount << ';';
    std::cout << "deposit:" << deposit << ';';

    this->_amount += deposit;
    this->_nbDeposits++;
    Account::_totalNbDeposits++;
    Account::_totalAmount += deposit;

    std::cout << "amount:" << this->_amount << ';';
    std::cout << "nb_deposits:" << this->_nbDeposits;
    std::cout << std::endl;
};
bool	Account::makeWithdrawal( int withdrawal ) {
    // [19920104_091532] index:0;p_amount:47;withdrawal:refused
    // [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
    Account::_displayTimestamp();
    std::cout << " ";
    std::cout << "index:" << this->_accountIndex << ';';
    std::cout << "p_amount:" << this->_amount << ';';
    
    if (this->_amount - withdrawal >= 0) {
        this->_amount -= withdrawal;
        this->_nbWithdrawals++;
        Account::_totalNbWithdrawals++;
        Account::_totalAmount -= withdrawal;
        std::cout << "withdrawal:" << withdrawal << ';';
        std::cout << "amount:" << this->_amount << ';';
        std::cout << "nb_withdrawals:" << this->_nbWithdrawals;
        std::cout << std::endl;
        return (true);
    } else {
        std::cout << "withdrawal:refused" << std::endl;
        return (false);
    }
};
int		Account::checkAmount( void ) const {
    return (this->_amount);
};
void	Account::displayStatus( void ) const {
    // [19920104_091532] index:5;amount:0;deposits:0;withdrawals:0
    Account::_displayTimestamp();
    std::cout << " ";
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals;
    std::cout << std::endl;
};

void	Account::_displayTimestamp( void ) {
    // [19920104_091532]

    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);

    std::cout << '[';
    std::cout << (now->tm_year + 1900);
    std::cout << std::setfill('0') << std::setw(2) << now->tm_mon + 1;
    std::cout << std::setfill('0') << std::setw(2) << now->tm_mday;
    std::cout << '_';
    std::cout << now->tm_hour << now->tm_min << now->tm_sec << ']';
};

Account::Account( void ) {};