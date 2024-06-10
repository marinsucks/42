/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:09:57 by mbecker           #+#    #+#             */
/*   Updated: 2024/06/10 18:34:02 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * Prints an `error_msg` to the standard error output and returns 1.
 */
int	error(char *error_msg)
{
	write(STDERR_FILENO, error_msg, strlen(error_msg));
	return (1);
}
