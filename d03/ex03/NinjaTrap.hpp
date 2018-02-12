/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 21:57:41 by scollet           #+#    #+#             */
/*   Updated: 2018/01/12 21:57:43 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP

#include "ClapTrap.hpp"

class NinjaTrap : public ClapTrap {
public:
  NinjaTrap(std::string name);
  ~NinjaTrap(void);
  NinjaTrap(const NinjaTrap & f);
  NinjaTrap & operator = (const NinjaTrap &ft);

  unsigned int rangedAttack(std::string atk, std::string const & target);
  unsigned int meleeAttack(std::string atk, std::string const & target);
  unsigned int vaulthunter_dot_exe(std::string const & target);
};

#endif
