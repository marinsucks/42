/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:47:48 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/29 18:59:34 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_one(char *str, int fd[2])
{
	ft_printf("str = %s\n", str); //DEBUG
	int fd1 = open("child_a.txt", O_CREAT | O_RDWR | O_TRUNC, 0644); //DEBUG
	ft_printf_fd(fd1, "Child 1 writing in its file child_a.txt\n"); //DEBUG	
	write(fd[1], "Hi from child a !!", 17);
	exit(0);
}

void	child_two(int fd[2])
{
	close(fd[1]);
	int fd2 = open("child_b.txt", O_CREAT | O_RDWR | O_TRUNC, 0644); //DEBUG
	ft_printf_fd(fd2, "Child 2 writing in its file child_a.txt\n"); //DEBUG	
	
	char message[BUFFER_SIZE + 1];
	read(fd[0], message, BUFFER_SIZE);
	ft_printf("Child 2 reading from pipe: %s\n", message); //DEBUG

	exit(0);
}

void	give_birth(char **argv)
{
	int 	fd[2];
	pid_t	pid1;
	pid_t	pid2;

    if (pipe(fd) == -1) {
        fprintf(stderr, "Pipe Failed");
        return ;
    }

	ft_printf("fd[0] = %d\n", fd[0]);
	ft_printf("fd[1] = %d\n", fd[1]);

	pid1 = fork();
	if (pid1 < 0)
		return ; //fork failed
	else if (pid1 == 0)
		child_one(argv[1], fd);
	
	waitpid(pid1, NULL, 0);
	pid2 = fork();
	if (pid2 < 0)//fork failed
		return ;
	else if (pid2 == 0)
		child_two(fd);

	waitpid(pid2, NULL, 0);
}
