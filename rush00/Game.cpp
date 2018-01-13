/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 10:47:33 by scollet           #+#    #+#             */
/*   Updated: 2018/01/13 10:47:34 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Game::Game(void)
{
  std::srand(std::time(nullptr));
  initscr();
  start_color();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
  init_pair(1, COLOR_GREEN, COLOR_GREEN);
	init_pair(2, COLOR_WHITE, COLOR_GREEN);
	init_pair(3, COLOR_YELLOW, COLOR_GREEN);
	init_pair(4, COLOR_BLACK, COLOR_GREEN);
	init_pair(5, COLOR_RED, COLOR_BLACK);
	init_pair(6, COLOR_RED, COLOR_GREEN);
	init_pair(7, COLOR_RED, COLOR_RED);
  return ;
}

Game::~Game(void)
{

  return ;
}
