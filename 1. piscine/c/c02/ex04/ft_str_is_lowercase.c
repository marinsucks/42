/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 17:35:06 by mbecker           #+#    #+#             */
/*   Updated: 2023/07/02 17:35:10 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 'a' || str[i] > 'z')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*int main()
{
	printf("%i",  ft_str_is_lowercase(""));
	printf("%i",  ft_str_is_lowercase(" 77"));
	printf("%i",  ft_str_is_lowercase("alphab"));
	printf("%i",  ft_str_is_lowercase("ALPHAB"));
	printf("%i",  ft_str_is_lowercase("Alphab"));
	printf("%i",  ft_str_is_lowercase("pas alphab"));
	printf("%i",  ft_str_is_lowercase("777"));
	printf("%i",  ft_str_is_lowercase("pasalphab777"));

	return 0;
}*/
