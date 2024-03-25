/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:19:41 by mbecker           #+#    #+#             */
/*   Updated: 2024/03/25 14:26:29 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>


# define TOO_FEW_ARG "Error: Too few arguments.\n"
# define TOO_MANY_ARG "Error: Too many arguments.\n"
# define INVALID_ARG "Error: Invalid argument.\n"
# define NOT_NUM "Error: Argument is not a number.\n"
# define INT_MAX 2147483647

typedef struct s_philo
{
	int				id;
	int				nb_philo;
	int				die;
	int				eat;
	int				sleep;
	int				must_eat;
	int				*forks;
	int				*forks_status;
	int				*last_meal;
	int				*nb_meal;
	int				*is_dead;
	int				*is_full;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*dead_mutex;
	pthread_mutex_t	*full_mutex;
}				t_philo;

int	philo_parsing(int ac, char const *av[], t_philo *data);
// philo_parsing.c

#endif
