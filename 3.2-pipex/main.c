/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:20:40 by mbecker           #+#    #+#             */
/*   Updated: 2024/03/20 14:44:01 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	parsing(int argc, char const **argv, t_pipex *data, int *i)
{
	if (argc < 5)
		return (write(2, "Error: too few arguments\n", 25), 0);
	data->outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data->outfile < 0)
		return (perror(argv[argc - 1]), 0);
	data->infile = open(argv[1], O_RDONLY);
	if (data->infile < 0)
	{
		*i = 3;
		data->infile = open("/dev/null", O_RDONLY);
		return (perror(argv[1]), -1);
	}
	*i = 2;
	return (1);
}

void	handle_in_out(const char *cmd, t_pipex *data, char islast)
{
	if (!islast)
	{
		close(data->pipefd[0]);
		dup2(data->pipefd[1], STDOUT_FILENO);
		close(data->pipefd[1]);
		exec_cmd(cmd, data->envp);
		exit(1);
	}
	else
	{
		dup2(data->outfile, STDOUT_FILENO);
		close(data->outfile);
		exec_cmd(cmd, data->envp);
		exit(127);
	}
}

void	child_process(const char *cmd, t_pipex *data, char islast)
{
	pid_t	pid;

	if (!islast && pipe(data->pipefd) == -1)
		exit_error("pipe");
	pid = fork();
	if (pid == -1)
		exit_error("fork");
	else if (pid == 0)
		handle_in_out(cmd, data, islast);
	else
	{
		if (!islast)
		{
			close(data->pipefd[1]);
			dup2(data->pipefd[0], STDIN_FILENO);
			close(data->pipefd[0]);
		}
		else
			close(data->outfile);
	}
}

int	main(int argc, char const **argv, char **envp)
{
	t_pipex	data;
	int 	parsing_result;
	int		i;

	parsing_result = parsing(argc, argv, &data, &i);
	if (!parsing_result)
		return (1);
	data.envp = envp;
	if (dup2(data.infile, STDIN_FILENO) >= 0)
		close(data.infile);
	while (i < argc - 2)
		child_process(argv[i++], &data, FALSE);
	child_process(argv[i], &data, TRUE);
	wait(NULL);
	if (parsing_result == -1)
		close(data.infile);
	return (0);
}
