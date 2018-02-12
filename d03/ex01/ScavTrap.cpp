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

ScavTrap::ScavTrap(void)
{
  std::cout
  << "Starting bootup sequence"
  << std::endl
  << "\"Recompiling my combat code!\""
  << std::endl;
  this->name = "DEF4-LT";
  this->hp = 100;
  this->ep = 50;
  this->level = 1;
  this->meleeDMG = 20;
  this->rangeDMG = 10;
  this->armorDMGreduc = 3;
  return ;
}

ScavTrap::ScavTrap(std::string name)
{
  std::cout
  << "Starting bootup sequence"
  << std::endl
  << "\"Recompiling my combat code!\""
  << std::endl;
  this->name = name;
  this->hp = 100;
  this->ep = 50;
  this->level = 1;
  this->meleeDMG = 20;
  this->rangeDMG = 10;
  this->armorDMGreduc = 3;
  return ;
}

ScavTrap::~ScavTrap(void)
{
  std::cout
  << "\"I can't feel my fingers! Gah! I don't have any fingers!\""
  << std::endl;
  return ;
}

ScavTrap & ScavTrap::operator = (const ScavTrap &st)
{
  this->name = st.name;
  this->hp = st.hp;
  this->ep = st.ep;
  this->level = st.level;
  this->meleeDMG = st.meleeDMG;
  this->rangeDMG = st.rangeDMG;
  this->armorDMGreduc = st.armorDMGreduc;
  return *this;
}

void ScavTrap::set(std::string opt, int val)
{
  if (opt == "ENERGY")
    this->ep += val;
  return ;
}

int ScavTrap::get(std::string opt)
{
  if (opt == "ENERGY") return this->ep;
  else if (opt == "HP") return this->hp;
  return 0;
}

void ScavTrap::challengeNewcomer(int chal)
{
  typedef unsigned int (ScavTrap::*Actions)
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
    &ScavTrap::meleeAttack,
    &ScavTrap::rangedAttack
  };
  ((this->*(actions[std::rand() % 2]))
  (attacks[std::rand() % 5], challenges[chal]));
  return ;
}

unsigned int ScavTrap::rangedAttack(std::string atk, std::string const & target)
{
  std::cout
  << this->name
  << " popped a motherfuckin' cap in "
  << target
  << "'s ass with "
  << atk
  << " for "
  << this->rangeDMG
  << " points of damage "
  << std::endl
  << "\"Oh, quit falling to pieces.\""
  << std::endl;
  return this->rangeDMG;
}

unsigned int ScavTrap::meleeAttack(std::string atk, std::string const & target)
{
  std::cout
  << this->name
  << " slapped "
  << target
  << "'s face off with "
  << atk
  << " for "
  << this->meleeDMG
  << " points of damage "
  << std::endl
  << "\"WOW! I hit 'em!\""
  << std::endl;
  return this->meleeDMG;
}

void ScavTrap::takeDamage(unsigned int amount)
{
  this->hp -= amount + this->armorDMGreduc;
  this->hp = this->hp < 0 ?
  0 : this->hp > 100 ?
  100 : this->hp;

  std::cout
  << this->name
  << "'s hitpoints at "
  << this->hp
  << std::endl
  << "\"My robotic flesh! AAHH!\""
  << std::endl;
  return ;
}

void ScavTrap::beRepaired(unsigned int amount)
{
  this->hp += amount;
  this->hp = this->hp > 100 ? 100 : this->hp;
  std::cout
  << this->name
  << "'s hitpoints at "
  << this->hp
  << std::endl
  << "\"Good as new, I think. Am I leaking?\""
  << std::endl;
  return ;
}
