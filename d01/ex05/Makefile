# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scollet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/09 20:32:15 by scollet           #+#    #+#              #
#    Updated: 2018/01/09 20:32:16 by scollet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = brian
FILES = main.cpp \
				Human.cpp \
				Brain.cpp
FLAGS = -Wall -Werror -Wextra
C = clang++

all:
	$(C) $(FLAGS) -I Human.hpp $(FILES) -o $(NAME)
