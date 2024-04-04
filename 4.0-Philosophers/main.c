/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:24:42 by mbecker           #+#    #+#             */
/*   Updated: 2024/03/28 13:18:41 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	gettimestamp(t_specs *data)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000 - data->start_time);
}

int create_threads(t_specs *specs)//, t_philo *philo)
{
	int i;

	i = 0;
	while (i < specs->nb_philo)
	{
		//if (pthread_create(philo[i].id, NULL, &philo_routine, &philo[i]))
		//	return (write(2, "Error: pthread_create\n", 23), 1);
		i++;
	}
	return (0);
}

int	main(int ac, char const *av[])
{
	t_specs	specs;

	if (!philo_parsing(ac, av, &specs))
		return (1);
	t_philo	*philo = malloc(sizeof(t_philo) * specs.nb_philo);
	if (!philo)
		return (write(2, "Malloc error\n", 13), 2);

	specs.start_time = gettimestamp(&specs); // put at start of simulation
	if (create_threads(&specs))//, philo))
		return (1);
	
	return (0);
}
