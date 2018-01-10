/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 20:07:11 by scollet           #+#    #+#             */
/*   Updated: 2018/01/09 20:07:12 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "Human.hpp"

Human::Human(void)
{
  return ;
}

Human::~Human(void)
{
  return ;
}

std::string Human::identify(void)
{
  return this->getBrain().identify();
}

const Brain& Human::getBrain(void)
{
  return this->attr;
}
