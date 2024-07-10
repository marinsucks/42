/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:19:41 by mbecker           #+#    #+#             */
/*   Updated: 2024/06/28 16:13:36 by mbecker          ###   ########.fr       */
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

# define TOO_FEW_ARG 	"too few arguments\n"
# define TOO_MANY_ARG 	"too many arguments\n"
# define NOT_AN_UINT 	"invalid argument: not a positive int\n"

# define TRUE			1
# define FALSE			0
# define INT_MAX		2147483647

/* 
 * `pthread_t`			thread;
 * `int`				id;
 * `pthread_mutex_t *`	left_mutex;
 * `pthread_mutex_t *`	right_mutex;
 * `int`				died;
 * `int`				last_meal;
 * `int`				meals_eaten;
 * `t_data *`			data;
*/
typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	pthread_mutex_t	*left_mutex;
	pthread_mutex_t	*right_mutex;
	int				died;
	int				last_meal;
	int				meals_eaten;
	struct s_data	*data;
}					t_philo;

/*
 * `int`				nb_philo;
 * `int`				time_to_die;
 * `int`				time_to_eat;
 * `int`				time_to_sleep;
 * `int`				max_meal;
 * 
 * `t_philo **`			philo_tab;
 *
 * `pthread_mutex_t **`	mutex;
 * `pthread_mutex_t`	printf_mutex;
 * `pthread_mutex_t`	check_mutex;
 * 
 * `int`				start_time;
 * `int`				simulation_start;
 * `int`				death;
 * `int`				meals_left;
*/
typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_meal;

	t_philo			**philo_tab;

	pthread_mutex_t	*forks;
	pthread_mutex_t	printf_mutex;
	pthread_mutex_t	check_mutex;

	int				start_time;
	int				simulation_start;
	int				death;
	int				all_full;
}					t_data;

int			error(char *error_msg);
// error.c

//void		lock_forks(t_philo *philo);
//void		release_forks(t_philo *philo);
int			takes_forks(t_philo *philo);
// forks.c

void		freentab(char **tab, int heap, int n);
void		freedata(t_data *data, int nb_philo);
// free.c

void		state(t_philo *philo, char *status);
int			dies(t_philo *philo);
int			eats(t_philo *philo);
void		*philo_routine(void *philo);
// routine.c

int			create_threads(t_data *data);
void		join_threads(t_data *data);
// threads.c

int			gettimestamp(int start_time);
int			ft_strcmp(const char *s1, const char *s2);
long		ft_atol(const char *str);
int			ft_isnum(const char *str);
//utils.c

#endif
