/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 15:39:15 by scollet           #+#    #+#             */
/*   Updated: 2018/01/18 15:39:18 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T = char> class Array {
private:
  T *_arr;
  unsigned int _len;

public:
  Array<T>(void) : _arr(nullptr), _len(0) {};
  Array<T>(unsigned int n) {
    _arr = n == 0 ? nullptr : new T[n];
    _len = n;
    return ;
  };

  ~Array<T>(void) {}
  Array<T>(Array<T> & cpy) {
    if (this != &cpy) *this = cpy;
    return *this;
  };

  Array<T> & operator=(Array<T> const & cpy) {
    for (unsigned int i = 0; i < _len; i++) {
      _arr[i] = cpy._arr[i];
    } _len = cpy._len; return *this;
  };

  T & operator[](unsigned int idx) {
    if (idx < 0 || idx > _len || !_arr)
      throw std::range_error("Out of bounds");
    return _arr[idx];
  };

  unsigned int size(void) const {return _len;};
};

#endif
