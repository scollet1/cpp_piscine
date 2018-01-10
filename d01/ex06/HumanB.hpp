/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 22:19:42 by scollet           #+#    #+#             */
/*   Updated: 2018/01/09 22:19:43 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanB {
public:
  HumanB(std::string name);
  ~HumanB(void);
  void setWeapon(Weapon weapon);
  void attack(void);

  std::string name;
  Weapon weapon;
};
