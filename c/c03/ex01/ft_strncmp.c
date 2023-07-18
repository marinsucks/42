/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:28:19 by mbecker           #+#    #+#             */
/*   Updated: 2023/07/03 11:28:21 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned int	diff;
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	i = 0;
	while ((us1[i] || us2[i]) && i < n)
	{
		diff = us1[i] - us2[i];
		if (us1[i] != us2[i])
		{
			return (diff);
		}
		i++;
	}
	return (0);
}

/*#include <stdio.h>

int	main(void)
{
	char a[] = "check ok";
	char b[] = "check okA";
	char c[] = "";
	unsigned int x = 9;

	printf("%i\n", ft_strncmp(a, a, x));
	printf("%i\n", ft_strncmp(a, b, x));
	printf("%i\n", ft_strncmp(b, a, x));
	printf("%i\n", ft_strncmp(c, c, x));
	return (0);
}*/
