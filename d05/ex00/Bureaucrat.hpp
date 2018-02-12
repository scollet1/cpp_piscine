/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:38:59 by scollet           #+#    #+#             */
/*   Updated: 2018/01/15 13:39:00 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Bureaucrat {
private:
  const std::string _name;
  int _grade;

public:
  Bureaucrat(std::string name);
  ~Bureaucrat(void);
  Bureaucrat(Bureaucrat const & b);
  Bureaucrat & operator=(Bureaucrat const & rhs);

  std::ostream operator<<(void);

  int getGrade(void);
  std::string getName(void);
  void inc(void);
  void dec(void);

};
