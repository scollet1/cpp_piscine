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
  Game *game = new Game();
  int uIn;
  bool quit = false;

	char **map;
	int posY = 11, posX = 5;

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
  map = new char*[maxY];
  for (int i = 0; i < maxY; i++)
    map[i] = new char[maxX];
  for(int i = 0; i < maxX; ++i)
         map[0][i] = ' ';

  for(int i = 0; i < maxY; ++i)
  {
     map[i][1] = '#';
     map[i][maxX - 2] = '#';
  }
  //loads map with the inner game field
  for(int a = 2; a < maxY - 2; ++a)
  {
     for(int b = 0; b < maxX; ++b)
     {
         map[a][b] = ' ';
     }
    //  map[a][maxY / 10] = '|';
    //  map[a][maxY / 11] = '|';
    //  map[a][maxY / 12] = '|';
  }
  for(int i = 0; i < maxX; ++i)
     map[maxY - 1][i] = ' ';

	map[posY][posX] = '^';
	// map[posY][posX + 1] = '|';
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
  // for(int i=0; i < maxX; ++i)
	// 	map[0][i] = ' ';
  //
	// //loads map with top and bottom borders
	// for(int i=0; i < maxX; ++i)
	// {
	// 	map[1][i] = '#';
	// 	map[23][i] = '#';
	// }
	// //loads map with the inner game field
	// for(int a=2; a < 23; ++a)
	// {
	// 	for(int b=0; b < maxX; ++b)
	// 	{
	// 		map[a][b] = ' ';
	// 	}
	// 	map[a][10] = '|';
	// 	map[a][11] = '|';
	// 	map[a][12] = '|';
	// }
	// for(int i=0; i < maxX; ++i)
	// 	map[24][i] = ' ';
  //
	// map[posY][posX] = 'P';
	// map[posY][posX+1] = '=';
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

  while (quit != true)
  {
    uIn = getch();
    // std::cin >> uIn;
    // game->keyCommand(uIn);
    switch(uIn)
    {
      case KEY_UP:
        if (posY - 1 > 1)
          // game->getPlayer().getPos("Y") - 1 > 1)
        {
          map[posY][posX] = ' ';
          map[posY][posX + 1] = ' ';
          --posY;
        }
        break;
      case KEY_DOWN:
        if (posY + 1 < maxY)
        {
          map[posY][posX] = ' ';
          map[posY][posX + 1] = ' ';
          ++posY;
        }
        break;
      case KEY_LEFT:
        if (posX - 1 > 1)
          // game->getPlayer().getPos("Y") - 1 > 1)
        {
          map[posY][posX] = ' ';
          map[posY + 1][posX] = ' ';
          --posX;
        }
        break;
      case KEY_RIGHT:
        if (posX + 1 < maxX)
        {
          map[posY][posX] = ' ';
          map[posY + 1][posX] = ' ';
          ++posX;
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
    map[posY][posX] = '^';

		for(int i = 0; i < maxY - 1; ++i)
			map[0][i] = ' ';

		move(0, 0);
		//displays the map
		for(int a = 0; a < maxY; a++)
			for(int b = 0; b < maxX; b++)
			{
				if(map[a][b] == ' ') attron(COLOR_PAIR(1) | A_BOLD);
				else if(map[a][b] == '#') attron(COLOR_PAIR(2) | A_BOLD);
				else if(map[a][b] == '|') attron(COLOR_PAIR(4));
				else if(map[a][b] == '*') attron(COLOR_PAIR(4));
				else if(map[a][b] == '@') attron(COLOR_PAIR(6));
				else if(map[a][b] == '%') attron(COLOR_PAIR(7) | A_BOLD);
				else attron(COLOR_PAIR(2) | A_BOLD);
				addch(map[a][b]);
				standend();
			}
			attron(COLOR_PAIR(2) | A_BOLD);
			mvprintw(maxX - 1, 0, "Zombies killed: %i", 0);
			attroff(COLOR_PAIR(2) | A_BOLD);

		// for(int i=0; i < 100; ++i)
			// ++zombies[i].balancer;
	}
  char text[] = " You lost... ";
	attron(COLOR_PAIR(7) | A_BOLD);
	mvprintw(maxX / 2, (maxY - sizeof(text)) / 2, "%s", text);
	attroff(COLOR_PAIR(7) | A_BOLD);

	//the player needs the press enter to quit (so he gets time to see how many zombies he killed)
	timeout(-1);
	do {
		uIn = getch();
	} while(uIn != 10);

  endwin();
  delete game;
  return 0;
}
