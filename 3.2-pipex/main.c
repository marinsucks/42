/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:20:40 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/28 16:29:03 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char const **argv, char **envp)
{
	pid_t	pid_a;
	pid_t	pid_b;

	give_birth((char **)argv);
	exit(0);

	int fd1 = open("child_a.txt", O_CREAT | O_RDWR | O_TRUNC, 0644); //DEBUG
	int fd2 = open("child_b.txt", O_CREAT | O_RDWR | O_TRUNC, 0644); //DEBUG

	if (argc < 2)
		return (0);
	pid_a = fork();
	if (pid_a < 0)
		return (perror("fork a failed"), 1);
	else if (!pid_a)
	{
		ft_printf_fd(fd1, "CHILD 1 ok\n"); //DEBUG
		exec_cmd(argv[1], envp);
	}

	pid_b = fork();
	if (pid_b < 0)
		return (perror("fork b failed"), 1);
	else if (!pid_b)
	{
		ft_printf_fd(fd2, "CHILD 2 ok\n"); //DEBUG
		exec_cmd(argv[2], envp);
	}	
	waitpid(pid_a, NULL, 0);
	waitpid(pid_b, NULL, 0);
	close(3); //DEBUG
	close(4); //DEBUG
	ft_printf("Parent process ending\n"); //DEBUG
	return (0);
}
