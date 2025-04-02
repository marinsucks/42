/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:14:47 by mbecker           #+#    #+#             */
/*   Updated: 2023/07/02 16:14:52 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32
			|| str[i] > '~')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*int main()
{
	printf("%i",  ft_str_is_printable(""));
	printf("%i",  ft_str_is_printable(" 77"));
	printf("%i",  ft_str_is_printable("alphab"));
	printf("%i",  ft_str_is_printable("ALPHAB"));
	printf("%i",  ft_str_is_printable("Alphab"));
	printf("%i",  ft_str_is_printable("pas alphab"));
	printf("%i",  ft_str_is_printable("777"));
	printf("%i",  ft_str_is_printable("pasalphab777"));
	printf("%i",  ft_str_is_printable("\n"));

	return 0;
}*/
