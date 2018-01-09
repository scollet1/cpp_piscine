/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 10:40:28 by scollet           #+#    #+#             */
/*   Updated: 2018/01/08 10:40:29 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>
#include "Account.class.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp(void)
{
  time_t t = time(0);
  struct tm *now = localtime(&t);

  std::cout
  << "["
  << (now->tm_year + 1900)
  << (now->tm_mon + 1)
  << now->tm_mday
  << "_"
  << now->tm_hour
  << now->tm_min
  << now->tm_sec
  << "] ";
  return ;
}

Account::Account(int initial_deposit)
{
  static int INDEX = 0;

  Account::_displayTimestamp();

  Account::_accountIndex = INDEX;
  std::cout
  << "index:" << Account::_accountIndex << ";"
  << "amount:" << initial_deposit << ";"
  << "created" << std::endl;

  Account::_totalAmount = Account::_amount = initial_deposit;
  INDEX += 1;
  return ;
}

Account::~Account(void)
{
  Account::_displayTimestamp();

  std::cout
  << "index:" << Account::_accountIndex << ";"
  << "amount:" << Account::_amount << ";"
  << "closed" << std::endl;
  Account::_nbAccounts -= 1;
  return ;
}

int	Account::getNbAccounts(void)
{
  Account::_displayTimestamp();

  std::cout
  << "accounts:" << Account::_nbAccounts << ";"
  << "total:" << Account::_totalAmount << ";"
  << "deposits:" << Account::_totalNbDeposits << ";"
  << "withdrawals:" << Account::_totalNbWithdrawals
  << std::endl;

  return Account::_nbAccounts;
}

int	Account::getTotalAmount(void)
{
  Account::_displayTimestamp();

  std::cout
  << "index:" << Account::_nbAccounts << ";"
  << "total:" << Account::_totalAmount << ";"
  << "deposits:" << Account::_totalNbDeposits << ";"
  << "withdrawals:" << Account::_totalNbWithdrawals
  << std::endl;
  return Account::_totalAmount;
}
int	Account::getNbDeposits(void)
{
  Account::_displayTimestamp();

  std::cout
  << "accounts:" << Account::_nbAccounts << ";"
  << "total:" << Account::_totalAmount << ";"
  << "deposits:" << Account::_totalNbDeposits << ";"
  << "withdrawals:" << Account::_totalNbWithdrawals
  << std::endl;
  return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
  return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void)
{
  Account::_displayTimestamp();

  std::cout
  << "accounts:" << Account::_nbAccounts << ";"
  << "total:" << Account::_totalAmount << ";"
  << "deposits:" << Account::_totalNbDeposits << ";"
  << "withdrawals:" << Account::_totalNbWithdrawals
  << std::endl;

  return ;
}

void	Account::makeDeposit(int deposit)
{
  Account::_displayTimestamp();

  std::cout
  << "index:" << Account::_nbAccounts << ";"
  << "p_amount:" << Account::_amount << ";";

  Account::_amount += deposit;

  std::cout
  << "amount" << Account::_amount << ";"
  << "deposit:" << deposit << ";"
  << "nb_deposits:" << Account::_nbDeposits
  << std::endl;
  return ;
}

bool	Account::makeWithdrawal(int withdrawal)
{
  Account::_displayTimestamp();

  if (Account::_amount - withdrawal >= 0)
  {
    Account::_nbWithdrawals += 1;
    std::cout
    << "index:" << Account::_accountIndex << ";"
    << "p_amount:" << Account::_amount << ";";

    Account::_amount -= withdrawal;

    std::cout
    << "withdrawal:" << withdrawal << ";"
    << "amount:" << Account::_amount << ";"
    << "nb_withdrawals:" << Account::_nbWithdrawals
    << std::endl;
    return true;
  }
  std::cout
  << "index:" << Account::_accountIndex << ";"
  << "p_amount:" << Account::_amount << ";"
  << "withdrawal:refused" << std::endl;
  return false;
}

int		Account::checkAmount(void) const
{
  Account::_displayTimestamp();

  std::cout
  << "accounts:" << Account::_nbAccounts << ";"
  << "total:" << Account::_totalAmount << ";"
  << "deposits:" << Account::_totalNbDeposits << ";"
  << "withdrawals:" << Account::_totalNbWithdrawals
  << std::endl;
  return Account::_totalAmount;
}

void	Account::displayStatus(void) const
{
  Account::_displayTimestamp();

  std::cout
  << "index:" << Account::_accountIndex << ";"
  << "amount:" << Account::_amount << ";"
  << "deposits:" << Account::_nbDeposits << ";"
  << "withdrawals:" << Account::_nbWithdrawals
  << std::endl;
  return ;
}
