/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:14:21 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/26 11:28:04 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pf_backslash(const char *s, int *count)
{
	write(1, s, 2);
	s += 2;
	*count += 1;
}

int	pf_convert(const char *s, va_list args)
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
		return (pf_convert_int(args));
	else if (*s == 's')
		return (pf_convert_str(s, args));
	else if (*s == 'u')
		return (pf_convert_ui(s, args));
	else if (*s == 'x' || *s == 'X')
		return (pf_convert_hex(s, args, *s));
	else if (*s == 'p')
		return (pf_convert_ptr(s, args));
	return (1);
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
			count += pf_convert(s, args);
		}
		else if (*s == '\\')
			pf_backslash(s, &count);
		else
		{
			write(1, s, 1);
			count++;
		}
		s++;
	}
	va_end(args);
	return (count);
}
