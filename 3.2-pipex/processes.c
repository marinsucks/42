/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:47:48 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/28 16:30:01 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_one(char *str)
{
	printf("launching %s\n", str);
	int fd1 = open("child_a.txt", O_CREAT | O_RDWR | O_TRUNC, 0644); //DEBUG
	write(fd1, "hi from child 1\n", 16); //DEBUG
	
}

void	child_two(char *str)
{
	printf("launching %s\n", str);
	int fd2 = open("child_b.txt", O_CREAT | O_RDWR | O_TRUNC, 0644); //DEBUG
	write(fd2, "hi from child 2\n", 16); //DEBUG
}

void	give_birth(char **argv)
{
	pid_t	pid1;
	pid_t	pid2;

	pid1 = fork();
	if (pid1 < 0)
		return ;
	else if (pid1 == 0)
		child_one(argv[1]);
	
	pid2 = fork();
	if (pid2 < 0)
		return ;
	else if (pid2 == 0)
		child_two(argv[2]);
	else
	{
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
}
