/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 11:47:06 by mbecker           #+#    #+#             */
/*   Updated: 2023/07/02 11:47:09 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 'A'
			|| (str[i] > 'Z' && str[i] < 'a')
			|| str[i] > 'z')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*int main()
{
	printf("%i", ft_str_is_alpha(""));
	printf("%i", ft_str_is_alpha("777"));
	printf("%i", ft_str_is_alpha("alphab"));
	printf("%i", ft_str_is_alpha("ALPHAB"));
	printf("%i", ft_str_is_alpha("pas alphab"));
	printf("%i", ft_str_is_alpha("777"));
	printf("%i", ft_str_is_alpha("pasalphab777"));

	return 0;
}*/
