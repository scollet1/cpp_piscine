/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:24:12 by scollet           #+#    #+#             */
/*   Updated: 2018/01/12 12:24:14 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
protected:
  int hp;
  int maxHP;
  int ep;
  int maxEP;
  int level;
  std::string name;
  int meleeDMG;
  int rangeDMG;
  int armorDMGreduc;

public:
  ClapTrap(int h, int maxHp, int e, int maxEp,
  int lvl, std::string nam, int mdmg, int rdmg, int armr);
  ~ClapTrap(void);
  ClapTrap(ClapTrap & f);
  ClapTrap & operator = (const ClapTrap &ft);

  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  void set(std::string opt, int val);
  void setStr(std::string opt, std::string str);
  int get(std::string opt) const;
  std::string getStr(std::string opt) const;

  unsigned int meleeAttack(std::string atk, std::string const & target);
  unsigned int rangedAttack(std::string atk, std::string const & target);
};

#endif
