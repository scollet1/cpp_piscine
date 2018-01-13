/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 10:47:39 by scollet           #+#    #+#             */
/*   Updated: 2018/01/13 10:47:40 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <string>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <iostream>

class Game {
public:
  Game(void);
  ~Game(void);

  bool isRunning(void);
  void keyCommand(int num);
  void terminate(int err);
  Character getPlayer(void);
private:
  bool _running;
};
