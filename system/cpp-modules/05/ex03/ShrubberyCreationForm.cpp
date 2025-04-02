/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:02:35 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/18 15:58:19 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
	: AForm("Shrubbery Creation", 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
	: AForm("Shrubbery Creation", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
	: AForm(copy.getName(), 145, 137), _target(copy._target)
{
	if (this == &copy)
		return ;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	if (this == &copy)
		return *this;

	this->_target = copy._target;

	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::beExecuted(void) const
{
	std::string filename = this->_target + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (file.is_open())
	{
		file << SHRUBBERY << std::endl;
		file.close();
	}
	else
		std::cerr << "Error: could not open " << filename << std::endl;
}
