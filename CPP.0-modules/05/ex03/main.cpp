/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:49:41 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/19 10:58:39 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#include <unistd.h>

void	testForm(AForm* form)
{
	if (!form)
	{
		std::cout << "testForm(NULL)" << std::endl;
		return ;
	}

	std::cout << "testForm(" << form->getName() << ")" << std::endl;
	
	Bureaucrat toddler("Toddler", 150);
	Bureaucrat president("President", 1);
	
	toddler.signForm(*form);
	toddler.executeForm(*form);
	president.signForm(*form);
	president.executeForm(*form);
}

int main(void)
{
	sleep(30);

	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	testForm(rrf);
	delete rrf;
	
	AForm* scf;
	scf = someRandomIntern.makeForm("shrubbery creation", "Shrubber");
	testForm(scf);
	delete scf;

	AForm* ppf;
	ppf = someRandomIntern.makeForm("presidential pardon", "Presider");
	testForm(ppf);
	delete ppf;

	AForm* unknown;
	unknown = someRandomIntern.makeForm("unknown", "Unknown");
	testForm(unknown);
	delete unknown;

	return 0;
}
