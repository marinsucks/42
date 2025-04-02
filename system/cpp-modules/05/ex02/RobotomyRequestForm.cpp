/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:02:35 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/18 14:32:09 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
	: AForm("Robotomy Request", 72, 45)
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target) 
	: AForm("Robotomy Request", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
	: AForm(copy.getName(), 72, 45), _target(copy._target)
{
	if (this == &copy)
		return ;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	if (this == &copy)
		return *this;

	this->_target = copy._target;

	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void	RobotomyRequestForm::beExecuted(void) const
{
	std::cout << "* DzzzzzzzzzzBrrrrrBBrBrrrrzzzzzzTSSSiiiiiii *" << std::endl;
	if (rand() % 2)
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->_target << " robotomization failed" << std::endl;
}
