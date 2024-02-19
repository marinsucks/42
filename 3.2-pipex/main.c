/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:20:40 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/19 18:37:10 by mbecker          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	pid_t	pid1;
	pid_t	pid2;

	pid1 = fork();
	if (pid1 < 0 || argc < 1)
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
	return (0);
}
