/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:39:51 by scollet           #+#    #+#             */
/*   Updated: 2018/01/10 16:39:52 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
  int fpv;
  static const int fb = 8;
public:
  Fixed(void);
  ~Fixed(void);
  Fixed(const Fixed &f);
  Fixed(const int p);
  Fixed(const float p);

  Fixed & operator = (const Fixed &f);
  std::ostream & operator << (std::ostream & out);

  bool operator > (const Fixed &b);
  bool operator < (const Fixed &b);
  bool operator >= (const Fixed &b);
  bool operator <= (const Fixed &b);
  bool operator == (const Fixed &b);
  bool operator != (const Fixed &b);

  Fixed operator + (const Fixed &b);
  Fixed operator - (const Fixed &b);
  Fixed operator * (const Fixed &b);
  Fixed operator / (const Fixed &b);

  Fixed operator ++ (int a);
  Fixed & operator ++ (void);
  Fixed operator -- (int a);
  Fixed & operator -- (void);

  static Fixed & min(Fixed &a, Fixed &b);
  static Fixed & max(Fixed &a, Fixed &b);
  static const Fixed & min(const Fixed &a, const Fixed &b);
  static const Fixed & max(const Fixed &a, const Fixed &b);

  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;
};

#endif
