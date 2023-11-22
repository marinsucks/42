/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:14:21 by mbecker           #+#    #+#             */
/*   Updated: 2023/11/22 16:35:02 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

void	put_backslash(const char *s, int *count)
{
	write(1, s, 2);
	s += 2;
	*count += 1;
}

int	convert(const char *s, va_list args)
{
	int				argi;

	if (*s == '%')
		write(1, s, 1);
	else if (*s == 'd' || *s == 'i')
	{
		argi = va_arg(args, int);
		ft_putstr_fd(ft_itoa(argi), 1);
		return (ft_strlen(ft_itoa(argi)));
	}
	else if (*s == 's')
		return (convert_str(s, args));	
	else if (*s == 'u')
		return (convert_ui(s, args)); //PB fonction recursive
	//else if (*s == 'p')
	//	return (convert_ptr(s, args));
	//xX
	return (0);
} //44 max si initialisee a 17


int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%' && ft_strchr("cspdiuxX%", *(s + 1)))
		{
			s++;
			count += convert(s, args);
		}
		else if (*s == '\\')
			put_backslash(s, &count);
		else
		{
			write(1, s, 1);
			count++;
		}
		s++;
	}
	return (count);
}

int	main(void)
{
	//char	str[] = "Hello, World!";
	unsigned int ui = 4294967295;

	// int num = 5;
	// printf("%c, %s, %p, %d, %i, %u, %x, %X, %%\n", str[0], str, str, num,
	//	num, num, num, num);
	// ft_printf("%i,%d,%%=\n", 5, 7);
	printf("\n\nPRINTF RES = %d\n\n", printf("%u", ui));
	printf("\n\nFT_PRINTF RES = %d\n\n", ft_printf("%u", ui));
	reset();
}
