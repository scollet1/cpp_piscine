/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 22:18:54 by scollet           #+#    #+#             */
/*   Updated: 2018/01/09 22:18:55 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {
public:
  Weapon(std::string type);
  ~Weapon(void);
  const std::string& getType(void);
  void setType(std::string type);

  std::string type;
};

#endif
