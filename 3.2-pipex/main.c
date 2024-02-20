/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:20:40 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/20 19:48:22 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **envp)
{
	int		i;
	char	**path;

	i = 0;
	if (!envp)
		return (NULL);
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (NULL);
	path = ft_split(envp[i] + 5, ':');
	if (!path)
		return (NULL);
	return (path);
}

char	**get_cmd_args(char *exe)
{
	char	**args;

	while (!ft_is(*exe, SPACES)) //PB HERE
		exe++;
	ft_printf("exe: %s\n", exe);
	args = ft_split_charset(exe, SPACES);
	if (!args)
		return (NULL);
	if (!args[0])
		return (free(args), NULL);
	
	return (args);
}

int	exec_cmd(char *exe, char **envp)
{
	char	**path;
	char	**args;
	char	*cmd;
	int		i;

	if (!exe || !envp)
		return (1);
	args = get_cmd_args(exe);
	cmd = ft_strjoin("/", *args, FALSE, FALSE);
	if (ft_strchr(exe, '/'))
		execve(exe, args, envp);
	path = get_path(envp);
	if (!path)
		return (freetab(path, TRUE), 1);
	i = -1;
	while (path[++i])
	{
		cmd = ft_strjoin(path[i], cmd, FALSE, TRUE);
		execve(cmd, args, envp);
		free(cmd);
 	}
	return (perror(exe + 1), free(exe), freetab(path, TRUE), 1);
}

int	main(int argc, char **argv, char **envp)
{
	//pid_t	pid_a;
	//pid_t	pid_b;
	
	//if (argc < 2)
	//	return (1);
	//pid_a = fork();
	//if (pid_a < 0)
	//	return (perror("fork failed"), 1);
	//else if (!pid_a)
	//	exec_cmd(argv[1], NULL, envp);
	//else
	//{
	//	pid_b = fork();
	//	if (pid_b < 0)
	//		return (perror("fork failed"), 1);
	//	else if (!pid_b)
	//		exec_cmd(argv[2], NULL, envp);
	//	else
	//	{
	//		waitpid(pid_a, NULL, 0);
	//		waitpid(pid_b, NULL, 0);
	//	}
	//}
	//return (0);
	char **args = get_cmd_args(argv[1]);

	ft_printf("%s\n", argv[1]);
	printtab(args, 1);
	freetab(args, TRUE);

	if (argc || argv || envp)
		return (0);
}
