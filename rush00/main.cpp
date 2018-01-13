/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 10:41:14 by scollet           #+#    #+#             */
/*   Updated: 2018/01/13 10:41:15 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
// #include "Header.hpp"

int main(void)
{
  /* Initialize curses */
	// initscr();
	// start_color();
	// cbreak();
	// noecho();
	// keypad(stdscr, TRUE);

	// srand(time(0));

  Game *game = new Game();
	char map[1820][1400]; //the game map
	int posY = 11, posX = 5; //the game characters coordinates
	// int zombiespeed = 3; //how fast the zombies move
	// int fences = 3; //amount of fences left (3 at startup)
	// int zombie_index = 0;
	// int zombie_spawnrate = 100; //how fast the zombies spawn
	// int zombie_spawnbalancer = 0;
	// int zombies_killed = 0;

	//color initalizations
	// init_pair(1, COLOR_GREEN, COLOR_GREEN);
	// init_pair(2, COLOR_WHITE, COLOR_GREEN);
	// init_pair(3, COLOR_YELLOW, COLOR_GREEN);
	// init_pair(4, COLOR_BLACK, COLOR_GREEN);
	// init_pair(5, COLOR_RED, COLOR_BLACK);
	// init_pair(6, COLOR_RED, COLOR_GREEN);
	// init_pair(7, COLOR_RED, COLOR_RED);

	for(int i=0; i < 80; ++i)
		map[0][i] = ' ';

	//loads map with top and bottom borders
	for(int i=0; i < 80; ++i)
	{
		map[1][i] = '#';
		map[23][i] = '#';
	}
	//loads map with the inner game field
	for(int a=2; a < 23; ++a)
	{
		for(int b=0; b < 80; ++b)
		{
			map[a][b] = ' ';
		}
		map[a][10] = '|';
		map[a][11] = '|';
		map[a][12] = '|';
	}
	for(int i=0; i < 80; ++i)
		map[24][i] = ' ';

	map[posY][posX] = 'P';
	map[posY][posX+1] = '=';

	//print a startup message
	char text1[] = "ft_retro";
	char text2[] = "SCollet:JChow";
	char text3[] = "Press any key to start";
	int maxX, maxY;
	getmaxyx(stdscr, maxY, maxX);
	attron(COLOR_PAIR(5));
	mvprintw((maxY / 2) - 2, (maxX - sizeof(text1)) / 2, "%s", text1);
	mvprintw(maxY / 2, (maxX - sizeof(text2)) / 2, "%s", text2);
	attroff(COLOR_PAIR(5));

	attron(A_BOLD);
	mvprintw((maxY / 2) + 4, (maxX - sizeof(text3)) / 2, "%s", text3);
	attroff(A_BOLD);

	getch();

	curs_set(0);
  // std::srand(std::time(nullptr));
  // initscr();
  // start_color();
	// cbreak();
	// noecho();
	// keypad(stdscr, TRUE);
  // Game *game = new Game();

  // char map[2220][1400];
  // int posY = 11, posX = 5;
  // char text1[] = "ft_retro!";
  // char text2[] = "SCollet:JChow";
  // char text3[] = "~Press any key to start~";
  // int maxX, maxY;
  // int uIn;
  int bullet_stabilizer = 10;
	int bulletIndex = 0;
	// bool quit = false;
  // /*arr[] = {
  //   &keyUp,
  //   &keyDown,
  //   &keyLeft,
  //   &keyRight,
  //   &keySpace,
  //   &keyEsc
  // };*/
  //
  // // game->buildMap(maxX, maxY);
  //
  // init_pair(1, COLOR_GREEN, COLOR_GREEN);
	// init_pair(2, COLOR_WHITE, COLOR_GREEN);
	// init_pair(3, COLOR_YELLOW, COLOR_GREEN);
	// init_pair(4, COLOR_BLACK, COLOR_GREEN);
	// init_pair(5, COLOR_RED, COLOR_BLACK);
	// init_pair(6, COLOR_RED, COLOR_GREEN);
	// init_pair(7, COLOR_RED, COLOR_RED);
  //
  // // for(int i=0; i < 2220; ++i)
  //   // game->setMap(0, i, ' ');
  //
  // // for(int i=0; i < 2220; ++i)
  // // {
  //   // game->setMap(1, i, '#');
  //   // game->setMap(23, i, '#');
  // // }
  // // for(int a=2; a < 23; ++a)
  // // {
  //   // for(int b=0; b < 2220; ++b)
  //   // {
  //     // game->setMap(a, b, ' ');
  //     // map[a][b] = ' ';
  //   // }
  //   // game->setMap(a, 10, '|');
  //   // game->setMap(a, 11, '|');
  //   // game->setMap(a, 12, '|');
  // // }
  // // for(int i=0; i < 2220; ++i)
  //   // game->setMap(24, i, ' ');
  //
  // // game->setMap(posY, posX, 'P');
  // // game->setMap(posY, posX + 1, '=');
  //
  // getmaxyx(stdscr, maxY, maxX);
  // attron(COLOR_PAIR(5));
  // mvprintw((maxY / 2) - 2, (maxX - sizeof(text1)) / 2, "%s", text1);
  // mvprintw(maxY / 2, (maxX - sizeof(text2)) / 2, "%s", text2);
  // attroff(COLOR_PAIR(5));
  //
  // attron(A_BOLD);
  // mvprintw((maxY / 2) + 4, (maxX - sizeof(text3)) / 2, "%s", text3);
  // attroff(A_BOLD);
  //
  // std::cin >> uIn;
  //
  // curs_set(0);

  bool quit = false;
  int uIn;
  while (quit != true)
  {
    std::cin >> uIn;
    // game->keyCommand(uIn);
    switch(uIn)
    {
      case KEY_UP:
        if (posY - 1 > 1)
          // game->getPlayer().getPos("Y") - 1 > 1)
        {
          map[posY][posX] = ' ';
          map[posY][posX+1] = ' ';
          --posY;
        }
        break;
      case KEY_DOWN:
        if (posY + 1 < 23)
        {
          map[posY][posX] = ' ';
          map[posY][posX+1] = ' ';
          ++posY;
        }
        break;
      case ' ':
        if (bullet_stabilizer >= 10)
        {
          // bullets[bulletIndex].is_moving = true;
          // bullets[bulletIndex].posX = posX + 2;
          // bullets[bulletIndex].posY = posY;
          if (bulletIndex == 9) bulletIndex = 0;
          else ++bulletIndex;
          bullet_stabilizer = 0;
        }
        break;
      case 27:
        quit = true;
        break;
      default:
        break;
    }
  }

  delete game;
  return 0;
}
