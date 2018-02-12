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

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
  ScavTrap(void);
  ~ScavTrap(void);
  ScavTrap(std::string name);
  ScavTrap(const ScavTrap & st);
  ScavTrap & operator = (const ScavTrap &st);

  void challengeNewcomer(int chal);
  unsigned int rangedAttack(std::string atk, std::string const & target);
  unsigned int meleeAttack(std::string atk, std::string const & target);
};

#endif
