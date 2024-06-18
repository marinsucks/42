/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:19:41 by mbecker           #+#    #+#             */
/*   Updated: 2024/06/18 15:58:49 by mbecker          ###   ########.fr       */
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
 * `int`				died;
 * `int`				is_eating;
 * `int`				is_thinking;
 * `int *`				left_fork;
 * `int *`				right_fork;
 * `pthread_mutex_t *`	left_mutex;
 * `pthread_mutex_t *`	right_mutex;
 * `int`				last_meal;
 * `int`				max_meal;
 * `t_data *`			data;
*/
typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				died;
	int				is_eating;
	int				is_thinking;
	int				*left_fork;
	int				*right_fork;
	pthread_mutex_t	*left_mutex;
	pthread_mutex_t	*right_mutex;
	int				last_meal;
	int				max_meal;
	struct s_data	*data;
}					t_philo;

/*
 * `t_philo **`			philo_tab;
 * `int **`				forks;
 * `pthread_mutex_t **`	mutex;
 * `int`				nb_philo;
 * `int`				time_to_die;
 * `int`				time_to_eat;
 * `int`				time_to_sleep;
 * `int`				max_meal;
 * `int`				start_time;
 * `int`				simulation_start;
*/
typedef struct s_data
{
	t_philo			**philo_tab;
	int				**forks;
	pthread_mutex_t	**mutex;
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_meal;
	int				start_time;
	int				simulation_start;
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

int			gettimestamp(int start_time);
int			ft_strcmp(const char *s1, const char *s2);
long		ft_atol(const char *str);
int			ft_isnum(const char *str);
//utils.c

#endif
