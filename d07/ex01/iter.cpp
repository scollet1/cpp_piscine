/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 20:39:11 by scollet           #+#    #+#             */
/*   Updated: 2018/01/17 20:42:12 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>

void actualFunction(const T & param) {
	std::cout
	<< param
	<< std::endl;
	return ;
}

template <typename T>

void iter(T * arry, size_t len, void (*f)(const T &)) {
	for (size_t i = 0; i < len; i++) {
		f(arry[i]);
	} return ;
}

int main(void) {
	int arr[6] = {
		'a', 'b', 'c', 'd', 'e', 'f'
	};
	::iter(arr, 6, actualFunction);
	return 0;
}
