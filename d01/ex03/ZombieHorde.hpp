/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 23:02:41 by scollet           #+#    #+#             */
/*   Updated: 2018/01/08 23:02:42 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <iostream>

class ZombieHorde {
public:
  ZombieHorde(int N);
  ~ZombieHorde(void);

  std::string type;

  void setZombieType(std::string type);
  Zombie* newZombie(std::string name);
  Zombie *randomChump(std::string type);
  void announce();

  Zombie *_Horde;
};
