/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:07:47 by scollet           #+#    #+#             */
/*   Updated: 2018/01/11 18:07:49 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>

class ScavTrap {
private:
  int hp;
  const static int maxHP = 100;
  int ep;
  const static int maxEP = 50;
  int level;
  std::string name;
  int meleeDMG;
  int rangeDMG;
  int armorDMGreduc;

public:
  ScavTrap(void);
  ~ScavTrap(void);
  ScavTrap(std::string name);
  ScavTrap & operator = (const ScavTrap &st);

  unsigned int rangedAttack(std::string atk, std::string const & target);
  unsigned int meleeAttack(std::string atk, std::string const & target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  void challengeNewcomer(int chal);
  void set(std::string opt, int val);
  int get(std::string opt);
};

#endif
