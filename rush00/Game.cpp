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

bool Game::isRunning(void)
{
  return this->_running;
}

void Game::terminate(int err)
{
  std::cout
  << "Goodybe"
  << std::endl;
  exit(err);
}

void Game::keyCommand(int num)
{
  switch(num)
  {
    case KEY_UP:
      if(game.getPlayer().getPos("Y") - 1 > 1)
      {
        map[posY][posX] = ' ';
        map[posY][posX+1] = ' ';
        --posY;
      }
      break;
    case KEY_DOWN:
      if(posY + 1 < 23)
      {
        map[posY][posX] = ' ';
        map[posY][posX+1] = ' ';
        ++posY;
      }
      break;
    case ' ':
      if(bullet_stabilizer >= 10)
      {
        bullets[bulletIndex].is_moving = true;
        bullets[bulletIndex].posX = posX + 2;
        bullets[bulletIndex].posY = posY;
        if(bulletIndex == 9) bulletIndex = 0;
        else ++bulletIndex;
        bullet_stabilizer = 0;
      }
      break;
    case 27:
      return ;
      break;
    default:
      break;
  }
}
