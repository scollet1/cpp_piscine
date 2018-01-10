/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 23:02:25 by scollet           #+#    #+#             */
/*   Updated: 2018/01/08 23:02:26 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie {
public:
  Zombie(void);
  ~Zombie(void);

  void announce(std::string type);

  std::string name;
  std::string type;
  bool alive;
};
