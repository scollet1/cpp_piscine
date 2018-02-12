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
  setRawBits(0);
  return ;
}

Fixed::~Fixed(void)
{
  return ;
}

Fixed::Fixed(const Fixed &f)
{
  *this = f;
  return ;
}

Fixed::Fixed(const int p)
{
  this->fpv = p * 256.0;
  return ;
}

Fixed::Fixed(const float p)
{
  this->fpv = roundf(p * 256.0);
  return ;
}

std::ostream & operator << (std::ostream & out, const Fixed &f)
{
  out << f.toFloat();
  return out;
}

bool Fixed::operator > (const Fixed &b)
{
  return this->fpv > b.getRawBits();
}

bool Fixed::operator < (const Fixed &b)
{
  return this->fpv < b.getRawBits();
}

bool Fixed::operator >= (const Fixed &b)
{
  return this->fpv >= b.getRawBits();
}

bool Fixed::operator <= (const Fixed &b)
{
  return this->fpv <= b.getRawBits();
}

bool Fixed::operator == (const Fixed &b)
{
  return this->fpv == b.getRawBits();
}

bool Fixed::operator != (const Fixed &b)
{
  return this->fpv != b.getRawBits();
}

Fixed Fixed::operator + (const Fixed &b)
{
  Fixed tmp (this->fpv + b.getRawBits());
  return tmp;
}

Fixed Fixed::operator - (const Fixed &b)
{
  Fixed tmp (this->fpv - b.getRawBits());
  return tmp;
}

Fixed Fixed::operator * (const Fixed &b)
{
  Fixed tmp;
  tmp.fpv = (this->fpv * b.getRawBits()) / 256;
  return tmp;
}

Fixed Fixed::operator / (const Fixed &b)
{
  Fixed tmp;
  if (b.getRawBits() == 0)
  {
    std::cout
    << "fucl yu tryin divide by 0 smh"
    << std::endl;
    return Fixed(b.getRawBits());
  }
  tmp.fpv = ((this->fpv >> this->fb) / b.fpv);
  return tmp;
}

Fixed Fixed::operator ++ (int a)
{
  (void) a;
  Fixed tmp (*this);
  ++(*this);
  return tmp;
}

Fixed & Fixed::operator ++ (void)
{
  this->fpv++;
  return *this;
}

Fixed Fixed::operator -- (int a)
{
  (void) a;
  Fixed tmp (*this);
  --(*this);
  return tmp;
}

Fixed & Fixed::operator -- (void)
{
  this->fpv--;
  return *this;
}

Fixed & Fixed::min(Fixed &a, Fixed &b)
{
  return a.getRawBits() < b.getRawBits() ? a : b;
}

Fixed & Fixed::max(Fixed &a, Fixed &b)
{
  return a.getRawBits() > b.getRawBits() ? a : b;
}

const Fixed & Fixed::min(const Fixed &a, const Fixed &b)
{
  return a.getRawBits() < b.getRawBits() ? a : b;
}

const Fixed & Fixed::max(const Fixed &a, const Fixed &b)
{
  return a.getRawBits() > b.getRawBits() ? a : b;
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
  Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
  Fixed c( Fixed( 1 ) );
  Fixed tmp;

  std::cout << "b ================ " << b << std::endl;


  std::cout << "a ================ " << a << std::endl;
  std::cout << "pre-increment a == " << ++a << std::endl;
  std::cout << "a ================ " << a << std::endl;
  std::cout << "post-increment a = " << a++ << std::endl;
  std::cout << "a ================ " << a << std::endl;
  std::cout << "pre-decrement a == " << --a << std::endl;
  std::cout << "a ================ " << a << std::endl;
  std::cout << "post-decrement a = " << a-- << std::endl;
  std::cout << "a ================ " << a << std::endl;

  tmp = a * b;
  std::cout << "a * b ============ " << tmp << std::endl;
  tmp = a + b;
  std::cout << "a + b ============ " << tmp << std::endl;
  tmp = a / b;
  std::cout << "a / b ============ " << tmp << std::endl;
  tmp = c / a;
  std::cout << "b / a ============ " << tmp << std::endl;
  tmp = a - b;
  std::cout << "a - b ============ " <<  tmp << std::endl;
  tmp = a > b;
  std::cout << "Should be 0 ====== " << tmp << std::endl;
  tmp = a < b;
  std::cout << "Should be 1 ====== " << tmp << std::endl;
  tmp = a >= b;
  std::cout << "Should be 0 ====== " << tmp << std::endl;
  tmp = a <= b ;
  std::cout << "Should be 1 ====== " << tmp << std::endl;
  tmp = a == b;
  std::cout << "Should be 0 ====== " << tmp << std::endl;
  tmp = a != b;
  std::cout << "Should be 1 ====== " << tmp << std::endl;

  std::cout << "b ================ " << b << std::endl;

  std::cout << "minimum value ==== " << Fixed::min( a, b ) << std::endl;
  std::cout << "maximum value ==== " << Fixed::max( a, b ) << std::endl;

  return 0;
}
