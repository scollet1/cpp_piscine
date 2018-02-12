/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:45:37 by scollet           #+#    #+#             */
/*   Updated: 2018/01/11 16:45:38 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::~ScavTrap(void)
{
  std::cout
  << "\"I can't feel my fingers! Gah! I don't have any fingers!\""
  << std::endl;
  return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(100, 100, 50, 50, 1,
name, 20, 15, 3)
{
  std::cout
  << "Starting bootup sequence"
  << std::endl
  << "\"Recompiling my combat code!\""
  << std::endl;
  return ;
}

ScavTrap::ScavTrap(const ScavTrap & f) : ClapTrap(100, 100, 50, 50, 1,
"DEFA-LT", 20, 15, 3)
{
  *this = f;
  return ;
}

ScavTrap & ScavTrap::operator = (const ScavTrap &st)
{
  this->setStr("NAME", st.getStr("NAME"));
  this->set("HP", st.get("HP"));
  this->set("EP", st.get("EP"));
  this->set("LVL", st.get("LVL"));
  this->set("MDMG", st.get("MDMG"));
  this->set("RDMG", st.get("RDMG"));
  this->set("ARMR", st.get("ARMR"));
  return *this;
}

void ScavTrap::challengeNewcomer(int chal)
{
  typedef unsigned int (ClapTrap::*Actions)
  (std::string atk, std::string const & target);
  std::string const attacks[] = {
    "Senseless Sacrifice",
    "Laser Inferno",
    "Pistol",
    "Melee",
    "Sniper Rifle"
  };
  std::string const challenges[] = {
    "Badass",
    "CL4P-TP",
    "Ya Momma",
    "Gaetan",
    "The Corrector"
  };
  Actions actions[2] = {
    &ClapTrap::meleeAttack,
    &ClapTrap::rangedAttack
  };
  ((this->*(actions[std::rand() % 2]))
  (attacks[std::rand() % 5], challenges[chal]));
  return ;
}
