/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:48:19 by mbecker           #+#    #+#             */
/*   Updated: 2024/03/25 12:01:54 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTHER_H
# define OTHER_H

# include "../libft.h"

void		exit_error(char *msg);
void		cmd_error(char *cmd);
void		msg(char *msg, ...);
//error.c

size_t		ft_strlen(const char *s);
size_t		ft_tablen(const char **tab);
short int	ft_numlen(long long num);
short int	ft_numlen_base(unsigned long num, unsigned int baselen);
//ft_len.c

void		ft_revert_tab(char *s);
void		ft_revert_inttab(char *s);
//ft_revert.c

void		ft_dfs(char **map, int i, int j, char *notwalls);

#endif
