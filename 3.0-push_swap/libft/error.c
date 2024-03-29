/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:27:55 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/18 17:30:51 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//writes "Error\n" to fd and returns 1
int	error(int fd)
{
	write(fd, "Error\n", 6);
	return (1);
}
