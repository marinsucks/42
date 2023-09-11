/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:17:46 by mbecker           #+#    #+#             */
/*   Updated: 2023/06/28 14:37:39 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	int		intref;
	char	charref;

	intref = 97;
	while (intref < 123)
	{
		charref = intref;
		write(1, &charref, 1);
		intref++;
	}
}
