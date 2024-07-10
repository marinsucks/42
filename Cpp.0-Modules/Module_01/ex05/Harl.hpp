/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:28:51 by mbecker           #+#    #+#             */
/*   Updated: 2024/07/09 16:07:15 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Harl
{
	private:
		std::string _levels[4];
		void (Harl::*_funcs[4])();
		void debug();
		void info();
		void warning();
		void error();
	public:
		Harl();
		void complain(std::string level);
};
