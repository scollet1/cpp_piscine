/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 22:19:29 by scollet           #+#    #+#             */
/*   Updated: 2018/01/09 22:19:30 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanA {
public:
  HumanA(std::string name, Weapon weapon);
  ~HumanA(void);
  void attack(void);

  std::string name;
  Weapon weapon;
};
