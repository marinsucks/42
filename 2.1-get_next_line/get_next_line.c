/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:59:13 by mbecker           #+#    #+#             */
/*   Updated: 2023/12/14 10:48:46 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			read_ret;
	char		*res;

	read_ret = read(fd, buffer, BUFFER_SIZE);
	if (read_ret == -1)
		return (NULL);
	

	return (res);
}
