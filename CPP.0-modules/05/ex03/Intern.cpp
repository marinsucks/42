/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:10:18 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/19 10:45:56 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	_formNames[0] = "shrubbery creation";
	_formNames[1] = "robotomy request";
	_formNames[2] = "presidential pardon";
}

Intern::Intern(const Intern& copy)
{
	(void)copy;
	_formNames[0] = "shrubbery creation";
	_formNames[1] = "robotomy request";
	_formNames[2] = "presidential pardon";
}

Intern& Intern::operator=(const Intern& copy) 
{ 
	(void)copy;
	return *this; 
}

Intern::~Intern() {}

AForm	*Intern::makeForm(std::string formName, std::string target)
{
	int i = 0;
	while (i < 3 && _formNames[i] != formName)
		i++;

	switch (i)
	{
		case 0:
			return new ShrubberyCreationForm(target);
		case 1:
			return new RobotomyRequestForm(target);
		case 2:
			return new PresidentialPardonForm(target);
		default:
			std::cout << "Intern hasn't learnt to create " << formName << " yet." << std::endl;
			return NULL;
	}
}
