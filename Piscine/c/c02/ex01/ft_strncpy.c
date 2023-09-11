/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 09:43:20 by mbecker           #+#    #+#             */
/*   Updated: 2023/07/02 09:43:31 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/*int main()
{
	unsigned int num = 40;
	
	char source[] = "I will pass the test";

	unsigned int destnum = 30;
	char destination[destnum];

	ft_strncpy(destination, source, num);

	printf("%s", destination);
	while (destnum <= num)
	{
		if (destination[destnum] == '\0')
			printf("\\0");
		destnum++;
	}
	return (0);
}
*/