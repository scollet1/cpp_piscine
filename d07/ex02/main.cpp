/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:01:54 by scollet           #+#    #+#             */
/*   Updated: 2018/01/18 14:01:55 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void) {
  std::string  sam = "sam is a b";
  Array<char> *arr0 = new Array<char>(10);
  // Array<char> *arr1 = arr0;

  for (int i = 0; i < 10; i++) {
    arr0[i] = sam[i];
  }
  for (int i = 0; i < 10; i++) {
    std::cout << sam[i];
  }
  std::cout
  << std::endl
  << arr0->size()
  << arr0[1]
  << arr0[6]
  << arr0[11]
  << std::endl;
  return 0;
}
