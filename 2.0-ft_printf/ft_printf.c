/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:14:21 by mbecker           #+#    #+#             */
/*   Updated: 2023/11/23 17:29:56 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	ft_putbackslash(const char *s, int *count)
{
	write(1, s, 2);
	s += 2;
	*count += 1;
}

int	convert(const char *s, va_list args)
{
	int	argi;

	if (*s == '%')
		write(1, s, 1);
	else if (*s == 'c')
	{
		argi = va_arg(args, int);
		write(1, &argi, 1);
	}
	else if (*s == 'd' || *s == 'i')
		return (convert_int(args));
	else if (*s == 's')
		return (convert_str(s, args));
	else if (*s == 'u')
		return (convert_ui(s, args));
	else if (*s == 'x' || *s == 'X')
		return (convert_hex(s, args, *s));
	else if (*s == 'p')
		return (convert_ptr(s, args));
	return (0);
}

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
			ft_putbackslash(s, &count);
		else
		{
			write(1, s, 1);
			count++;
		}
		s++;
	}
	return (count);
}
