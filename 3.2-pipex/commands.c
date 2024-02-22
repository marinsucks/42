/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:20:40 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/22 15:38:30 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_cmd(char **envp, char *cmd, char **args)
{
	int		i;
	char	**path;

	i = 0;
	if (!envp)
		return (NULL);
	cmd = ft_strjoin("/", cmd, FALSE, TRUE);
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (free(cmd), NULL);
	path = ft_split(envp[i] + 5, ':');
	if (!path)
		return (free(cmd), NULL);
	i = -1;
	printtab(path, 2);
	while (path[++i])
	{
		path[i] = ft_strjoin(path[i], cmd, TRUE, FALSE);
		ft_printf("path[%d] = %s\n", i, path[i]);
		execve(path[i], args, envp);
		if (!path[i])
			return (freetab(path, TRUE), free(cmd), NULL);
	}
	free(cmd);
	return (path);
}

char	**get_cmd_args(const char *exe, char **cmd)
{
	char	**args;

	*cmd = (char *)exe;
	while (*exe && ft_is(*exe, SPACES))
		exe++;
	while (*exe && (!ft_is(*exe, SPACES)))
	{
		if ((*exe == '\\' && ft_is(*(exe + 1), " \t\n\v\f\r\\\"'")))
			exe++;
		exe++;
	}
	*cmd = ft_strndup(*cmd, exe - *cmd);
	if (!*exe)
		return (NULL);
	args = ft_split_charset(exe, SPACES);
	if (!args)
		return (NULL);
	if (!args[0])
		return (free(args), NULL);
	return (args);
}

int	exec_cmd(const char *exe, char **envp)
{
	char	**path;
	char	**args;
	char	*cmd;
	int		i;

	ft_printf("exe = %p\n", exe); //DEBUG
	if (!exe || ft_isprint(*exe) || !envp) //CHECK ISPRINT
		return (1);
	args = get_cmd_args(exe, &cmd);
	if (ft_strchr(exe, '/'))
	{
		free(cmd);
		execve(exe, args, envp);
	}
	path = get_cmd(envp, cmd, args);
	if (!path)
		return (freetab(path, TRUE), 1);
	i = -1;
	while (path[++i])
		execve(path[i], args, envp);
	return (perror(cmd), free(cmd), freetab(path, TRUE),
		freetab(args, TRUE),  1);
}

