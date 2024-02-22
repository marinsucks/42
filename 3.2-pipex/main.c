/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:20:40 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/22 15:34:45 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char const **argv, char **envp)
{
	pid_t	pid_a;
	
	if (argc < 2)
		return (1);
	pid_a = fork();
	if (pid_a < 0)
		return (perror("fork failed"), 1);
	else if (pid_a == 0)
	{
		ft_printf("CHILD A\n"); //DEBUG
		exec_cmd(argv[1], envp);
	}
	else
	{
		waitpid(pid_a, NULL, 0);
		exec_cmd(argv[2], envp);
	}
	return (0);
}
