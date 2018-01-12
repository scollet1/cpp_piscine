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
  setRawBits(0);
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

Fixed::Fixed(const int p)
{
  std::cout
  << "Int constructor called"
  << std::endl;
  setRawBits(roundf(p << this->fb));
  return ;
}

Fixed::Fixed(const float p)
{
  std::cout
  << "Float constructor called"
  << std::endl;
  setRawBits(p * (1 << this->fb));
  return ;
}

std::ostream & operator << (std::ostream & out, const Fixed &f)
{
  out << f.toFloat();
  return out;
}

float Fixed::toFloat(void) const
{
  float p;

  p = getRawBits();
  return p / (1 << this->fb);
}

int Fixed::toInt(void) const
{
  return getRawBits() >> this->fb;
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
  return this->fpv;
}

void Fixed::setRawBits(int const raw)
{
  this->fpv = raw;
  return ;
}

int main( void ) {
  Fixed a;
  Fixed const b( 10 );
  Fixed const c( 42.42f );
  Fixed const d( b );

  a = Fixed( 1234.4321f );

  std::cout << "a is " << a << std::endl;
  std::cout << "b is " << b << std::endl;
  std::cout << "c is " << c << std::endl;
  std::cout << "d is " << d << std::endl;

  std::cout << "a is " << a.toInt() << " as integer" << std::endl;
  std::cout << "b is " << b.toInt() << " as integer" << std::endl;
  std::cout << "c is " << c.toInt() << " as integer" << std::endl;
  std::cout << "d is " << d.toInt() << " as integer" << std::endl;

  return 0;
}
