/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:10:18 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/18 17:15:51 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& copy) {}

Intern& Intern::operator=(const Intern& copy) { return *this; }

Intern::~Intern() {}

AForm	*Intern::makeForm(std::string formName, std::string target)
{
	if (formName == "shrubbery creation")
		return new ShrubberyCreationForm(target);
	if (formName == "robotomy request")
		return new RobotomyRequestForm(target);
	if (formName == "presidential pardon")
		return new PresidentialPardonForm(target);
	return NULL;
}
