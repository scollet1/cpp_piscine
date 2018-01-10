/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 22:19:08 by scollet           #+#    #+#             */
/*   Updated: 2018/01/09 22:19:09 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon weapon)
{
  HumanA::name = name;
  HumanA::weapon = weapon;
  return ;
}

HumanA::~HumanA(void)
{
  return ;
}

void HumanA::attack(void)
{
  std::cout
  << HumanA::name
  << " attacks with his large, thick "
  << HumanA::weapon
  std::endl;
}
