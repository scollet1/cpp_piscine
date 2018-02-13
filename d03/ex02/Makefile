# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scollet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/11 17:26:30 by scollet           #+#    #+#              #
#    Updated: 2018/01/11 17:26:32 by scollet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = clap
FILES = main.cpp FragTrap.cpp ScavTrap.cpp ClapTrap.cpp
INC = -I FragTrap.hpp -I ClapTrap.hpp -I ScavTrap.hpp
FLAGS = -Wall -Werror -Wextra
C = clang++

all:
	$(C) $(FLAGS) $(INC) $(FILES) -o $(NAME)
