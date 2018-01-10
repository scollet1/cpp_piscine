/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 23:02:49 by scollet           #+#    #+#             */
/*   Updated: 2018/01/08 23:02:50 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieHorde.hpp"

int main(int ac, char **av)
{
  int num;

  if (ac <= 1)
  {
    std::cout
    << "Enter a number as argument"
    << std::endl;
    return 0;
  }
  num = atoi(av[1]);
  if (num < 0 || num > 2147483647)
  {
    std::cout
    << "Enter a positive number that fits in an int dude,\
    you're killin' me"
    << std::endl;
    return 0;
  }

  srand (time(NULL));
  ZombieHorde *z = new ZombieHorde(num);

  z->setZombieType("Regular-ass Zombie");
  z->announce();
  std::cout << "\nNew wave incoming ...\n" << std::endl;
  z->setZombieType("Big ol' boy");
  z->announce();
  std::cout << "\nNew wave incoming ...\n" << std::endl;
  z->setZombieType("Congressman");
  z->announce();
  std::cout << "\nNew wave incoming ...\n" << std::endl;
  z->setZombieType("Me in the morning");
  z->announce();

  delete[] z->_Horde;
  delete z;
  return 0;
}
