/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:39:06 by scollet           #+#    #+#             */
/*   Updated: 2018/01/15 13:39:07 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
  try {
    if (grade < 1)
      throw "Bureaucrat::GradeTooHighException";
    else if (grade > 150)
      throw "Bureaucrat::GradeTooLowException";
  } catch (std::exception & e) {
    std::cerr << e << std::endl;
  } return ;
}

Bureaucrat::~Bureaucrat(void) {
  return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const & b) {

}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs) {
  _name = rhs.name;
  _grade = rhs.grade;
}

std::ostream Bureaucrat::operator<<(std::ostream out) {
  return out << _name << ", bureaucrat grade " << _grade;
}

int Bureaucrat::getGrade(void) {
  return _grade;
}

std::string Bureaucrat::getName(void) {
  return _name;
}

void Bureaucrat::inc(void) {
  try {
    if (_grade - 1 > 0) _grade -= 1;
    else throw "";
  } catch (std::exception & e) {

  } return ;
}

void Bureaucrat::dec(void) {
  try {

  } catch (std::exception & e) {
  } return ;
}
