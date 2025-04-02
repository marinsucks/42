/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:49:41 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/18 17:04:23 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	testAllForms(Bureaucrat& b)
{
	ShrubberyCreationForm shrubbery(b.getName());
	RobotomyRequestForm robotomy(b.getName());
	PresidentialPardonForm pardon(b.getName());

	std::cout << b << std::endl;

	b.signForm(shrubbery);
	b.signForm(robotomy);

	b.signForm(pardon);

	b.executeForm(shrubbery);
	b.executeForm(robotomy);
	b.executeForm(pardon);
}

int main(void)
{
	Bureaucrat President("President", 1);
	Bureaucrat Surgeon("Surgeon", 45);
	Bureaucrat Secretary("Secretary", 110);
	Bureaucrat Intern("Intern", 140);
	Bureaucrat Toddler("Toddler", 150);

	testAllForms(President);
	std::cout << std::endl;
	testAllForms(Surgeon);
	std::cout << std::endl;
	testAllForms(Secretary);
	std::cout << std::endl;
	testAllForms(Intern);
	std::cout << std::endl;
	testAllForms(Toddler);

	return 0;
}
