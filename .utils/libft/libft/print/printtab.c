/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printtab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:48:37 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/20 19:45:39 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

/**
 * Prints the contents of a string array, with optional color formatting.
 * @param 0 white
 * @param 1 red
 * @param 2 green
 * @param 3 yellow
 * @param 4 blue
 * @param 5 magenta
 * @param 6 cyan
 * @param else grey
 */
void	printtab(char **tab, int color)
{
	int		i;
	char	*cstr;

	if (color == 0)
		cstr = "\033[0m";
	else if (color == 1)
		cstr = "\033[0;31m";
	else if (color == 2)
		cstr = "\033[0;32m";
	else if (color == 3)
		cstr = "\033[0;33m";
	else if (color == 4)
		cstr = "\033[0;34m";
	else if (color == 5)
		cstr = "\033[0;35m";
	else if (color == 6)
		cstr = "\033[0;36m";
	else
		cstr = "\033[0;30m";
	if (!tab)
		return ((void)ft_printf("%sempty tab.\033[0m\n", cstr));
	i = -1;
	while (tab[++i])
		ft_printf("\033[0;30m[%d]\t%s%s\033[0;30m$\n", i, cstr, tab[i]);
	write(1, "\033[0m", 4);
}
