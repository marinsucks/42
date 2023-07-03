/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 20:13:14 by mbecker           #+#    #+#             */
/*   Updated: 2023/07/02 20:13:18 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0')
	{
		if (i < size - 1)
			dest[i] = src[i];
		i++;
	}
	if (i < size)
		dest[i] = '\0';
	else if (size > 0)
	{
		dest[size - 1] = '\0';
	}
	return (i);
}

/*int main() {
    char src[] = "Hello, World!";
    char dest[20];
    unsigned int size = 10;
    
    unsigned int length = ft_strlcpy(dest, src, size);
    
    printf("Source: %s\n", src);
    printf("Destination: %s\n", dest);
    printf("Length: %u\n", length);
    
    return 0;
}*/
