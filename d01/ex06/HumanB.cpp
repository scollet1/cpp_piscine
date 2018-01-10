/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 22:19:36 by scollet           #+#    #+#             */
/*   Updated: 2018/01/09 22:19:37 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
  HumanB::name = name;
  return ;
}

HumanB::~HumanB(void)
{
  return ;
}

void setWeapon(Weapon weapon)
{
  
}

void HumanB::attack(void)
{
  std::cout
  << HumanB::name
  << " attacks with his large, thick "
  << HumanB::weapon
  std::endl;
}
