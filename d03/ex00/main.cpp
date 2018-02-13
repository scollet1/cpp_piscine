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

int main(void)
{
  std::srand(std::time(nullptr));
  FragTrap cl4p ("CL4P-TP");
  FragTrap c0py (cl4p);
  FragTrap fr4g;

  while (1)
  {
    if (cl4p.get("ENERGY") > 0)
    {
      fr4g.takeDamage(cl4p.vaulthunter_dot_exe("DEF4-LT"));
      cl4p.set("ENERGY", -25);
    }
    else
    {
      std::cout
      << "\"Dangit, I'm out!\""
      << std::endl;
      break ;
    }
    if (fr4g.get("ENERGY") > 0)
    {
      cl4p.takeDamage(fr4g.vaulthunter_dot_exe("CL4P-TP"));
      fr4g.set("ENERGY", -25);
    }
    else
    {
      std::cout
      << "\"Dangit, I'm out!\""
      << std::endl;
      break ;
    }
    if (c0py.get("ENERGY") > 0)
    {
      c0py.vaulthunter_dot_exe("Badass");
      c0py.set("ENERGY", -25);
    }
    else
    {
      std::cout
      << "\"Dangit, I'm out!\""
      << std::endl;
      break ;
    }
    if (c0py.get("HP") == 0) c0py.beRepaired(25);
    if (fr4g.get("HP") == 0) fr4g.beRepaired(25);
    if (cl4p.get("HP") == 0) cl4p.beRepaired(25);
    c0py = fr4g;
  }
  return 0;
}
