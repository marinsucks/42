/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:20:40 by mbecker           #+#    #+#             */
/*   Updated: 2024/03/14 16:49:38 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

char	**get_cmd_paths(char **envp, char *cmd)//, int fd)//DEBUG
{
	int		i;
	char	**path;

	i = 0;
	if (!envp || !cmd || !*cmd)
		return (NULL);
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (free(cmd), NULL);
	path = ft_split(envp[i] + 5, ':');
	if (!path)
		return (free(cmd), NULL);
	i = -1;
	while (path[++i])
	{
		path[i] = ft_strjoin(path[i], "/", TRUE, FALSE);
		path[i] = ft_strjoin(path[i], cmd, TRUE, FALSE);
		if (!path[i])
			return (freetab(path, TRUE), free(cmd), NULL);
	}
	return (path);
}

int	exec_cmd(const char *cmd, char **envp)//, int fd)//DEBUG
{
	char	**path;
	char	**args;
	int		i;

	if (!cmd || !*cmd || !envp)
		return (cmd_error(""), 1);
	args = ft_split_charset(cmd, SPACES);
	if (ft_strchr(cmd, '/'))
	{
		execve(args[0], args, envp);
		return (cmd_error(args[0]), freetab(args, TRUE), 1);
	}
	path = get_cmd_paths(envp, args[0]);
	if (!path)
		return (write(2, MALLOC_ERR, 21), freetab(path, TRUE), 1);
	i = 0;
	while (path[i])
		execve(path[i++], args, envp);
	return (cmd_error(args[0]), freetab(path, TRUE), freetab(args, TRUE), 1);
}
