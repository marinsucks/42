/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:05:35 by mbecker           #+#    #+#             */
/*   Updated: 2023/07/02 16:05:38 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 'A' || str[i] > 'Z')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*int main()
{
	printf("%i",  ft_str_is_uppercase(""));
	printf("%i",  ft_str_is_uppercase(" 77"));
	printf("%i",  ft_str_is_uppercase("alphab"));
	printf("%i",  ft_str_is_uppercase("ALPHAB"));
	printf("%i",  ft_str_is_uppercase("Alphab"));
	printf("%i",  ft_str_is_uppercase("pas alphab"));
	printf("%i",  ft_str_is_uppercase("777"));
	printf("%i",  ft_str_is_uppercase("pasalphab777"));
	
	return 0;
}*/