/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:24:42 by mbecker           #+#    #+#             */
/*   Updated: 2024/06/14 17:33:17 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * Parses the command line arguments.
 * @return `0` if parsing is successful, `1` otherwise.
 */
int	philo_parsing(int ac, char const *av[])
{
	int			i;

	if (ac < 5)
		return (error(TOO_FEW_ARG));
	else if (ac > 6)
		return (error(TOO_MANY_ARG));
	i = 0;
	while (av[++i])
	{
		if (!ft_isnum(av[i]) || ft_atol(av[i]) < 0 || ft_atol(av[i]) > INT_MAX)
			return (error(NOT_AN_UINT));
	}
	return (0);
}

/**
 * Initializes the data structure with the given arguments.
 * @return 0 if successful, 1 if there was an error.
 */
int	init_data(t_data *data, int ac, char const *av[])
{
	int	i;

	*data = (t_data){data->mutex, data->forum, ft_atol(av[1]), ft_atol(av[2]),
		ft_atol(av[3]), ft_atol(av[4]), -1, 0, 0};
	if (ac == 6)
		data->max_meal = ft_atol(av[5]);
	data->forum = malloc((sizeof(t_philo *) * data->nb_philo));
	data->forks = malloc((sizeof(int *) * data->nb_philo));
	if (!data->forum || !data->forks)
		return (error("malloc failed\n"));
	i = 0;
	while (i < data->nb_philo)
	{
		data->forks[i] = malloc(sizeof(int));
		if (!data->forks[i])
			return (error("malloc failed\n"));
		*data->forks[i] = 1;
		i++;
	}
	data->start_time = gettimestamp(data->start_time);
	return (0);
}

/**
 * Creates threads for each philosopher and initializes their data.
 * 
 * @param data The data structure containing information about the philosophers.
 * @return 0 if successful, -1 if an error occurred.
 */
int	create_threads(t_data *data)
{
	t_philo *philo;
	int i;

	i = 0;
	while (i < data->nb_philo)
	{
		philo = malloc(sizeof(t_philo));
		if (!data->forks[i] || !philo)
			return (error("malloc failed\n"));
		*philo = (t_philo){0, i, 0, 0, 0, 
			data->forks[i], data->forks[(i + 1) % data->nb_philo], data};
		data->forum[i++] = philo;
		if (pthread_create(&philo->thread, NULL, &philo_routine, philo))
			return (error("pthread_create failed\n"));
	}
	return (0);
}

int	main(int ac, char const *av[])
{
	t_data	data;
	int		i;

	if (philo_parsing(ac, av))
		return (1);
	init_data(&data, ac, av);
	pthread_mutex_init(&data.mutex, NULL);
	if (create_threads(&data))
		return (error("create_threads failed\n"));
	i = 0;
	while (i < data.nb_philo)
	{
		if (pthread_join(data.forum[i++]->thread, NULL))
			return (error("pthread_join failed\n"));
	}
	pthread_mutex_destroy(&data.mutex);
	freedata(&data);
	return (0);
}

//void	*print_structs(t_data data)
//{
//	printf("start_time: \t%d\n", data.start_time);
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
