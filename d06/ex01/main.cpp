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

#include <string>
#include <ctime>
#include <iostream>

struct Data {
	std::string s1;
	int n;
	std::string s2;
};

void *serialize(void)
{
	int			*tmp;
	int			i;
	int			j;

	char 	*data = new char[22];
	static const char alpha[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

	i = 0;
	std::srand(std::time(0));
	while (i < 8)
		data[i++] = alpha[std::rand() % (sizeof(alpha) - 1)];
	data[i++] = 0;
	tmp = reinterpret_cast<int*>(data + i);
	*tmp = std::rand();
	i += 4;
	j = 0;
	while (j < 8) {
		data[i++] = alpha[std::rand() % (sizeof(alpha) - 1)];
		j++;
	}
	data[i] = 0;
	return reinterpret_cast<void*>(data);
}

Data *		deserialize(void *raw)
{
	Data 	*data = new Data;
	int		*n;
	char 	*tmp;

	tmp = reinterpret_cast<char*>(raw);
	data->s1 = tmp;
	tmp += 9;
	n = reinterpret_cast<int*>(tmp);
	data->n = *n;
	tmp += 4;
	data->s2 = tmp;
	return data;
}

int			main(void)
{
	void	*serializedData;

	serializedData = serialize();
	Data * data = deserialize(serializedData);
	std::cout
	<< "data->s1 : "
	<< data->s1
	<< std::endl
	<< "data->s2 : "
	<< data->s2
	<< std::endl
	<< "data->n : "
	<< data->n
	<< std::endl;

	delete reinterpret_cast<char *>(serializedData);
	delete data;
	return 0;
}
