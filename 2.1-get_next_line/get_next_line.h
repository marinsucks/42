/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:59:21 by mbecker           #+#    #+#             */
/*   Updated: 2023/12/17 22:47:34 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

char	*maketemp(char *stash, char *res);
char	*makeres(char *temp);
void	makestash(char *temp, char *stash);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);


size_t	ft_strlen(char *s);
int		hasnewline(char *temp);

#endif
