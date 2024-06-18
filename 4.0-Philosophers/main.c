/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:24:42 by mbecker           #+#    #+#             */
/*   Updated: 2024/06/18 17:22:50 by mbecker          ###   ########.fr       */
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

	*data = (t_data){NULL, NULL, NULL, ft_atol(av[1]), ft_atol(av[2]),
		ft_atol(av[3]), ft_atol(av[4]), -1, 0, 0};
	if (ac == 6)
		data->max_meal = ft_atol(av[5]);
	data->philo_tab = malloc((sizeof(t_philo *) * data->nb_philo));
	data->forks = malloc((sizeof(int *) * data->nb_philo));
	data->mutex = malloc((sizeof(int *) * data->nb_philo));
	if (!data->philo_tab || !data->forks || !data->mutex)
		return (error("fatal: malloc failed\n"));
	i = 0;
	while (i < data->nb_philo)
	{
		data->forks[i] = malloc(sizeof(int));
		data->mutex[i] = malloc(sizeof(pthread_mutex_t));
		if (!data->forks[i] || !data->mutex[i])
			return (error("fatal: malloc failed\n"));
		*data->forks[i] = 1;
		i++;
	}
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
			return (error("fatal: malloc failed\n"));
		*philo = (t_philo){
			philo->thread, 
			i,  
			0, 
			0, 
			0, 
			data->forks[i], 						//l, shared with i-1 
			data->forks[(i + 1) % data->nb_philo],	//r, shared with i+1
			data->mutex[i],							//l, shared with i-1
			data->mutex[(i + 1) % data->nb_philo],	//r, shared with i+1
			0,
			data->max_meal, 
			data
		};
		data->philo_tab[i] = philo;
		pthread_mutex_init(data->mutex[i], NULL);
		if (pthread_create(&philo->thread, NULL, &philo_routine, philo))
			return (error("pthread_create failed\n"), i);
		printf("philo %d: %p | %p | %p | %p\n", i, philo->left_fork, philo->right_fork, philo->left_mutex, philo->right_mutex); // DEBUG
		i++;
	}
	data->simulation_start = 1;
	return (0);
}

void	join_threads(t_data *data)
{
	t_philo *philo;
	int		i;

	i = 0;
	while (i < data->nb_philo)
	{
		philo = data->philo_tab[i];
		if (!philo->died && pthread_join(philo->thread, NULL))
			error("pthread_join failed\n");
		pthread_mutex_destroy(data->mutex[i]);
		i++;
	}
}

int	main(int ac, char const *av[])
{
	t_data	data;
	int		failure;

	if (philo_parsing(ac, av))
		return (1);
	init_data(&data, ac, av);
	//pthread_mutex_init(&data.mutex, NULL);
	failure = create_threads(&data);
	if (failure)
	{
		freedata(&data, failure);
		return (error("create_threads failed\n"));
	}
	join_threads(&data);
	//pthread_mutex_destroy(&data.mutex);
	freedata(&data, data.nb_philo);
	return (0);
}
