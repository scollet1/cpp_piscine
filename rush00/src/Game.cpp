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

Game::Game(int y, int x)
{
  this->_player = new Player(y - 5, x / 2);
  _maxY = y;
  _maxX = x;
  // std::srand(std::time(nullptr));
  // initscr();
  // start_color();
	// cbreak();
	// noecho();
	// keypad(stdscr, TRUE);
  // init_pair(1, COLOR_GREEN, COLOR_GREEN);
	// init_pair(2, COLOR_WHITE, COLOR_GREEN);
	// init_pair(3, COLOR_yELLOW, COLOR_GREEN);
	// init_pair(4, COLOR_BLACK, COLOR_GREEN);
	// init_pair(5, COLOR_RED, COLOR_BLACK);
	// init_pair(6, COLOR_RED, COLOR_GREEN);
	// init_pair(7, COLOR_RED, COLOR_RED);
  this->_running = true;
  return ;
}

Game::~Game(void)
{
  for (int i = 0; i < 1; ++i)
    delete[] this->_map[i];
  return ;
}

void Game::buildMaps(int sizey, int sizex)
{
  int i;

  _enemies = new Enemy*[sizey];
  for (i = 0; i < sizey; i++)
    _enemies[i] = new Enemy[sizex];
  this->_map = new char*[sizey];
  for (i = 0; i < sizey; i++)
    this->_map[i] = new char[sizex];
  return ;
}

int          Game::getMaxY(void)
{
  return _maxY;
}

int          Game::getMaxX(void)
{
  return _maxX;
}

void Game::setMap(int y, int x, char ch)
{
  // this->_enemies[y][x].setAliveStatus(true);
  this->_map[y][x] = ch;
  return ;
}

char Game::getMap(int y, int x)
{
  return this->_map[y][x];
}

Enemy & Game::getEnemy(int y, int x)
{
  return _enemies[y][x];
}

Player& Game::getPlayer(void)
{
  return *_player;
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
  num = 0;
  return ;
}
//
// Player & Game::getPlayer(void)
// {
//   return this->_player;
// }
