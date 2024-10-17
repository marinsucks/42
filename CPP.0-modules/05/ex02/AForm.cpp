/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:57:33 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/17 12:50:07 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm()
	: _name("default"), _signed(false), _signGrade(150), _execGrade(150)
{}

AForm::AForm(std::string name, int signGrade, int execGrade)
	: _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& copy)
	: _name(copy._name), _signed(copy._signed), _signGrade(copy._signGrade), _execGrade(copy._execGrade)
{
	if (this == &copy)
		return ;
}

AForm& AForm::operator=(const AForm& copy)
{
	if (this == &copy)
		return *this;

	this->_signed = copy._signed;
	
	return *this;
}

AForm::~AForm() {}

void	AForm::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > this->_signGrade)
		throw Bureaucrat::GradeTooLowException();
	this->_signed = true;
}

std::string	AForm::getName() const
{
	return this->_name;
}

bool	AForm::getSigned() const
{
	return this->_signed;
}

int		AForm::getSignGrade() const
{
	return this->_signGrade;
}

int		AForm::getExecGrade() const
{
	return this->_execGrade;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "AForm grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "AForm grade is too low";
}

std::ostream&	operator<<(std::ostream& o, const AForm &form)
{
	o << "AForm " << form.getName();
	o << " is " << (form.getSigned() ? "" : "not ") << "signed, ";
	o << "requires a grade " << form.getSignGrade() << " to be signed ";
	o << "and a grade " << form.getExecGrade() << " to be executed.";
	return o;
}	
