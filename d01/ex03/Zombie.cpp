/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 23:02:14 by scollet           #+#    #+#             */
/*   Updated: 2018/01/08 23:02:15 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce(std::string type)
{
  std::cout
  << "I'm "
  << Zombie::name
  << ", "
  << type
  << " type, "
  << " Braiiiiiiinnnssss..."
  << std::endl;
}
