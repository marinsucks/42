/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:53:50 by mbecker           #+#    #+#             */
/*   Updated: 2024/03/25 12:14:41 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "other.h"

void	exit_error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

/**
 * Displays an error message indicating that a command was not found.
 *
 * @param cmd The command that was not found.
 */
void	cmd_error(char *cmd)
{
	write(2, "command not found: ", 19);
	write(2, cmd, ft_strlen(cmd));
	write(2, "\n", 1);
}

/**
 * Prints a message to the standard output or a specified file descriptor.
 *
 * @param msg The message to be printed.
 * @param ... Optional arguments.
 */
void	msg(char *msg, ...)
{
	va_list	args;
	int		fd;
	char	*str;

	va_start(args, msg);
	fd = va_arg(args, int);
	if (!fd)
		fd = 1;
	write(fd, msg, ft_strlen(msg));
	str = va_arg(args, char *);
	if (str)
		write(fd, str, ft_strlen(str));
	va_end(args);
}
