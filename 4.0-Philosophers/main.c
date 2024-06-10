/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:24:42 by mbecker           #+#    #+#             */
/*   Updated: 2024/06/10 18:33:51 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * Calculates the timestamp in milliseconds since the start of the program.
 *
 * @param params The parameters struct containing the start time of the program.
 * @return The timestamp in milliseconds.
 */
int	gettimestamp(t_params *params)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000 - params->start_time);
}

int	create_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->params->nb_philo)
	{
		data->forum[i] = malloc(sizeof(t_philo));
		if (pthread_create(&data->forum[i]->id, NULL, &philo_routine, data))
			return (error("pthread_create failed\n"));
		i++;
	}
	data->forum[i] = NULL;
	return (0);
}

int	main(int ac, char const *av[])
{
	t_data	data;
	int		i;

	data.params = philo_parsing(ac, av);
	if (!data.params)
		return (1);
	data.params->start_time = gettimestamp(data.params); // put at start 
	data.forum = malloc((sizeof(t_philo *) * data.params->nb_philo) + 8);
	if (create_threads(&data))
		return (2);
	i = 0;
	while (i < data.params->nb_philo)
		pthread_join(data.forum[i++]->id, NULL);
	freedata(data);
	return (0);
}

//void	*print_structs(t_data data)
//{
//	printf("start_time: \t%d\n", data.params->start_time);
//	printf("nb_philo: \t%d\n", data.params->nb_philo);
//	printf("time_to_die: \t%d\n", data.params->time_to_die);
//	printf("time_to_eat: \t%d\n", data.params->time_to_eat);
//	printf("time_to_sleep: \t%d\n", data.params->time_to_sleep);
//	printf("nb_must_eat: \t%d\n", data.params->nb_must_eat);
//	printf("forks: \t\t%d\n", data.params->forks);
//	printf("forks_status: \t%p\n", (void*)data.params->forks_status);
//	printf("last_meal: \t%p\n", (void*)data.params->last_meal);
//	printf("nb_meal: \t%p\n", (void*)data.params->nb_meal);
//	printf("is_dead: \t%p\n", (void*)data.params->is_dead);
//	printf("is_full: \t%p\n", (void*)data.params->is_full);
//	printf("mutex: \t\t%p\n", (void*)data.params->mutex);
//	printf("print_mutex: \t%p\n", (void*)data.params->print_mutex);
//	printf("dead_mutex: \t%p\n", (void*)data.params->dead_mutex);
//	printf("full_mutex: \t%p\n", (void*)data.params->full_mutex);
//}
