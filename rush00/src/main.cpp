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
#include "Enemy.hpp"
#include "Header.hpp"
#include "Character.hpp"
#include "GameEntity.hpp"

void play(Game *game)
{
  int i;
  int j;
  int uIn;
  int eKilled = 0;
  char pause[] = " GAME OVER ";

  uIn = getch();
  std::cout << "play entered" << std::endl;
  while (game->getPlayer().getAliveStatus())
  {
    usleep(30000);
    timeout(0); // don't block for user
    uIn = getch();

    /*
      NOTE : CAPTURE USER INPUT AND ROUTE COMMANDS
    */

    switch (uIn)
    {
      case KEY_UP:
        if (game->getPlayer().getPosY() - 1 > 1)
        {
          game->setMap(game->getPlayer().getPosY(), game->getPlayer().getPosX(), ' ');
          game->getPlayer().updateObject(-1, 0);
        }
        break;
      case KEY_DOWN:
        if (game->getPlayer().getPosY() + 1 < game->getMaxY() - 1)
        {
          game->setMap(game->getPlayer().getPosY(), game->getPlayer().getPosX(), ' ');
          game->getPlayer().updateObject(1, 0);
        }
        break;
      case KEY_LEFT:
        if (game->getPlayer().getPosX() - 1 > 1)
        {
          game->setMap(game->getPlayer().getPosY(), game->getPlayer().getPosX(), ' ');
          game->getPlayer().updateObject(0, -1);
        }
        break;
      case KEY_RIGHT:
        if (game->getPlayer().getPosX() + 1 < game->getMaxX() - 1)
        {
          game->setMap(game->getPlayer().getPosY(), game->getPlayer().getPosX(), ' ');
          game->getPlayer().updateObject(0, 1);
        }
        break;
      case ' ':
        game->getPlayer().shootBullet(); // currently not shooting projectile but activates on keypress
        // exit(1); // TESTING SEGFAULT
        break;
      case 'p':
        move(0, 0);
    	  attron(COLOR_PAIR(7) | A_BOLD);
    	  mvprintw(game->getMaxX() / 2, (game->getMaxX() - sizeof(pause)) / 2, "%s", pause);
    	  attroff(COLOR_PAIR(7) | A_BOLD);
        do {
          uIn = getch();
        } while(uIn != 'p');
        break;
      case KEY_END:
        game->getPlayer().setAliveStatus(false); // currently doesn't exit properly
        break;
      default:
        break;
    }

    /*
      NOTE : CHECK ENEMY ALIVE STATUS
    */

    // exit(1); // TESTING SEGFAULT

    for (i = game->getMaxY() - 1; i >= 0; --i) // pre-increment
      for (j = game->getMaxX() - 1; j >= 0; --j) { // pre-increment

        // exit(1); // TESTING SEGFAULT

        if (game->getEnemy(i, j).getAliveStatus()) {

          // exit(1); // TESTING SEGFAULT

          /*
            NOTE : WIPE LAST POSITION AND UPDATE OBJECT
          */

          // exit(1); // TESTING SEGFAULT

          int ey = game->getEnemy(i, j).getPosY();
          int ex = game->getEnemy(i, j).getPosX();
          if (game->getMap(i + 1, j) != '|' && game->getMap(i + 1, j) != 'A') {
            if (i >= game->getMaxY() - 4) {
              game->getEnemy(i, j).setAliveStatus(false);
              game->setMap(i, j, ' ');
              continue ;
            }
            game->setMap(ey, ex, ' ');
            game->getEnemy(ey, ex).updateObject(1, 0);
            game->getEnemy(i + 1, j).activateEnemy(i + 1, j);
            game->setMap(i + 1, j, 'W');
          } else if (game->getMap(i + 1, j) == '|') {
            game->setMap(i, j, '*');
            eKilled++;
          } else if (game->getMap(i + 1, j) == 'A') {
            exit(1);
            game->setMap(game->getPlayer().getPosY(), game->getPlayer().getPosX(), ' ');
            game->getPlayer().setAliveStatus(false);
          }
          // game->setMap(game->getEnemy(ey, ex).getPosY()),
          // game->getEnemy(ey + 1, ex).getPosX(), 'W');

          // game->getEnemy(game->getEnemy(ey, ex).getPosY(),
          // game->getEnemy(ey + 1, ex).setAliveStatus(true);

          game->getEnemy(ey, ex).setAliveStatus(false);

        } else if (std::rand() % 1000 == 1 && i == 2) {

          /*
            NOTE : RANDOM CHANCE TO SPAWN ENEMIES
          */

          // exit(1); // TESTING SEGFAULT

          int r = std::rand() % (game->getMaxX() - 2);
          if (!game->getEnemy(2, r).getAliveStatus()) {
            game->getEnemy(i, j).activateEnemy(i, j);
            game->setMap(i, r, 'W');
          }
        } else {
          game->setMap(i, j, ' ');
        }
        /*else if (!game->getEnemy(i, j).getAliveStatus()) {
          game->getEnemy(i, j).setAliveStatus(true);
          if (game->getMap(i, j) != '|') {
            game->setMap(i, j, 'W');
          } else {
            game->setMap(i, j, ' ');
            game->getEnemy(i, j).setAliveStatus(false);
            eKilled++;
          }
        }*/

          // else if (!game->getEnemy(i, j).getAliveStatus()) {
          // game->setMap(i, j, ' ');
          // game->getEnemy(i, j).triggerDeath();
        // }

        // std::cerr << game->getEnemy(i, j).getAliveStatus() << std::endl;*/
      }

    /*
      NOTE : CHECK BULLET ALIVE STATUS
    */

    for (i = 0; i < MAX_BULLETS; i++)
    {
      if (game->getPlayer().getBullet(i)->getAliveStatus()) {
        int by = game->getPlayer().getBullet(i)->getPosY();
        int bx = game->getPlayer().getBullet(i)->getPosX();

        /*
          NOTE : SET BULLET PREVIOUS POSITION TO EMPTY && UPDATE BULLET OBJECT POSITION
        */

        // exit(1); // TESTING SEGFAULT
        game->setMap(by, bx, ' ');
        // exit(1); // TESTING SEGFAULT
        game->getPlayer().getBullet(i)->updateObject(-1, 0);
        // exit(1); // TESTING SEGFAULT
        game->setMap(game->getPlayer().getBullet(i)->getPosY(),
        game->getPlayer().getBullet(i)->getPosX(), '|');

        /*
          NOTE : CHECK IF BULLET INTERSECTS WITH ENEMY OR LEAVES SCREEN
        */

        // exit(1); // TESTING SEGFAULT

        if (game->getEnemy(game->getPlayer().getBullet(i)->getPosY(),
        game->getPlayer().getBullet(i)->getPosX()).getAliveStatus()) {
          game->getEnemy(game->getPlayer().getBullet(i)->getPosY(),
          game->getPlayer().getBullet(i)->getPosX()).takeDamage(game->getPlayer().getAtkDmg());
          game->setMap(game->getPlayer().getBullet(i)->getPosY(),
          game->getPlayer().getBullet(i)->getPosX(), '*');
          eKilled++;
        } else if (game->getPlayer().getBullet(i)->getPosY() < 2) {
          game->getPlayer().getBullet(i)->deactivateBullet();
          game->setMap(game->getPlayer().getBullet(i)->getPosY(),
          game->getPlayer().getBullet(i)->getPosX(), ' ');
        }
      }
    }

    /*
      NOTE : SET PLAYER'S NEW POSITION
    */

    game->setMap(game->getPlayer().getPosY(), game->getPlayer().getPosX(), 'A');
		move(0, 0);

    // exit(1); // TESTING SEGFAULT

    /*
      NOTE : BUFFER OUTPUT FOR PRINTING
    */

		for (int a = 0; a < game->getMaxY(); a++)
			for (int b = 0; b < game->getMaxX(); b++)
			{
        if (game->getMap(a, b) == 'W')
          attron(COLOR_PAIR(2) | A_BOLD);
        else if (game->getMap(a, b) == 'A')
          attron(COLOR_PAIR(1) | A_BOLD);
        else if (game->getMap(a, b) == '\'')
          attron(COLOR_PAIR(1) | A_BOLD);
        else if (game->getMap(a, b) == ' ')
          attron(COLOR_PAIR(4) | A_BOLD);
        else if (game->getMap(a, b) == '|')
          attron(COLOR_PAIR(3) | A_BOLD);
        else if (game->getMap(a, b) == '*') {
          attron(COLOR_PAIR(7) | A_BOLD);
        }
        addch(game->getMap(a, b));
			}
    // exit(1); // TESTING SEGFAULT
    /*for (i = 0; i < MAX_BULLETS - 1; i++)
    {
      if (game->getPlayer().getBullet(i)->getAliveStatus()) {
        // exit(1); // TESTING SEGFAULT
        attron(COLOR_PAIR(5));
        // exit(1); // TESTING SEGFAULT
        mvprintw((game->getMaxY() / 2), (game->getMaxX() - sizeof(TEST_DISPLAY_BULLETS_WORKING))
        / 2, "%s", TEST_DISPLAY_BULLETS_WORKING);
        // exit(1); // TESTING SEGFAULT
        attroff(COLOR_PAIR(5));
      } else {
        // exit(1); // TESTING SEGFAULT

        attron(COLOR_PAIR(5));
        mvprintw((game->getMaxY() / 2), (game->getMaxX() - sizeof(TEST_DISPLAY_BULLETS_NOT_WORKING))
        / 2, "%s", TEST_DISPLAY_BULLETS_NOT_WORKING);
        attroff(COLOR_PAIR(5));
      }
    }*/
		attron(COLOR_PAIR(6) | A_BOLD);
    mvprintw(game->getMaxY() - 4, 2, "|| ======================================== ||");
		mvprintw(game->getMaxY() - 3, 2, "|| Enemies killed : %d ", eKilled);
    mvprintw(game->getMaxY() - 3, 27, "|=====| Lives : %d  ||", game->getPlayer().getLives());
    mvprintw(game->getMaxY() - 2, 2, "|| ======================================== ||");
		attroff(COLOR_PAIR(6) | A_BOLD);
  }
  return ;
}

