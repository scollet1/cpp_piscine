/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 20:07:23 by scollet           #+#    #+#             */
/*   Updated: 2018/01/09 20:07:25 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"

class Human {
public:

  Human(void);
  ~Human(void);
  std::string identify(void);
  const Brain& getBrain(void);

  const Brain attr;
};
