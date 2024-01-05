/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:38:33 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/05 10:57:18 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_MAX
#  define FD_MAX 512
# endif

typedef struct s_fd_data
{
	int				fd;
	char			stash[BUFFER_SIZE + 1];
}					t_fd_data;

char	*maketemp(char *stash, char *res);
char	*tempsplit(char *temp, char *stash);
char	*get_next_line(int fd);

size_t	ft_strlen(char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
int		hasnewline(char *temp);
char	*ft_strncpy(char *dst, const char *src, size_t len);

#endif
