/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:20:40 by mbecker           #+#    #+#             */
/*   Updated: 2024/03/19 15:11:44 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	parsing(int argc, char const **argv, int *infile, int *outfile)
{
	if (argc < 5)
		return (write(2, "Error: too few arguments\n", 25), 0);
	*outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (*outfile < 0)
		return (perror(argv[argc - 1]), 0);
	*infile = open(argv[1], O_RDONLY);
	if (*infile < 0)
		return (perror(argv[1]), -1);
	return (1);
}

/**
 * Executes a child process and redirects its output.
 *
 * @param cmd The command to be executed.
 * @param envp The environment variables for the child process.
 *
 * This function creates a pipe and forks a child process. The child process
 * redirects its standard output to the write end of the pipe. Then, it executes
 * the specified executable using the `exec_cmd` function. The parent process
 * redirects its standard input to the read end of the pipe. It waits for the
 * child process to complete using `waitpid`.
 */
void	child_process(const char *cmd, char **envp, int outfile, char islast)
{
	pid_t	pid;
	int		pipefd[2];

	if (!islast && pipe(pipefd) == -1)
		exit_error("pipe");
	pid = fork();
	if (pid == -1)
		exit_error("fork");
	else if (pid == 0)
	{
		if (!islast)
		{
			close(pipefd[0]);
			dup2(pipefd[1], STDOUT_FILENO);
			close(pipefd[1]);
			exec_cmd(cmd, envp);
			exit(1);
		}
		else
		{
			//close(pipefd[0]);
			//close(pipefd[1]);
			dup2(outfile, STDOUT_FILENO);
			close(outfile);
			exec_cmd(cmd, envp);
			exit(127);
		}
	}
	else
	{
		if (!islast)
		{
			close(pipefd[1]);
			dup2(pipefd[0], STDIN_FILENO);
			close(pipefd[0]);
		}
		else
			close(outfile);
	}
}

int	main(int argc, char const **argv, char **envp)
{
	int	infile;
	int	outfile;
	int	i;

	if (!parsing(argc, argv, &infile, &outfile))
		return (1);
	i = 2;
	dup2(infile, STDIN_FILENO);
	close(infile);
	while (i < argc - 2)
		child_process(argv[i++], envp, outfile, FALSE);
	child_process(argv[i], envp, outfile, TRUE);
	wait(NULL);
	return (0);
}
