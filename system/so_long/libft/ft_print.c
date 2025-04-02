/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:48:37 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/08 18:54:35 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Prints the contents of a string array, with optional color formatting.
 *
 * @param tab   The string array to be printed.
 *
 * @param 0 none
 * @param 1 red
 * @param 2 green
 * @param 3 yellow
 * @param 4 blue
 * @param 5 magenta
 * @param 6 cyan
 */
void	print_tab(char **tab, int color)
{
	int	i;

	if (color == 1)
		ft_printf("\n\033[0;31m");
	else if (color == 2)
		ft_printf("\n\033[0;32m");
	else if (color == 3)
		ft_printf("\n\033[0;33m");
	else if (color == 4)
		ft_printf("\n\033[0;34m");
	else if (color == 5)
		ft_printf("\n\033[0;35m");
	else if (color == 6)
		ft_printf("\n\033[0;36m");
	i = 0;
	while (tab[i])
		ft_printf("%s", tab[i++]);
	ft_printf("\033[0m$\n");
}
