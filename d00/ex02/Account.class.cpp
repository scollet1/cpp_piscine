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

#include <ios>
#include <time.h>
#include <iomanip>
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

  std::cout << "["
  << (now->tm_year + 1900)
  << std::setfill('0') << std::setw(2) << (now->tm_mon + 1)
  << std::setfill('0') << std::setw(2) << now->tm_mday
  << "_"
  << std::setfill('0') << std::setw(2) << now->tm_hour
  << std::setfill('0') << std::setw(2) << now->tm_min
  << std::setfill('0') << std::setw(2) << now->tm_sec
  << "] ";
  return ;
}

Account::Account(int initial_deposit)
{
  static int INDEX = 0;

  Account::_displayTimestamp();

  Account::_accountIndex = INDEX;
  Account::_nbAccounts += 1;
  Account::_amount = initial_deposit;
  Account::_totalAmount += Account::_amount;
  Account::_totalNbDeposits = 0;
  Account::_totalNbWithdrawals = 0;
  Account::_nbDeposits = 0;
  Account::_nbWithdrawals = 0;
  std::cout
  << "index:" << Account::_accountIndex << ";"
  << "amount:" << initial_deposit << ";"
  << "created" << std::endl;

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
  return Account::_nbAccounts;
}

int	Account::getTotalAmount(void)
{
  return Account::_totalAmount;
}
int	Account::getNbDeposits(void)
{
  return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
  return Account::_totalNbWithdrawals;
}

int		Account::checkAmount(void) const
{
  return Account::_amount;
}

void	Account::displayAccountsInfos(void)
{
  Account::_displayTimestamp();

  std::cout
  << "accounts:" << Account::getNbAccounts() << ";"
  << "total:" << Account::getTotalAmount() << ";"
  << "deposits:" << Account::getNbDeposits() << ";"
  << "withdrawals:" << Account::getNbWithdrawals()
  << std::endl;

  return ;
}

void	Account::makeDeposit(int deposit)
{
  Account::_displayTimestamp();

  std::cout
  << "index:" << Account::_accountIndex << ";"
  << "p_amount:" << Account::_amount << ";";

  Account::_amount += deposit;
  Account::_totalAmount += deposit;
  Account::_nbDeposits += 1;
  Account::_totalNbDeposits += 1;

  std::cout
  << "deposit:" << deposit << ";"
  << "amount" << Account::_amount << ";"
  << "nb_deposits:" << Account::_nbDeposits
  << std::endl;
  return ;
}

bool	Account::makeWithdrawal(int withdrawal)
{
  Account::_displayTimestamp();

  if (Account::_amount - withdrawal >= 0)
  {
    std::cout
    << "index:" << Account::_accountIndex << ";"
    << "p_amount:" << Account::_amount << ";";

    Account::_amount -= withdrawal;
    Account::_totalAmount -= withdrawal;
    Account::_nbWithdrawals += 1;
    Account::_totalNbWithdrawals += 1;

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
