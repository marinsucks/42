/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:14:21 by mbecker           #+#    #+#             */
/*   Updated: 2023/11/21 17:19:36 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

int	printf_utils(char a, char b)
{
	
	// fonction if c, s, p, d, i, u, x, X, % = faire qqc
	// quand rencontre \, putstr("\(++i)")
	// ATTENTION : bien gerer la valeur retour de printf.
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%' && ft_strchr("cspdiuxX", s[i + 1]))
		{
			//do conversion
			i++;
		}
		else if (s[i] == '\\')
		{
			
		}
		
		else
			write(1, &s[i], 1);
		i++;
	}

	return i;

}


int	main(void)
{
	char str[] = "Hello, World!";
	int num = 5;

	printf("%c, %s, %p, %d, %i, %u, %x, %X, %%\n", str[0], str, str, num, num, num, num, num);
	ft_printf("test %s%s wesh et %f et %dx et \nxxx%a%b%c%d%e%f%g%h%i%j%k%l%m%n%o%p%q%r%s%t%u%v%w%x%y%z%%%%x");
}