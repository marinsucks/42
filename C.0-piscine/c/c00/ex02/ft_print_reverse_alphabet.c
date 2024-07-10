/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:20:39 by mbecker           #+#    #+#             */
/*   Updated: 2023/06/28 15:20:42 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	int		intref;
	char	charref;

	intref = 122;
	while (intref > 96)
	{
		charref = intref;
		write(1, &charref, 1);
		intref--;
	}
}
