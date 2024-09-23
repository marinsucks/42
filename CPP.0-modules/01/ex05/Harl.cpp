/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:39:28 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/11 16:59:19 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include "colors.hpp"

Harl::Harl() 
{
	_levels[0] = "DEBUG";
	_levels[1] = "INFO";
	_levels[2] = "WANING";
	_levels[3] = "ERROR";
	_funcs[0] = &Harl::debug;
	_funcs[1] = &Harl::info;
	_funcs[2] = &Harl::warning;
	_funcs[3] = &Harl::error;
}

void	Harl::debug()
{
	std::cout << GREEN << "[DEBUG]\t\t" ;
	std::cout << LGREEN << "Just passed the piscine !!! So excited to start my libft." << std::endl;
	std::cout << NC;
}

void	Harl::info()
{
	std::cout << YELLOW << "[INFO]\t\t" ;
	std::cout << LYELLOW << "Sweet, another segfault in my push_swap. Because the ten previous error messages really made it clearer 👍" << std::endl;
	std::cout << NC;
}

void	Harl::warning()
{
	std::cout << MAGENTA << "[WARNING]\t" ;
	std::cout << LMAGENTA << "Seriously ?? Are you really gonna do everything in your power to break my minishell ???" << std::endl;
	std::cout << NC;
}

void	Harl::error()
{
	std::cout << RED << "[ERROR]\t\t" ;
	std::cout << LRED << "This is too much I'm calling Xavier Niel..." << std::endl;
	std::cout << NC;
}

void Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (!level.compare(_levels[i]))
		{
			(this->*_funcs[i])();
			return ;
		}
	}	
	std::cout << CYAN << "[Finally, some silence...]" << NC << std::endl;
}
