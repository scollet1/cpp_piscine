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

  while (1)
  {
    char text1[] = "ft_retro!";
  	char text2[] = "SCollet:JChow";
  	char text3[] = "~Press any key to start~";
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
  }
  delete game;
  return 0;
}
