/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:59:38 by mbecker           #+#    #+#             */
/*   Updated: 2023/12/14 16:48:38 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	nonewline(char *temp)
{
	int i;

	i = 0;
	while (temp[i])
	{
		if (temp[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}
