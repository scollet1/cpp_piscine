/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 20:06:56 by scollet           #+#    #+#             */
/*   Updated: 2018/01/09 20:06:57 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "Human.hpp"

Brain::Brain(void)
{
  return ;
}

Brain::Brain(bool thinks, bool inUse)
{
  Brain::thinks = thinks;
  Brain::inUse = inUse;
  return ;
}

Brain::~Brain(void)
{
  return ;
}

std::string Brain::identify(void) const
{
  std::stringstream s;
  s << this;
  return s.str();
}
