/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:30:43 by mbecker           #+#    #+#             */
/*   Updated: 2024/06/11 12:20:53 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long	ft_atol(const char *str)
{
	long	i;
	long	sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || ((str[i] >= 9 && str[i] <= 13) || (str[i] == '+'
				&& ft_isdigit(str[i + 1]))))
		i++;
	if ((str[i] == '-') && (str[i + 1] >= '0' && str[i + 1] <= '9'))
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

// Check if str is a number
int	ft_isnum(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

/**
 * Parses the command line arguments.
 *
 * @param params A pointer to the t_params structure where the parsed values
 * will be stored.
 * @return Returns 0 if parsing is successful, 1 otherwise.
 */
t_params	*philo_parsing(int ac, char const *av[])
{
	int			i;
	t_params	*params;

	params = (t_params *)malloc(sizeof(t_params));
	if (ac < 5)
		return (free(params), error(TOO_FEW_ARG), NULL);
	else if (ac > 6)
		return (free(params), error(TOO_MANY_ARG), NULL);
	i = 0;
	while (av[++i])
	{
		if (!ft_isnum(av[i]) || ft_atol(av[i]) < 0 || ft_atol(av[i]) > INT_MAX)
			return (free(params), error(NOT_AN_UINT), NULL);
	}
	*params = (t_params){0, ft_atol(av[1]), ft_atol(av[2]), ft_atol(av[3]),
		ft_atol(av[4]), 0, ft_atol(av[1]), 0, 0, 0, 0, 0};
	if (ac == 6)
		params->nb_must_eat = ft_atol(av[5]);
	else
		params->nb_must_eat = -1;
	return (params);
}
