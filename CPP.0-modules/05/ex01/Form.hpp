/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:44:06 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/17 12:50:07 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Bureaucrat;

#include "Bureaucrat.hpp"

class Form
{
	private:
		std::string const	_name;
		bool							_signed;
		int const			_signGrade;
		int const			_execGrade;

	public:
		Form();
		Form(std::string name, int signGrade, int execGrade);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		void		beSigned(Bureaucrat& b);

		std::string	getName() const;
		bool		getSigned() const;
		int			getSignGrade() const;
		int			getExecGrade() const;

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& form);
