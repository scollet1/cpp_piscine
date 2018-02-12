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

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
  FragTrap(std::string name);
  ~FragTrap(void);
  FragTrap(const FragTrap & f);
  FragTrap & operator = (const FragTrap &ft);

  unsigned int vaulthunter_dot_exe(std::string const & target);
};

#endif
