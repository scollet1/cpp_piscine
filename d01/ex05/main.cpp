/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 20:07:29 by scollet           #+#    #+#             */
/*   Updated: 2018/01/09 20:07:30 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int main()
{
  Human bob;
  std::cout << bob.identify() << std::endl;
  std::cout << bob.getBrain().identify() << std::endl;
}