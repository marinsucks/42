/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:09:57 by mbecker           #+#    #+#             */
/*   Updated: 2024/06/11 16:17:58 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * if not NULL, prints the macro `PROGRAM_NAME` followed by `: `, and 
 * `error_msg` to the standard error output. 
 * @returns `EXIT_FAILURE` (1)
 */
int	error(char *error_msg)
{
	if (PROGRAM_NAME)
	{
		write(STDERR_FILENO, PROGRAM_NAME, strlen(PROGRAM_NAME));
		write(STDERR_FILENO, ": ", 2);
	}
	write(STDERR_FILENO, error_msg, strlen(error_msg));
	return (EXIT_FAILURE);
}
