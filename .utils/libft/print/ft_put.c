/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:04:52 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/15 17:13:47 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	write(fd, s, ft_strlen(s));
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n != -2147483648)
	{
		if (n >= 0 && n <= 9)
		{
			ft_putchar_fd(n + '0', fd);
		}
		else if (n < 0)
		{
			ft_putchar_fd('-', fd);
			ft_putnbr_fd(-n, fd);
		}
		else
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
	}
	else
		write(fd, "-2147483648", 11);
}

void	ft_putlong_fd(long long n, int fd)
{
	if (n >= 0 && n <= 9)
	{
		ft_putchar_fd(n + '0', fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putlong_fd(-n, fd);
	}
	else
	{
		ft_putlong_fd(n / 10, fd);
		ft_putlong_fd(n % 10, fd);
	}
}
