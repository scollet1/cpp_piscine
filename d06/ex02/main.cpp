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

#include <ctime>
#include <iostream>

class Base {
public:
	virtual ~Base(void) {};
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base*		generate(void)
{
	std::srand(std::time(0));
	int		rd = std::rand();
	rd = rd % 3;
	if (rd == 0) {
		A* a = new A;;
		std::cout << "A" << std::endl;
		return static_cast<Base*>(a);
	} else if (rd == 1) {
		B* b = new B;
		std::cout << "B" << std::endl;
		return static_cast<Base*>(b);
	}
	C* c = new C;
	std::cout << "C" << std::endl;
	return static_cast<Base*>(c);
}

void		IDpointer(Base* p)
{
	A* a = dynamic_cast<A*>(p);
	if (a) {
		std::cout << "A pointer" << std::endl;
		return;
	}
	B* b = dynamic_cast<B*>(p);
	if (b) {
		std::cout << "B pointer" << std::endl;
		return;
	}
	C* c = dynamic_cast<C*>(p);
	if (c) {
		std::cout << "C pointer" << std::endl;
		return;
	}
	return;
}

void		IDreference(Base & p)
{
	try {
		A & a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A reference" << std::endl;
	} catch (std::bad_cast &bc) {
		try {
			B & b = dynamic_cast<B &>(p);
			(void)b;
			std::cout << "B reference" << std::endl;
		} catch (std::bad_cast &bc) {
			try {
				C & c = dynamic_cast<C &>(p);
				(void)c;
				std::cout << "C reference" << std::endl;
			} catch (std::bad_cast &bc) {
				return;
			} return;
		} return;
	} return;
}

int			main(void)
{
	Base* base = generate();

	IDpointer(base);
	IDreference(*base);

	return 0;
}
