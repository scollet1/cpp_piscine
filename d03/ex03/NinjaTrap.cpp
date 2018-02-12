/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 21:57:36 by scollet           #+#    #+#             */
/*   Updated: 2018/01/12 21:57:37 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::~NinjaTrap(void)
{
  std::cout
  << "\"I can't feel my fingers! Gah! I don't have any fingers!\""
  << std::endl;
  return ;
}

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(60, 60, 120, 1,
name, 60, 5, 0)
{
  std::cout
  << "Starting bootup sequence"
  << std::endl
  << "\"Recompiling my combat code!\""
  << std::endl;
  this->setStr("NAME", name);
  this->set("HP", 60);
  this->set("EP", 120);
  this->set("LVL", 1);
  this->set("MDMG", 30);
  this->set("RDMG", 20);
  this->set("ARMR", 5);
  return ;
}

NinjaTrap::NinjaTrap(const NinjaTrap & f) : ClapTrap()
{
  *this = f;
  return ;
}

NinjaTrap & NinjaTrap::operator = (const NinjaTrap &st)
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

unsigned int NinjaTrap::rangedAttack(std::string atk, std::string const & target)
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

unsigned int NinjaTrap::meleeAttack(std::string atk, std::string const & target)
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
