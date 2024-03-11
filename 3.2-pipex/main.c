/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:20:40 by mbecker           #+#    #+#             */
/*   Updated: 2024/03/11 18:18:02 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	parsing(int argc, char const **argv, int *file1, int *file2)
{
	if (argc < 5)
		return (write(2, "Error: too few arguments\n", 25), 0);
	*file1 = open(argv[1], O_RDWR | O_TRUNC, 0644);
	if (*file1 < 0)
		return (perror(argv[1]), 0);
	if (!ft_strncmp(argv[1], "here_doc", 8))
		*file2 = open(argv[ft_tablen(argv) - 1], O_CREAT | O_RDWR | O_APPEND);
	else
		*file2 = open(argv[ft_tablen(argv) - 1], O_CREAT | O_RDWR | O_TRUNC);
	return (1);
}

int	main(int argc, char const **argv, char **envp)
{
	pid_t	pid;//[argc - 1];
	int		file1;
	int		file2;
	int		i;

	
	if (!parsing(argc, argv, &file1, &file2))
		return (1);
	i = 1;
	while (i < argc - 3)
	{
		pid = fork();
		if (pid < 0)
			return (perror("fork failed"), 1);
		else if (!pid)
		{
			exec_cmd(argv[i++], envp);
		}
	}
	
	waitpid(pid, NULL, 0);
	close(3); //DEBUG
	close(4); //DEBUG
	return (0);
}
