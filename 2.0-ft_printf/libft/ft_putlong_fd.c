/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:57:17 by mbecker           #+#    #+#             */
/*   Updated: 2023/11/23 11:36:23 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
