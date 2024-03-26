/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:30:43 by mbecker           #+#    #+#             */
/*   Updated: 2024/03/26 17:21:58 by mbecker          ###   ########.fr       */
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

int	philo_parsing(int ac, char const *av[], t_specs *data)
{
	int	i;

	if (ac < 5)
		return (write(2, TOO_FEW_ARG, 26), 0);
	else if (ac > 6)
		return (write(2, TOO_MANY_ARG, 27), 0);
	i = 0;
	while (av[++i])
	{
		if (!ft_isnum(av[i]) || ft_atol(av[i]) < 0 || ft_atol(av[i]) > INT_MAX)
			return (write(2, NOT_AN_UINT, 46), 0);
	}
	*data = (t_specs){0, ft_atol(av[1]), ft_atol(av[2]), ft_atol(av[3]),
		ft_atol(av[4]), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	if (ac == 6)
		data->nb_must_eat = ft_atol(av[5]);
	else
		data->nb_must_eat = -1;
	return (1);
}
