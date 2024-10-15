/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:24:43 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/15 18:09:25 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade)
	: _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) 
	: _name(copy._name), _grade(copy._grade)
{
	if (this == &copy)
		return ;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
	if (this == &copy)
		return *this;

	this->_grade = copy._grade;

	return *this;
}

Bureaucrat::~Bureaucrat(){}


std::string	Bureaucrat::getName() const
{
	return this->_name;
}

int			Bureaucrat::getGrade() const
{
	return this->_grade;
}

void		Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void		Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void		Bureaucrat::signForm(Form& form)
{
	//Objects successfully compiled in /home/mbecker/42/CPP.0-modules/05/ex01/obj/.
	///usr/bin/ld: /tmp/Bureaucrat-e05a4b.o: in function `Bureaucrat::signForm(Form&)':
	//Bureaucrat.cpp:(.text+0x380): undefined reference to `Form::beSigned(Bureaucrat&)'
	///usr/bin/ld: Bureaucrat.cpp:(.text+0x3c6): undefined reference to `Form::getName[abi:cxx11]() const'
	///usr/bin/ld: Bureaucrat.cpp:(.text+0x4a8): undefined reference to `Form::getName[abi:cxx11]() const'
	//clang: error: linker command failed with exit code 1 (use -v to see invocation)
	//make: *** [Makefile:28: ex00] Error 1
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed the form" << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->_name << " couldn't sign the form " << form.getName() << " because " << e.what() << std::endl;
	}
	
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat grade is too low";
}

std::ostream&	operator<<(std::ostream& o, Bureaucrat const & b ) {
	o << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return o;
}
