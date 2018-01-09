/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 21:49:19 by scollet           #+#    #+#             */
/*   Updated: 2018/01/08 21:49:20 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

int main(void)
{
  Pony *heapPony = ponyOnTheHeap("heap");
  Pony stackPony = ponyOnTheStack("stack");

  std::cout << heapPony->_name << std::endl;
  std::cout << heapPony->_head << std::endl;
  std::cout << heapPony->_legs << std::endl;
  std::cout << heapPony->_tail << std::endl;
  std::cout << heapPony->_color << std::endl;

  std::cout << stackPony._name << std::endl;
  std::cout << stackPony._head << std::endl;
  std::cout << stackPony._legs << std::endl;
  std::cout << stackPony._tail << std::endl;
  std::cout << stackPony._color << std::endl;

  delete heapPony;
}
