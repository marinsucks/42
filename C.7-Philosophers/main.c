/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:24:42 by mbecker           #+#    #+#             */
/*   Updated: 2024/06/28 15:04:51 by mbecker          ###   ########.fr       */
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
	*data = (t_data){
		ft_atol(av[1]),
		ft_atol(av[2]),
		ft_atol(av[3]),
		ft_atol(av[4]),
		-1,
		NULL,
		NULL,
		data->printf_mutex,
		data->check_mutex,
		0,
		0,
		0,
		0
	};
	if (ac == 6)
		data->max_meal = ft_atol(av[5]);
	data->philo_tab = malloc((sizeof(t_philo *) * data->nb_philo));
	data->forks = malloc((sizeof(pthread_mutex_t) * data->nb_philo));
	if (!data->philo_tab || !data->forks)
		return (error("fatal: malloc failed\n"));
	return (0);
}

int	main(int ac, char const *av[])
{
	t_data	data;
	int		failure;

	if (philo_parsing(ac, av))
		return (1);
	init_data(&data, ac, av);
	failure = create_threads(&data);
	if (failure)
	{
		freedata(&data, failure);
		return (error("create_threads failed\n"));
	}
	join_threads(&data);
	freedata(&data, data.nb_philo);
	return (0);
}
