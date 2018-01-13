# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scollet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/13 10:42:50 by scollet           #+#    #+#              #
#    Updated: 2018/01/13 10:42:53 by scollet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro

SRC = main.cpp Game.cpp Character.cpp
OBJ = $(SRC:.cpp=.o)

CC = clang++ -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $@ -lncurses

%.o: %.cpp
	$(CC) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
