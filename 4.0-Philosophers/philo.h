/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:19:41 by mbecker           #+#    #+#             */
/*   Updated: 2024/03/26 17:19:46 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H//REMOVE $(NAME) from Makefile before pushing
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define TOO_FEW_ARG "Error: Too few arguments.\n"
# define TOO_MANY_ARG "Error: Too many arguments.\n"
# define NOT_AN_UINT "Error: Invalid argument: not a positive int.\n"
# define INT_MAX 2147483647

typedef struct s_philo
{
	int	id;
	int	died;
	int	is_eating;
	int	must_eat;
}		t_philo;

typedef struct s_specs
{
	int				start_time;
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_must_eat;
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
}					t_specs;

int	philo_parsing(int ac, char const *av[], t_specs *data);
// philo_parsing.c

int	gettimestamp(t_specs *data);
// ?.c

#endif
