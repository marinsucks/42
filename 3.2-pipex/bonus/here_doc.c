/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:38:21 by mbecker           #+#    #+#             */
/*   Updated: 2024/03/14 16:49:43 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	redirect_input(const char *limiter, int fd)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
			exit(EXIT_SUCCESS);
		ft_putstr_fd(line, fd);
		free(line);
		get_next_line(STDIN_FILENO);
	}
}

void	here_doc(const char *limiter)
{
	pid_t	reader;
	int		fd[2];

	if (pipe(fd) == -1)
		exit_error("pipe");
	reader = fork();
	if (reader == 0)
	{
		close(fd[0]);
		redirect_input(limiter, fd[1]);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}
