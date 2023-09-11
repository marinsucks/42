/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:00:01 by mbecker           #+#    #+#             */
/*   Updated: 2023/07/03 23:00:03 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[0] == '\0')
	{
		return (str);
	}
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
			{
				return (&str[i]);
			}
			j++;
		}
		i++;
	}
	return (0);
}

/*int main()
{
	char str[] = "hello comment ca va";
	char to_find[] = "comment";
	char to_not_find[] = "coxment";
	char to_not_find2[] = "";

	printf("%s", ft_strstr(str, to_find));
	printf("\n");
	printf("%s", strstr(str, to_find));
	printf("\n");

	printf("%s", ft_strstr(str, to_not_find));
	printf("\n");
	printf("%s", strstr(str, to_not_find));
	printf("\n");

	printf("%s", ft_strstr(str, to_not_find2));
	printf("\n");
	printf("%s", strstr(str, to_not_find2));
	printf("\n");
}*/
