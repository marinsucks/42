/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:11:03 by mbecker           #+#    #+#             */
/*   Updated: 2023/07/03 11:11:05 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	int				diff;
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	i = 0;
	while (us1[i] || us2[i])
	{
		diff = us1[i] - us2[i];
		if (us1[i] != us2[i])
			return (diff);
		i++;
	}
	return (0);
}

/*ALTERNATIVE

int	ft_strcmp(char *s1, char *s2)
{
	int				i;

	i = 0;
	while (s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}*/


/*#include <stdio.h>

int	main(void)
{
	char a[] = "check okb";
	char b[] = "check oka";
	char c[] = "";


	printf("%i\n", ft_strcmp(a, a));
	printf("%i\n", ft_strcmp(a, b));
	printf("%i\n", ft_strcmp(b, a));
	printf("%i\n", ft_strcmp(c, c));
	return (0);
}*/