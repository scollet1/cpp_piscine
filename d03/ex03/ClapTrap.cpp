/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:24:07 by scollet           #+#    #+#             */
/*   Updated: 2018/01/12 12:24:08 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(int h, int maxHp, int e, int maxEp,
int lvl, std::string nam, int mdmg, int rdmg, int armr) :
hp(h),
maxHP(maxHp),
ep(e),
maxEP(maxEp),
level(lvl),
name(nam),
meleeDMG(mdmg),
rangeDMG(rdmg),
armorDMGreduc(armr)
{
  return ;
}

ClapTrap::~ClapTrap(void)
{
  return ;
}

ClapTrap::ClapTrap(ClapTrap & f)
{
  *this = f;
  return ;
}

ClapTrap & ClapTrap::operator = (const ClapTrap &ft)
{
  this->name = ft.name;
  this->hp = ft.hp;
  this->ep = ft.ep;
  this->level = ft.level;
  this->meleeDMG = ft.meleeDMG;
  this->rangeDMG = ft.rangeDMG;
  this->armorDMGreduc = ft.armorDMGreduc;
  return *this;
}

void ClapTrap::set(std::string opt, int val)
{
  if (opt == "EP") this->ep = val;
  else if (opt == "HP") this->hp = val;
  else if (opt == "LVL") this->level = val;
  else if (opt == "MDMG") this->meleeDMG = val;
  else if (opt == "RDMG") this->rangeDMG = val;
  else if (opt == "ARMR") this->armorDMGreduc = val;
  return ;
}

int ClapTrap::get(std::string opt) const
{
  if (opt == "EP") return this->ep;
  else if (opt == "HP") return this->hp;
  else if (opt == "RDMG") return this->rangeDMG;
  else if (opt == "MDMG") return this->meleeDMG;
  else if (opt == "LVL") return this->level;
  return 0;
}

void ClapTrap::setStr(std::string opt, std::string str)
{
  if (opt == "NAME") this->name = str;
  return ;
}

std::string ClapTrap::getStr(std::string opt) const
{
  if (opt == "NAME") return this->name;
  return "NULL";
}

unsigned int ClapTrap::rangedAttack(std::string atk, std::string const & target)
{
  std::cout
  << this->getStr("NAME")
  << " popped a motherfuckin' cap in "
  << target
  << "'s ass with "
  << atk
  << std::endl
  << "\"Step right up, to the Bulletnator 9000!\""
  << std::endl;
  return this->get("RDMG");
}

unsigned int ClapTrap::meleeAttack(std::string atk, std::string const & target)
{
  std::cout
  << this->getStr("NAME")
  << " slapped "
  << target
  << "'s face off with "
  << atk
  << std::endl
  << "\"Ha ha ha! Fall before your robot overlord!\""
  << std::endl;
  return this->get("MDMG");
}

void ClapTrap::takeDamage(unsigned int amount)
{
  this->hp -= amount + this->get("ARMR");
  this->hp = (this->get("HP") < 0) ?
  0 : (this->get("HP") > 100) ?
  100 : this->get("HP");

  std::cout
  << this->name
  << "'s hitpoints at "
  << this->hp
  << std::endl
  << "\"Woah! Oh! Jeez!\""
  << std::endl;
  return ;
}

void ClapTrap::beRepaired(unsigned int amount)
{
  this->hp += amount;
  this->hp = this->hp > 100 ? 100 : this->hp;
  std::cout
  << this->name
  << "'s hitpoints at "
  << this->hp
  << std::endl
  << "\"Sweet life juice!\""
  << std::endl;
  return ;
}
