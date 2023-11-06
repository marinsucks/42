/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:35:46 by mbecker           #+#    #+#             */
/*   Updated: 2023/10/30 16:35:51 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (src < dst && src + len > dst)
	{
		d += len - 1;
		s += len - 1;
		while (len > 0)
		{
			*d = *s;
			d--;
			s--;
			len--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}


#include <stdio.h>
#include <string.h>

int main() {
    char str1[20] = "Hello, World!";
    char str2[20] = "1234567890";
    char str3[20] = "1234567890";

    // Cas où les chaînes mémoire se chevauchent et src est avant dst
    printf("Cas 1 (src < dst && src + len > dst):\n");
    printf("Avant memmove:\n");
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    ft_memmove(str1 + 3, str1, 12);
    printf("Après memmove:\n");
	printf("str1: %s (Attendu : Hello, World!Hello, World!)\n", str1);
    printf("str2: %s (Attendu : Hello, World!)\n\n", str2);

    // Cas où les chaînes mémoire se chevauchent mais src est après dst
    printf("Cas 2 (src > dst):\n");
    printf("Avant memmove:\n");
    printf("str2: %s\n", str2);
    printf("str3: %s\n", str3);
    ft_memmove(str2, str2 + 3, 12);
    printf("Après memmove:\n");
    printf("str2: %s (Attendu : 4567890123456789)\n", str2);
    printf("str3: %s (Attendu : 1234567890)\n\n", str3);

    // Cas où les chaînes mémoire ne se chevauchent pas
    printf("Cas 3 (Aucun chevauchement):\n");
    char str4[20] = "Hello, World!";
    char str5[20] = "1234567890";
    printf("Avant memmove:\n");
    printf("str4: %s\n", str4);
    printf("str5: %s\n", str5);
    ft_memmove(str4, str5, 12);
    printf("Après memmove:\n");
    printf("str4: %s (Attendu : 12345678901234567890)\n", str4);
    printf("str5: %s (Attendu : 1234567890)\n", str5);

    return 0;
}


//INCOMPLETE FUNCTION - see example below

//#include <stdio.h>
//#include <string.h>

//int	main(void)
//{
//	char buffer[] = "0123456789";
//	// char mem[30];
//	ft_memmove(buffer + 4, buffer, strlen(buffer) + 1);
//	// ft_memcpy(mem, buffer, 20);
//	printf("%s\n", buffer);
//	return (0);
//} 
