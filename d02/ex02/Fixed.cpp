/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:39:58 by scollet           #+#    #+#             */
/*   Updated: 2018/01/10 16:39:59 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void)
{
  std::cout
  << "Default constructor called"
  << std::endl;
  this->fpv = 0;
  return ;
}

Fixed::~Fixed(void)
{
  std::cout
  << "Destructor called"
  << std::endl;
  return ;
}

Fixed::Fixed(const Fixed &f)
{
  std::cout
  << "Copy constructor called"
  << std::endl;
  *this = f;
  return ;
}

Fixed & Fixed::operator = (const Fixed &f)
{
  std::cout
  << "Assignation operator called"
  << std::endl;
  if (this != &f)
    this->fpv = f.getRawBits();
  return *this;
}

int Fixed::getRawBits(void) const
{
  std::cout
  << "getRawBits member function called"
  << std::endl;
  return this->fpv;
}

void Fixed::setRawBits(int const raw)
{
  std::cout
  << "setRawBits member function called"
  << std::endl;
  this->fpv = raw;
  return ;
}

int main( void ) {

  Fixed a;
  Fixed b( a );
  Fixed c;

  c = b;

  std::cout << a.getRawBits() << std::endl;
  std::cout << b.getRawBits() << std::endl;
  std::cout << c.getRawBits() << std::endl;

  return 0;
}
