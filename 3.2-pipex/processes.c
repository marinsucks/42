/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:47:48 by mbecker           #+#    #+#             */
/*   Updated: 2024/03/12 18:25:07 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//char	*read_all(int fd, int buffer_size)
//{
//	char	temp[buffer_size + 1];
//	char	*res;
//	int 	readval;

//	readval = read(fd, temp, buffer_size);
//	if (readval <= 0)
//		return (NULL);
//	temp[readval] = '\0';
//	res = ft_strdup(temp);
//	while (readval > 0)
//	{
//		readval = read(fd, temp, buffer_size);
//		temp[readval] = '\0';
//		res = ft_strjoin(res, temp, TRUE, FALSE);
//	}
//	return (res);
//}

void	handle_io(int i, int max, t_pipex *fd)
{
	if (i == 2)
	{
		if (dup2(fd->pipe[0], STDIN_FILENO) == -1)
			perror("Error redirecting standard input");
	}
	else if (i > 2 && i != max)
	{
		if (dup2(fd->pipe[1], STDOUT_FILENO) == -1)
			perror("Error redirecting standard output");
		if (dup2(fd->pipe[0], STDIN_FILENO) == -1)
			perror("Error redirecting standard input");
	}
	else
	{
		if (dup2(fd->pipe[1], STDOUT_FILENO) == -1)
			perror("Error redirecting standard output");
		if (dup2(fd->outfile, STDOUT_FILENO) == -1)
			perror("Error redirecting standard output");
	}
}

int	split_process(t_args args, pid_t *pid, t_pipex *fd)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (++i < args.ac - 1)
	{
		pid[j] = fork();
		if (pid[j] < 0)
			return (perror("fork failed"), 1);
		else if (!pid[j])
		{
			if (i > 2)
				handle_io(i, args.ac - 2, fd);
			exec_cmd(args.av[i], args.envp);
			exit(1);
		}
		j++;
	}
	return (0);
}
