/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:47:48 by mbecker           #+#    #+#             */
/*   Updated: 2024/03/11 15:05:10 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*read_all(int fd, int buffer_size)
{
	char	temp[buffer_size + 1];
	char	*res;
	int 	readval;

	readval = read(fd, temp, buffer_size);
	if (readval <= 0)
		return (NULL);
	temp[readval] = '\0';
	res = ft_strdup(temp);
	while (readval > 0)
	{
		readval = read(fd, temp, buffer_size);
		temp[readval] = '\0';
		res = ft_strjoin(res, temp, TRUE, FALSE);
	}
	return (res);
}

void	child_one(int fd[2])
{	
	char *message = "Hi from child a !!";
	write(fd[1], message, 17);
	close(fd[1]);

	exit(0);
}

void	child_two(int fd[2])
{
	close(fd[1]);
	char *message = get_next_line(fd[0]);
	ft_printf("Child 2 reading from pipe: %s\n", message); //DEBUG

	exit(0);
}

void	give_birth(void)
{
	int 	fd[2];
	pid_t	pid1;
	pid_t	pid2;

    if (pipe(fd) == -1) 
	{
        perror("Pipe Failed");
        return ;
    }

	pid1 = fork();
	if (pid1 < 0)
		return ; //fork failed
	else if (pid1 == 0)
		child_one(fd);
	
	pid2 = fork();
	if (pid2 < 0)//fork failed
		return ;
	else if (pid2 == 0)
		child_two(fd);
}
