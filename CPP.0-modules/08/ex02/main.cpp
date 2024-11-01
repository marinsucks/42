#include <iostream>
#include <list>
#include "MutantStack.hpp"

template <class C>
void	test(std::string title)
{
	std::cout << title << std::endl;

	C whatever;

	std::cout << "push(5)" << std::endl;
	whatever.push(5);
	std::cout << "push(17)" << std::endl;
	whatever.push(17);
	std::cout << "CONTENT: " << whatever << std::endl;
	std::cout << "SIZE: " << whatever.size() << std::endl;
	std::cout << "TOP: " << whatever.top() << std::endl;
	
	std::cout << std::endl;

	std::cout << "pop()" << std::endl;
	whatever.pop();
	std::cout << "CONTENT: " << whatever << std::endl;
	std::cout << "SIZE: " << whatever.size() << std::endl;
	std::cout << "TOP: " << whatever.top() << std::endl;

	std::cout << std::endl;

	std::cout << "push(3)" << std::endl;
	whatever.push(3);
	std::cout << "push(5)" << std::endl;
	whatever.push(5);
	std::cout << "push(737)" << std::endl;
	whatever.push(737);
	std::cout << "push(0)" << std::endl;
	whatever.push(0);
	std::cout << "CONTENT: " << whatever << std::endl;
	std::cout << "SIZE: " << whatever.size() << std::endl;
	std::cout << "TOP: " << whatever.top() << std::endl;

	std::cout << std::endl;

	std::cout << "ITERATOR" << std::endl;
	MutantStack<int>::iterator begin = whatever.begin();
	MutantStack<int>::iterator end = whatever.end();
	while (begin != end)
	{
		static int i = 0;
		std::cout << "iterator [" << i++ << "] " << *begin << std::endl;
		++begin;
	}
}


int main()
{
	test<MutantStack<int> >("MutantStack<int>");
	return 0;
}
