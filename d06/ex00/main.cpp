/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 10:55:48 by scollet           #+#    #+#             */
/*   Updated: 2018/01/17 10:55:51 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int			isChar(char c)
{
	std::cout
  << "char : "
  << c
  << std::endl
	<< "int : "
  << static_cast<int>(c)
  << std::endl
	<< "float : "
  << static_cast<float>(c)
  << std::endl
	<< "double : "
  << static_cast<double>(c)
  << std::endl;
	return 0;
}

int			haHaMath(char *s)
{
		std::cout << "char : " << "impossible" << std::endl;
		std::cout << "int : " << "impossible" << std::endl;
		if (!std::strcmp(s, "-inff") || !std::strcmp(s, "+inff") || !std::strcmp(s, "nanf"))
			std::cout << "float : " << s << std::endl;
		else
			std::cout << "float : " << s << "f" << std::endl;
		if (!std::strcmp(s, "-inff") || !std::strcmp(s, "+inff") || !std::strcmp(s, "nanf"))
			s[std::strlen(s) - 1] = 0;
		std::cout << "double : " << s << std::endl;

		return 0;
}

int			isInt(char * s)
{
	int		i = std::atoi(s);
	char	c;

	c = static_cast<char>(i);
 	if (std::isprint(c))
 		std::cout << "char : '" << c << "'" << std::endl;
	else
		std::cout << "char : Non displayable" << std::endl;
	std::cout
  << "int : "
  << i
  << std::endl
	<< "float : "
  << static_cast<float>(i)
  << ".0f"
  << std::endl
	<< "double : "
  << static_cast<double>(i)
  << ".0"
  << std::endl;
	return 0;
}

int			isFloat(char * s)
{
	int		i = std::atoi(s);
	char	c;

	s[std::strlen(s) - 1] = 0;
	c = static_cast<char>(i);
 	if (std::isprint(c)) std::cout << "char : '" << c << "'" << std::endl;
	else std::cout << "char : Non displayable" << std::endl;
	std::cout
  << "int : "
  << static_cast<int>(i)
  << std::endl
	<< "float : "
  << s
  << "f"
  << std::endl
	<< "double : "
  << s
  << std::endl;
	return 0;
}

int			isDouble(char * s)
{
	int		i = std::atoi(s);
	char	c;

	c = static_cast<char>(i);
 	if (std::isprint(c)) std::cout << "char : '" << c << "'" << std::endl;
	else std::cout << "char : Non displayable" << std::endl;
	std::cout
  << "int : "
  << static_cast<int>(i)
  << std::endl
  << "float : "
  << s
  << "f"
  << std::endl
	<< "double : "
  << s
  << std::endl;
	return 0;
}

int			main(int ac, char **av)
{
	unsigned int i;

	if (ac != 2) return 0;
 	if (!std::strcmp(av[1], "-inf") || !std::strcmp(av[1], "+inf") || !std::strcmp(av[1], "nan")
		|| !std::strcmp(av[1], "-inff") || !std::strcmp(av[1], "+inff") || !std::strcmp(av[1], "nanf"))
 		return haHaMath(av[1]);
	i = 0;
	if (std::strlen(av[1]) == 1 && !std::isdigit(av[1][0]) && std::isprint(av[1][0]))
		return isChar(av[1][0]);
	if (av[1][i] == '-' || av[1][i] == '+')
		i++;
	while (i <= std::strlen(av[1]) && std::isdigit(av[1][i])) {
		i++;
	}
	if (i == std::strlen(av[1])) return isInt(av[1]);
	else if (av[1][i] == '.' && av[1][std::strlen(av[1]) - 1] == 'f') return isFloat(av[1]);
	else if (av[1][i] == '.' && std::isdigit(av[1][std::strlen(av[1]) - 1])) return isDouble(av[1]);
	return 0;
}
