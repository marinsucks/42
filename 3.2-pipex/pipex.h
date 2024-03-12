/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:11:32 by mbecker           #+#    #+#             */
/*   Updated: 2024/03/12 18:19:57 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		pipe[2];
}			t_pipex;

typedef struct s_args
{
	int			ac;
	char const	**av;
	char		**envp;
}				t_args;

int		exec_cmd(const char *exe, char **envp);//, int fd); //DEBUG
//commands.c

int	split_process(t_args args, pid_t *pid, t_pipex *fd);
//processes.c

#endif