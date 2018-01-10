/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 22:18:46 by scollet           #+#    #+#             */
/*   Updated: 2018/01/09 22:18:47 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
  Weapon::type = type;
  return ;
}

Weapon::~Weapon(void)
{
  return ;
}

const std::string& Weapon::getType(void)
{
  return Weapon::type;
}

void Weapon::setType(std::string type)
{
  Weapon::type = &type;
  return ;
}
