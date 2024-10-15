/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:57:33 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/15 17:40:41 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
	: _name("default"), _signed(false), _signGrade(150), _execGrade(150)
{}

Form::Form(std::string name, int signGrade, int execGrade)
	: _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& copy)
	: _name(copy._name), _signed(copy._signed), _signGrade(copy._signGrade), _execGrade(copy._execGrade)
{
	if (this == &copy)
		return ;
}

Form& Form::operator=(const Form& copy)
{
	if (this == &copy)
		return *this;

	this->_signed = copy._signed;
	
	return *this;
}

Form::~Form() {}

void	Form::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

std::string	Form::getName() const
{
	return this->_name;
}

bool	Form::getSigned() const
{
	return this->_signed;
}

int		Form::getSignGrade() const
{
	return this->_signGrade;
}

int		Form::getExecGrade() const
{
	return this->_execGrade;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form grade is too low";
}

std::ostream&	operator<<(std::ostream& o, Form &i)
{
	o << "Form " << i.getName();
	o << " is " << (i.getSigned() ? "" : "not ") << "signed, ";
	o << "requires a grade " << i.getSignGrade() << " to be signed ";
	o << "and a grade " << i.getExecGrade() << " to be executed." << std::endl;
}	