int main(void)
{
  // init
  int uIn;
  std::srand(std::time(nullptr));
  initscr();
  start_color();
	cbreak();
	noecho();
	keypad(stdscr, true);
  init_pair(1, COLOR_BLUE, COLOR_BLACK); // PLAYER
	init_pair(2, COLOR_RED, COLOR_BLACK); // ENEMY
	init_pair(3, COLOR_YELLOW, COLOR_BLACK); // BULLET
	init_pair(4, COLOR_WHITE, COLOR_BLACK); // BACKGROUND
	init_pair(5, COLOR_BLUE, COLOR_BLACK);
	init_pair(6, COLOR_RED, COLOR_BLACK);
	init_pair(7, COLOR_RED, COLOR_BLACK);

	int maxX, maxY;
  // int i;
  getmaxyx(stdscr, maxY, maxX);
  int posY = maxY - 5, posX = maxX / 2;

  std::cout << "game obj init" << std::endl;
  Game *game = new Game(maxY, maxX);
  game->buildMaps(maxY, maxX);
  std::cout << "game compiles" << std::endl;

  const char menuTextName[] = "ft_retro!";
  const char menuTextAuth[] = "SCollet:JChow";
  const char menuTextInst[] = "Press any key to continue...";

  std::cout << "strings declared" << std::endl;

  attron(COLOR_PAIR(5));
  mvprintw((maxY / 2) - 2, (maxX - sizeof(menuTextName)) / 2, "%s", menuTextName);
	mvprintw(maxY / 2, (maxX - sizeof(menuTextAuth)) / 2, "%s", menuTextAuth);
	attroff(COLOR_PAIR(5));

	attron(A_BOLD);
	mvprintw((maxY / 2) + 4, (maxX - sizeof(menuTextInst)) / 2, "%s", menuTextInst);
	attroff(A_BOLD);

	curs_set(0);

  /*for (i = 0; i < maxX; i++)
    game->setMap(0, i, ' ');
  std::cout << "game compiles" << std::endl;
  for (i = 0; i < maxY; i++)
  {
    game->setMap(i - 2, 0, '-');
    game->setMap(i - 2, 0, '-');
  }*/
  std::cout << "before stacking map" << std::endl;
  for (int a = 0; a < maxY - 1; a++)
    for (int b = 0; b < maxX - 1; b++)
    {
      // std::cout << a << b << std::endl;
      game->setMap(a, b, ' ');
    }
  std::cout << "before setting player" << std::endl;
  // for (i = 0; i < maxX; i++)
    // game->setMap(0, i, ' ');
  game->setMap(posY, posX, 'A');

  play(game);

  char text[] = " GAME OVER ";
	attron(COLOR_PAIR(7) | A_BOLD);
	mvprintw(maxX / 2, (maxY - sizeof(text)) / 2, "%s", text);
	attroff(COLOR_PAIR(7) | A_BOLD);
  curs_set(0);

	//the player needs the press enter to quit (so he gets time to see how many zombies he killed)
	timeout(-1);
	do {
		uIn = getch();
	} while(uIn != KEY_END);

  endwin();
  // delete[] enemies;
  delete game;
  return 0;
}
