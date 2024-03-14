/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:20:40 by mbecker           #+#    #+#             */
/*   Updated: 2024/03/14 16:49:20 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	parsing(int argc, char const **argv, int *infile, int *outfile)
{
	if (!ft_strncmp(argv[1], "here_doc", 8))
	{
		if (argc < 6)
			return (write(2, "Error: too few arguments\n", 25), 0);
		*outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_APPEND, 0644);
	}
	else 
	{
		if (argc < 5)
			return (write(2, "Error: too few arguments\n", 25), 0);
		*infile = open(argv[1], O_RDONLY);
		if (*infile < 0)
			return (perror(argv[1]), 0);
		*outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	}
	if (*outfile < 0)
		return (perror(argv[argc - 1]), close(*infile), 0);
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
void	child_process(const char *cmd, char **envp)
{
	pid_t	pid;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		exit_error("pipe");
	pid = fork();
	if (pid == -1)
		exit_error("fork");
	else if (pid == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		exec_cmd(cmd, envp);
		exit(1);
	}
	else
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		//waitpid(pid, NULL, 0);
	}
}

int	main(int argc, char const **argv, char **envp)
{
	int 	infile;
	int 	outfile;
	int		i;

	if (argc == 1 || !parsing(argc, argv, &infile, &outfile))
		return (1);
	if (!ft_strncmp(argv[1], "here_doc", 8))
	{
		i = 3;
		here_doc(argv[2]);
	}
	else
	{
		i = 2;
		if (dup2(infile, STDIN_FILENO) == -1)
			return (perror("Error redirecting standard input"), 1);
	}
	while (i < argc - 2)
		child_process(argv[i++], envp);
	if (dup2(outfile, STDOUT_FILENO) == -1)
		return (perror("Error redirecting standard output"), 1);
	if(exec_cmd(argv[argc -2], envp))
		return (127);
	return (0);
}
