/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:19:41 by mbecker           #+#    #+#             */
/*   Updated: 2024/06/11 16:30:23 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H//REMOVE $(NAME) from Makefile before pushing
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <time.h>
# include <pthread.h>

# define PROGRAM_NAME	"philo"

# define TOO_FEW_ARG 	"Error: Too few arguments.\n"
# define TOO_MANY_ARG 	"Error: Too many arguments.\n"
# define NOT_AN_UINT 	"Error: Invalid argument: not a positive int.\n"

# define TRUE			1
# define FALSE			0
# define INT_MAX		2147483647


/**

 * `int`			start_time;
 * `int`			nb_philo;
 * `int`			time_to_die;
 * `int`			time_to_eat;
 * `int`			time_to_sleep;
 * `int`			nb_must_eat; (minimum nb of meal before end of simulation)
 * `int`			forks;
 * `int	*`			forks_status;
 * `int	*`			last_meal;
 * `int	*`			nb_meal;
 * `int	*`			is_dead;
 * `int	*`			is_full;
*/
typedef struct s_params
{
	int				start_time;
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_must_eat;
	int				forks;
	int				*forks_status;
	int				*last_meal;
	int				*nb_meal;
	int				*is_dead;
	int				*is_full;
}					t_params;

//typedef struct s_mutex
//{
//	pthread_mutex_t	mtx;
//	pthread_mutex_t	print;
//	pthread_mutex_t	dead;
//	pthread_mutex_t	full;
//}					t_mutex;

/*
 * `pthread_t`	thread;
 * `int`		id;
 * `int`		died;
 * `int`		is_eating;
 * `int`		must_eat;
 * `t_data *`	data;
*/
typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				died;
	int				is_eating;
	int				must_eat;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	t_params		*params;
	//t_mutex		*mutex;
	pthread_mutex_t	mutex;
	t_philo			**forum;
}					t_data;

t_params	*philo_parsing(int ac, char const *av[]);
// parsing.c

int			gettimestamp(int start_time);
// main.c

void		*philo_routine(void *philo);
// threads.c

int			error(char *error_msg);
// error.c

void		freetab(char **tab, int heap);
void		freedata(t_data data);
// free.c

#endif
