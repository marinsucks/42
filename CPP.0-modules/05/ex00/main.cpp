/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:49:41 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/15 16:28:40 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	gradeTooLow(void)
{
	std::cout << "gradeTooLow(): " << std::endl;
	try
	{
		std::cout << "Creating Chuck with grade 151" << std::endl;
		Bureaucrat chuck("Chuck", 151);
		std::cout << chuck.getName() << " successfully created with grade " << chuck.getGrade() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	gradeTooHigh(void)
{
	std::cout << "gradeTooHigh(): " << std::endl;
	try
	{
		std::cout << "Creating Jack with grade 151" << std::endl;
		Bureaucrat jack("Jack", 0);
		std::cout << jack.getName() << " successfully created with grade " << jack.getGrade() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	badIncrement(void)
{
	std::cout << "badIncrement(): " << std::endl;
	try
	{
		std::cout << "Creating Gary with grade 1" << std::endl;
		Bureaucrat gary("Gary", 1);
		std::cout << gary.getName() << " successfully created with grade " << gary.getGrade() << std::endl;
		
		std::cout << "Incrementing Gary" << std::endl;
		gary.incrementGrade();
		std::cout << gary.getName() << " successfully incremented to grade " << gary.getGrade() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	badDecrement(void)
{
	std::cout << "badDecrement(): " << std::endl;
	try
	{
		std::cout << "Creating Ron with grade 150" << std::endl;
		Bureaucrat ron("Ron", 150);
		std::cout << ron.getName() << " successfully created with grade " << ron.getGrade() << std::endl;
		
		std::cout << "Decrementing Ron" << std::endl;
		ron.decrementGrade();
		std::cout << ron.getName() << " successfully decremented to grade " << ron.getGrade() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}


int main(void)
{
	gradeTooLow();
	std::cout << std::endl;
	gradeTooHigh();
	std::cout << std::endl;
	badIncrement();
	std::cout << std::endl;
	badDecrement();

	return 0;
}
