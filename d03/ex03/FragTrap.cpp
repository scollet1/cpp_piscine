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

FragTrap::FragTrap(std::string name) : ClapTrap(100, 100, 100, 100, 1,
name, 30, 20, 5)
{
  std::cout
  << "Starting bootup sequence"
  << std::endl
  << "\"Directive one: Protect humanity!\
  Directive two: Obey Jack at all costs.\
  Directive three: Dance!\""
  << std::endl;
  this->setStr("NAME", name);
  this->set("HP", 100);
  this->set("EP", 100);
  this->set("LVL", 1);
  this->set("MDMG", 30);
  this->set("RDMG", 20);
  this->set("ARMR", 5);
  return ;
}

FragTrap::FragTrap(const FragTrap & f) : ClapTrap(100, 100, 100, 100, 1,
"DEFA-LT", 30, 20, 5)
{
  *this = f;
  return ;
}

FragTrap::~FragTrap(void)
{
  std::cout
  << "\"Argh arghargh death gurgle gurglegurgle urgh... death.\""
  << std::endl;
  return ;
}

FragTrap & FragTrap::operator = (const FragTrap & f)
{
  this->setStr("NAME", f.getStr("NAME"));
  this->set("HP", f.get("HP"));
  this->set("EP", f.get("EP"));
  this->set("LVL", f.get("LVL"));
  this->set("MDMG", f.get("MDMG"));
  this->set("RDMG", f.get("RDMG"));
  this->set("ARMR", f.get("ARMR"));
  return *this;
}

unsigned int FragTrap::vaulthunter_dot_exe(std::string const & target)
{
  typedef unsigned int (ClapTrap::*Actions)
  (std::string atk, std::string const & target);
  std::string const attacks[] = {
    "Hyperion Punch",
    "Float like a Bee",
    "Explosive Element",
    "Shock Element",
    "Assault Rifles"
  };
  Actions actions[2] = {
    &ClapTrap::meleeAttack,
    &ClapTrap::rangedAttack
  };
  return ((this->*(actions[std::rand() % 2]))
  (attacks[std::rand() % 5], target));
}
