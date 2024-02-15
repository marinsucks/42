/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:42:24 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/15 17:22:27 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# ifndef FD_MAX
#  define FD_MAX 512
# endif

# define TRUE 1
# define FALSE 0

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# include "free/free.h"
#include "get/get.h"
#include "lst/lst.h"
#include "mem/mem.h"
#include "print/print.h"
#include "str/str.h"

//typedef struct s_list
//{
//	int				*content;
//	struct s_list	*target;
//	struct s_list	*next;
//}					t_list;

int			error(int fd);

void		freetab(char **tab, int heap);

void		ft_dfs(char **map, int i, int j, char *notwalls);

#endif
