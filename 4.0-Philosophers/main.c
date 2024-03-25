/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:24:42 by mbecker           #+#    #+#             */
/*   Updated: 2024/03/25 14:24:40 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char const *av[])
{
	t_philo	data;

	if (!philo_parsing(ac, av, &data))
		return (1);

	printf("nb_philo: %d\n", data.nb_philo);
	printf("die: %d\n", data.die);
	printf("eat: %d\n", data.eat);
	printf("sleep: %d\n", data.sleep);
	printf("must_eat: %d\n", data.must_eat);
	printf("forks: %p\n", data.forks);
	printf("forks_status: %p\n", data.forks_status);
	printf("last_meal: %p\n", data.last_meal);
	printf("nb_meal: %p\n", data.nb_meal);
	printf("is_dead: %p\n", data.is_dead);
	printf("is_full: %p\n", data.is_full);
	printf("mutex: %p\n", data.mutex);
	printf("print_mutex: %p\n", data.print_mutex);
	printf("dead_mutex: %p\n", data.dead_mutex);
	printf("full_mutex: %p\n", data.full_mutex);
	

	return (0);
}
