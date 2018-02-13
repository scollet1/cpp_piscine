/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:45:37 by scollet           #+#    #+#             */
/*   Updated: 2018/01/11 16:45:38 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
  std::cout
  << "Starting bootup sequence"
  << "\"Directive one: Protect humanity!\
  Directive two: Obey Jack at all costs.\
  Directive three: Dance!\""
  << std::endl;
  name = "DEFR-4G";
  hp = 100;
  ep = 100;
  level = 1;
  meleeDMG = 30;
  rangeDMG = 20;
  armorDMGreduc = 5;
  return ;
}

FragTrap::FragTrap(std::string name)
{
  std::cout
  << "Starting bootup sequence"
  << std::endl
  << "\"Directive one: Protect humanity!\
  Directive two: Obey Jack at all costs.\
  Directive three: Dance!\""
  << std::endl;
  this->name = name;
  this->hp = 100;
  this->ep = 100;
  this->level = 1;
  this->meleeDMG = 30;
  this->rangeDMG = 20;
  this->armorDMGreduc = 5;
  return ;
}

FragTrap::~FragTrap(void)
{
  std::cout
  << "\"Argh arghargh death gurgle gurglegurgle urgh... death.\""
  << std::endl;
  return ;
}

FragTrap::FragTrap(const FragTrap & f)
{
  *this = f;
  return ;
}

FragTrap & FragTrap::operator = (const FragTrap & f)
{
  this->name = f.name;
  this->hp = f.hp;
  this->ep = f.ep;
  this->level = f.level;
  this->meleeDMG = f.meleeDMG;
  this->rangeDMG = f.rangeDMG;
  this->armorDMGreduc = f.armorDMGreduc;
  return *this;
}

void FragTrap::set(std::string opt, int val)
{
  if (opt == "ENERGY") this->ep += val;
  return ;
}

int FragTrap::get(std::string opt)
{
  if (opt == "ENERGY") return this->ep;
  else if (opt == "HP") return this->hp;
  return 0;
}

unsigned int FragTrap::rangedAttack(std::string atk, std::string const & target)
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
  << "\"Step right up, to the Bulletnator 9000!\""
  << std::endl;
  return this->rangeDMG;
}

unsigned int FragTrap::meleeAttack(std::string atk, std::string const & target)
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
  << "\"Is it dead? Can, can I open my eyes now?\""
  << std::endl;
  return this->meleeDMG;
}

unsigned int FragTrap::vaulthunter_dot_exe(std::string const & target)
{
  typedef unsigned int (FragTrap::*Actions)
  (std::string atk, std::string const & target);
  std::string const attacks[] = {
    "Hyperion Punch",
    "Float like a Bee",
    "Explosive Element",
    "Shock Element",
    "Assault Rifles"
  };
  Actions actions[2] = {
    &FragTrap::meleeAttack,
    &FragTrap::rangedAttack
  };
  return ((this->*(actions[std::rand() % 2]))
  (attacks[std::rand() % 5], target));
}

void FragTrap::takeDamage(unsigned int amount)
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
  << "\"Why do I even feel pain?!\""
  << std::endl;
  return ;
}

void FragTrap::beRepaired(unsigned int amount)
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
