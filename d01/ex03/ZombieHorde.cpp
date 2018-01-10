/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 23:02:34 by scollet           #+#    #+#             */
/*   Updated: 2018/01/08 23:02:35 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieHorde.hpp"

std::string NAMES [10] = {
  "Zombo",
  "Sniffing Glue",
  "Guy",
  "Larry King",
  "Draugr",
  "Tupac",
  "Romero",
  "Grandpa",
  "Generic Zombie",
  "Zombie Joke Haha"
};

Zombie::Zombie()
{
  Zombie::alive = true;
  return ;
}

Zombie::~Zombie(void)
{
  return ;
}

ZombieHorde::ZombieHorde(int N)
{
  int i;

  ZombieHorde::_Horde = new Zombie[N];
  for (i = 0; i < N; i++)
    ZombieHorde::_Horde[i].alive = true;
  return ;
}

ZombieHorde::~ZombieHorde(void)
{
  return ;
}

void ZombieHorde::announce()
{
  int i;

  for (i = 0; ZombieHorde::_Horde[i].alive; i++)
    ZombieHorde::_Horde[i].announce(ZombieHorde::type);
  return ;
}

void ZombieHorde::setZombieType(std::string type)
{
  int i;

  ZombieHorde::type = type;
  for (i = 0; ZombieHorde::_Horde[i].alive; i++)
  {
    ZombieHorde::_Horde[i].name = NAMES[rand() % 10];
    ZombieHorde::_Horde[i].type = type;
  }
  return ;
}
