/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:47:47 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/24 17:11:26 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main()
{
	Data *instance = new Data;
	std::cout << "Instance:     "<< instance << std::endl;

	uintptr_t serialized = Serializer::serialize(instance);
	std::cout << "Serialized:   " << serialized << std::endl;

	Data *deserialized = Serializer::deserialize(serialized);
	std::cout << "Deserialized: " << deserialized << std::endl;


	if (instance == deserialized)
		std::cout << "Success" << std::endl;
	else
		std::cout << "Failure" << std::endl;
	
	delete instance;
	return 0;
}
