/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:24:42 by mbecker           #+#    #+#             */
/*   Updated: 2024/03/26 17:22:27 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	gettimestamp(t_specs *data)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000 - data->start_time);
}

int	main(int ac, char const *av[])
{
	t_specs	data;

	if (!philo_parsing(ac, av, &data))
		return (1);
	
	data.start_time = gettimestamp(&data); // put at start of simulation
	
	
	
	return (0);
}
