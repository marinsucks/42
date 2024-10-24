/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:20:47 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/24 18:08:03 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>

Base* generate(void)
{
	srand(time(0) + clock());
	int irand = rand() % 3;

	switch (irand)
	{
		case 0:
			std::cout << "A generated" << std::endl;
			return new A;
		case 1:
			std::cout << "B generated" << std::endl;
			return new B;
		case 2:
			std::cout << "C generated" << std::endl;
			return new C;
	}
	return NULL;
}

void identify(Base* p) 
{
	if (dynamic_cast<A*>(p))
		std::cout << "Pointer is of type A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Pointer is of type B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Pointer is of type C" << std::endl;
}

void identify(Base& p) 
{
	try 
	{
		A &a = dynamic_cast<A&>(p);
		(void) a;
		std::cout << "Reference is of type A" << std::endl;
	}
	catch (std::exception &e) {}

	try
	{
		B &b = dynamic_cast<B&>(p);
		(void) b;
		std::cout << "Reference is of type B" << std::endl;
	}
	catch (std::exception &e) {}

	try
	{
		C &c = dynamic_cast<C&>(p);
		(void) c;
		std::cout << "Reference is of type C" << std::endl;
	}
	catch (std::exception &e) {}
}

int main()
{
	for (int i = 0; i < 10; i++)
	{
		Base *random = generate();
		identify(*random);
		delete random;
	}
	
	return 0;
}
