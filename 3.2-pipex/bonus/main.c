/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:20:40 by mbecker           #+#    #+#             */
/*   Updated: 2024/03/19 16:28:33 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	parsing(int argc, char const **argv, int *infile, int *outfile)
{
	if (argc < 5)
		return (write(2, "Error: too few arguments\n", 25), 0);
	*outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (*outfile < 0)
		return (perror(argv[argc - 1]), 0);
	if (ft_strncmp(argv[1], "here_doc", 9))
	{
		*infile = open(argv[1], O_RDONLY);
		if (*infile < 0)
			return (perror(argv[1]), -1);
	}
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
	int		i;

	if (!parsing(argc, argv, &data.infile, &data.outfile))
		return (1);
	data.envp = envp;
	if (!ft_strncmp(argv[1], "here_doc", 8))
	{
		i = 3;
		here_doc(argv[2]);
	}
	else
	{
		i = 2;
		if (dup2(data.infile, STDIN_FILENO) >= 0)
			close(data.infile);
	}
	while (i < argc - 2)
		child_process(argv[i++], &data, FALSE);
	child_process(argv[i], &data, TRUE);
	wait(NULL);
	return (0);
}
