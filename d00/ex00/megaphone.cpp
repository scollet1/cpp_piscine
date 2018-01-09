/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 09:22:01 by scollet           #+#    #+#             */
/*   Updated: 2018/01/08 09:22:03 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void big_fucking_letters(const char *str)
{
  int i;

  for (i = 0; str[i]; i++)
  {
    if (str[i] < 123 && str[i] > 96)
      std::cout << (char)(str[i] - 32);
    else
      std::cout << str[i];
  }
  return ;
}

int main(int ac, char **av)
{
  int i;

  if (ac >= 1)
    for (i = 1; av[i]; i++)
    {
      big_fucking_letters(av[i]);
      std::cout << " ";
    }
  else
    big_fucking_letters("* LOUD AND UNBEARABLE FEEDBACK NOISE *\n");
  std::cout << std::endl;
  return (0);
}
