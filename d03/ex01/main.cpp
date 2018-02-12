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

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
  std::srand(std::time(nullptr));
  FragTrap cl4p ("CL4P-TP");
  ScavTrap sc4v ("SC4V-TP");
  FragTrap fr4g (cl4p);
  ScavTrap tr4p (sc4v);
  FragTrap def4;
  ScavTrap d3fa;

  while (1)
  {
    if (cl4p.get("ENERGY") > 0)
    {
      sc4v.takeDamage(cl4p.vaulthunter_dot_exe("SC4V-TP"));
      cl4p.set("ENERGY", -25);
    }
    else
    {
      std::cout
      << "\"Dangit, I'm out!\""
      << std::endl;
      break ;
    }
    if (sc4v.get("ENERGY") > 0)
    {
      sc4v.challengeNewcomer(std::rand() % 5);
      sc4v.set("ENERGY", -25);
    }
    else
    {
      std::cout
      << "\"My servos... are seizing...\""
      << std::endl;
      break ;
    }
    if (sc4v.get("HP") == 0) sc4v.beRepaired(25);
    if (fr4g.get("HP") == 0) fr4g.beRepaired(25);
    if (cl4p.get("HP") == 0) cl4p.beRepaired(25);
    if (tr4p.get("HP") == 0) tr4p.beRepaired(25);
    if (def4.get("HP") == 0) def4.beRepaired(25);
    if (d3fa.get("HP") == 0) d3fa.beRepaired(25);
    def4 = fr4g;
    d3fa = tr4p;
  }
  return 0;
}
