/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:59:23 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/18 15:58:23 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream> 

#include "AForm.hpp"

#define SHRUBBERY \
"     ccee88oo\n\
  C8O8O8Q8PoOb o8oo\n\
 dOB69QO8PdUOpugoO9bD\n\
CgggbU8OU qOp qOdoUOdcb\n\
    6OuU  /p u gcoUodpP\n\
      \\\\\\//  /douUP\n\
        \\\\\\////\n\
         |||/\\\n\
         |||\\/\n\
         |||||\n\
   .....//||||\\...."

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		void	beExecuted(void) const;
};
