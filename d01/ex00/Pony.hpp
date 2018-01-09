/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 21:49:11 by scollet           #+#    #+#             */
/*   Updated: 2018/01/08 21:49:12 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ios>
#include <iostream>

class Pony {
public:
  Pony(std::string name);
  ~Pony(void);

  std::string _name;
  bool        _head;
  int         _legs;
  bool        _tail;
  std::string _color;
};

Pony *ponyOnTheHeap(std::string name);
Pony ponyOnTheStack(std::string name);
