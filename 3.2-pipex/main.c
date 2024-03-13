/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:20:40 by mbecker           #+#    #+#             */
/*   Updated: 2024/03/13 15:48:57 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	parsing(int argc, char const **argv, t_pipex *fd)
{
	if (argc < 5)
		return (write(2, "Error: too few arguments\n", 25), 0);
	fd->infile = open(argv[1], O_RDONLY);
	if (fd->infile < 0)
		return (perror(argv[1]), 0);
	if (!ft_strncmp(argv[1], "here_doc", 8))
		fd->outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_APPEND, 0644);
	else
		fd->outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd->outfile < 0)
		return (perror(argv[argc - 1]), close(fd->outfile), 0);
	return (1);
}

int	main(int argc, char const **argv, char **envp)
{
	t_args	args;
	t_pipex	fd;
	pid_t	*pid;
	int		i;
	
	fd = (t_pipex){0, 0, {0, 0}};
	args = (t_args){argc, argv, envp};
	if (!parsing(argc, argv, &fd))
		return (1);
	pid = malloc((argc - 3) * sizeof(pid_t));
	if (dup2(fd.infile, STDIN_FILENO) == -1)
		return (perror("Error redirecting standard input"), 1);
	if (pipe(fd.pipe) == -1)
		return (perror("pipe failed"), 1);

	split_process(args, pid, fd);

	i = 0;
	while (i < argc - 3)
		waitpid(pid[i++], NULL, 0);
	free(pid);
	
	
	ft_printf("\nEND\n"); //DEBUG
	return (0);
}
