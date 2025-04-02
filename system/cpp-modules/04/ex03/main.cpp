/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:19:37 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/11 12:14:25 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

void	subject(void)
{
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

void	basic(void)
{
	AMateria* i = new Ice();
	AMateria* c = new Cure();
	Character	*player = new Character("player");

	i->use(*player);
	c->use(*player);


	player->equip(i);
	player->equip(c);
	player->equip(i);
	player->equip(c);
	player->equip(i); //should not equip


	for (int j = 0; j < 4; j++)
		player->use(j, *player);

	player->unequip(0);
	player->unequip(1);

	delete	player;
}

void	copy(void)
{
	Character a("a");
	Character b("b");
	a.equip(new Ice());
	b.equip(new Ice());
	b = a;

	//test copy constructors
	std::cout << "creating playerTest" << std::endl;
	Character *playerTest = new Character("playerTest");

	std::cout << "creating playerCopy using copy constructor" << std::endl;
	Character *playerCopy = new Character(*playerTest);

	std::cout << "creating playerCopy2 using copy assignment operator" << std::endl;
	Character playerCopy2;
	playerCopy2 = *playerTest;

	std::cout << "delete playerCopy" << std::endl;
	delete	playerCopy;
	std::cout << "delete playerTest" << std::endl;
	delete	playerTest;
}

int main()
{
	std::cout << "Subject test" << std::endl;
	subject();
	std::cout << std::endl;

	std::cout << "Basic test" << std::endl;
	basic();
	std::cout << std::endl;

	std::cout << "Copy test" << std::endl;
	copy();
	std::cout << std::endl;

	return 0;
}

