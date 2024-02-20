/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:47:48 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/20 12:48:18 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void	child_one(char *str)
{
	printf("launching %s\n", str);
}

void	child_two(char *str)
{
	printf("launching %s\n", str);
}

void	give_birth(char **argv)
{
	pid_t	pid1;
	pid_t	pid2;

	pid1 = fork();
	if (pid1 < 0)
		return (perror("Fork failure"), 1);
	else if (pid1 == 0)
		child_one(argv[1]);
	else
	{
		pid2 = fork();
		if (pid2 < 0)
			return (perror("Fork failure"), 1);
		else if (pid2 == 0)
			child_two(argv[2]);
		else
		{
			waitpid(pid1, NULL, 0);
			waitpid(pid2, NULL, 0);
		}
	}
}
