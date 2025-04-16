/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:09:38 by ankammer          #+#    #+#             */
/*   Updated: 2025/04/16 17:12:41 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initialDeposit)
{
    _displayTimestamp();
    _accountIndex = _nbAccounts;
    _nbAccounts++;
    _amount = initialDeposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _totalAmount += _amount;
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "created" << std::endl;
}
Account::~Account()
{
    _displayTimestamp();
    _nbAccounts--;
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "closed" << std::endl;
}

int Account::getNbAccounts(void)
{
    return (_nbAccounts);
}
int Account::getTotalAmount(void)
{
    return (_totalAmount);
}
int Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}
int Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}
void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";";
    std::cout << "total:" << _totalAmount << ";";
    std::cout << "deposits:" << _totalNbDeposits << ";";
    std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}
void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    _nbDeposits++;
    _totalNbDeposits++;
    _totalAmount += deposit;
    _amount += deposit;
    std::cout << "deposit:" << deposit << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}
bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    if (withdrawal > _amount)
    {
        std::cout << "withdrawal:refused" << std::endl;
        return (1);
    }
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    _totalAmount -= withdrawal;
    _amount -= withdrawal;
    std::cout << "withdrawal:" << withdrawal << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
    return (0);
}
int Account::checkAmount(void) const
{
    return (_amount);
}
void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "deposits:" << _nbDeposits << ";";
    std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
    char formatedTime[80];
    std::time_t actualTimeInSec = std::time(NULL);                                   // std::time(NULL) → retourne ce nombre de secondes
    struct tm *convertTime = std::localtime(&actualTimeInSec);                       // transformer ce nombre de secondes en une structure struct tm (AMJHMS)
    std::strftime(formatedTime, sizeof(formatedTime), "%Y%m%d_%H%M%s", convertTime); // formate cette struct tm en chaîne de caractères (dans un buffer) selon un modèle donnee
    std::cout << formatedTime << " ";
}