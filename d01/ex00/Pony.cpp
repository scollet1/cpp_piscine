/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 21:49:03 by scollet           #+#    #+#             */
/*   Updated: 2018/01/08 21:49:04 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(std::string name)
{
  Pony::_name = name;
  Pony::_head = true;
  Pony::_legs = 4;
  Pony::_tail = true;
  Pony::_color = "Blue or Green, whatever";
  return ;
}

Pony::~Pony(void)
{
  return ;
}

Pony *ponyOnTheHeap(std::string name)
{
  Pony *pony = new Pony(name);
  return pony;
}

Pony ponyOnTheStack(std::string name)
{
  Pony pony(name);
  // pony->_name = name;
  return pony;
}
