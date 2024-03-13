/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:47:48 by mbecker           #+#    #+#             */
/*   Updated: 2024/03/13 15:55:14 by mbecker          ###   ########.fr       */
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
		if (dup2(fd->infile, STDIN_FILENO))
			perror("Error redirecting standard input");
		if (dup2(fd->pipe[1], STDIN_FILENO) == -1)
			perror("Error redirecting standard output");
	}
	else if (i > 2 && i != max - 1)
	{
		if (dup2(fd->pipe[0], STDIN_FILENO) == -1)
			perror("Error redirecting standard input");
		if (dup2(fd->pipe[1], STDOUT_FILENO) == -1)
			perror("Error redirecting standard output");
	}
	else
	{
		if (dup2(fd->pipe[0], STDOUT_FILENO) == -1)
			perror("Error redirecting standard output");
		if (dup2(fd->outfile, STDOUT_FILENO) == -1)
			perror("Error redirecting standard output");
	}
}
void redirect_in_out(int in, int out)
{
	if (dup2(in, STDIN_FILENO) == -1)
		perror("Error redirecting standard input");
	if (dup2(out, STDOUT_FILENO) == -1)
		perror("Error redirecting standard output");
}

int	split_process(t_args args, pid_t *pid, t_pipex fd)
{
	int	i;

	i = -1;
	while (++i < args.ac - 3)
	{
		pid[i] = fork();
		if (pid[i] < 0)
			return (perror("fork failed"), 1);
		else if (!pid[i])
		{
			if (i == 0)
				redirect_in_out(fd.infile, fd.pipe[1]);
			else if (i >= 0 && i != args.ac - 4)
				redirect_in_out(fd.pipe[0], fd.pipe[1]);
			else
				redirect_in_out(fd.pipe[0], fd.outfile);
			exec_cmd(args.av[i + 2], args.envp);
			exit(1);
		}
		else
			printf("pid[%d] = %d | arg = %s", i, pid[i], args.av[i + 2]);
	}
	return (0);
}
