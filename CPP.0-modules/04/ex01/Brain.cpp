/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:10:53 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/08 17:59:41 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;

	for (int i = 0; i < 100; i++)
	{
		ideas[i] = "idea #";
		ideas[i].push_back(i / 100 + 48);
		ideas[i].push_back(i / 10 + 48);
		ideas[i].push_back(i % 10 + 48);
	}
}

Brain::Brain(Brain const &copy)
{
	std::cout << "Brain copy constructor called" << std::endl;

	Brain const *nullcheck = &copy;
	if (nullcheck == NULL)
		*this = Brain();
	else if (this != &copy)
		*this = copy;
}

Brain	&Brain::operator=(Brain const &copy)
{
	std::cout << "Brain assignation operator called" << std::endl;

	Brain const *nullcheck = &copy;
	if (this == &copy || nullcheck == NULL)
		return *this;

	for (int i = 0; i < 100; i++)
		ideas[i] = copy.ideas[i];

	return *this;
}


Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

void	Brain::appendIdeas( std::string new_idea )
{
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = new_idea + "idea #";
		ideas[i].push_back(i / 100 + 48);
		ideas[i].push_back(i / 10 + 48);
		ideas[i].push_back(i % 10 + 48);
	}
} 

std::string	Brain::getIdea(int i)
{
	return ideas[i];
} 
