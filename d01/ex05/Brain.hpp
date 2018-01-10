/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 20:07:04 by scollet           #+#    #+#             */
/*   Updated: 2018/01/09 20:07:05 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Brain {
public:

  Brain(void);
  Brain(bool thinks, bool inUse);
  ~Brain(void);
  std::string identify(void) const;
  // Brain& getBrain(void);


  bool thinks;
  bool inUse;
};
