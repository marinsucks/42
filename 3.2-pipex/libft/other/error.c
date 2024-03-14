/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:53:50 by mbecker           #+#    #+#             */
/*   Updated: 2024/03/14 16:41:23 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "other.h"

void	exit_error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	cmd_error(char *cmd)
{
	write(2, "command not found: ", 19);
	write(2, cmd, ft_strlen(cmd));
	write(2, "\n", 1);
}
