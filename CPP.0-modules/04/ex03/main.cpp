/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:19:37 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/30 17:37:55 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main()
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
	player->equip(i);


	for (int j = 0; j < 4; j++)
		player->use(j, *player);

	//test copy constructors
	Character *playerCopy = new Character(*player);
	Character playerCopy2 = *player;

	delete	c;
	delete	i;
	delete	player;
	delete	playerCopy;
	return 0;
}

//int main()
//{
//	IMateriaSource* src = new MateriaSource();

//	src->learnMateria(new Ice());
//	src->learnMateria(new Cure());

//	ICharacter* me = new Character("me");

//	AMateria* tmp;

//	tmp = src->createMateria("ice");
//	me->equip(tmp);
//	tmp = src->createMateria("cure");
//	me->equip(tmp);

//	ICharacter* bob = new Character("bob");

//	me->use(0, *bob);
//	me->use(1, *bob);

//	delete bob;
//	delete me;
//	delete src;

//	return 0;
//}
