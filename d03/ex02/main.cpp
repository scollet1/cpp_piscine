/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:45:51 by scollet           #+#    #+#             */
/*   Updated: 2018/01/11 16:45:52 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
  std::srand(std::time(nullptr));
  FragTrap cl4p1 ("FUCK YOU");
  ScavTrap cl4p2 ("k");
  FragTrap cl4p3 (cl4p1);
  ScavTrap cl4p4 (cl4p2);
  ScavTrap scav ("GOTT-EE");
  FragTrap cl4p5 = cl4p3;
  ScavTrap cl4p6 = cl4p2;

  while (1)
  {
    if (cl4p1.get("EP") > 0)
    {
      cl4p2.takeDamage(cl4p1.vaulthunter_dot_exe("CL4P-TP"));
      cl4p1.set("EP", -25);
    }
    else
    {
      std::cout
      << "\"Dangit, I'm out!\""
      << std::endl;
      break ;
    }
    if (cl4p2.get("EP") > 0)
    {
      cl4p2.challengeNewcomer(std::rand() % 5);
      cl4p2.set("EP", -25);
    }
    else
    {
      std::cout
      << "\"My servos... are seizing...\""
      << std::endl;
      break ;
    }
    if (cl4p1.get("HP") == 0) cl4p1.beRepaired(25);
    if (cl4p2.get("HP") == 0) cl4p2.beRepaired(25);
    if (cl4p3.get("HP") == 0) cl4p3.beRepaired(25);
    if (cl4p4.get("HP") == 0) cl4p4.beRepaired(25);
    if (cl4p5.get("HP") == 0) cl4p5.beRepaired(25);
    if (cl4p6.get("HP") == 0) cl4p6.beRepaired(25);
    cl4p1 = cl4p5;
  }
  return 0;
}
