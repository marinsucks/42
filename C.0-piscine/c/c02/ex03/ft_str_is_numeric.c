/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 13:58:53 by mbecker           #+#    #+#             */
/*   Updated: 2023/07/02 13:59:29 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '1'
			|| str[i] > '9')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*int main()
{
	printf("%i", ft_str_is_numeric(""));
	printf("%i", ft_str_is_numeric(" 77"));
	printf("%i", ft_str_is_numeric("alphab"));
	printf("%i", ft_str_is_numeric("ALPHAB"));
	printf("%i", ft_str_is_numeric("pas alphab"));
	printf("%i", ft_str_is_numeric("777"));
	printf("%i", ft_str_is_numeric("pasalphab777"));

	return 0;
}*/
