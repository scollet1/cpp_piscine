/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:45:46 by scollet           #+#    #+#             */
/*   Updated: 2018/01/11 16:45:47 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>

class FragTrap {
private:
  int hp;
  const static int maxHP = 100;
  int ep;
  const static int maxEP = 100;
  int level;
  std::string name;
  int meleeDMG;
  int rangeDMG;
  int armorDMGreduc;

public:
  FragTrap(void);
  FragTrap(std::string name);
  ~FragTrap(void);
  FragTrap(const FragTrap & f);
  FragTrap & operator = (const FragTrap & f);

  unsigned int rangedAttack(std::string atk, std::string const & target);
  unsigned int meleeAttack(std::string atk, std::string const & target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  unsigned int vaulthunter_dot_exe(std::string const & target);
  void set(std::string opt, int val);
  int get(std::string opt);
};

#endif
