/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:14:21 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/15 17:13:46 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void	pf_backslash(const char *s, int *count)
{
	write(1, s, 2);
	s += 2;
	*count += 1;
}

short int	pf_convert_bin(const char *s, va_list args)
{
	unsigned long	argl;
	char			*res;
	short int		len;

	argl = va_arg(args, unsigned long);
	res = NULL;
	res = ft_intbase(argl, "01", 2);
	len = ft_strlen(res);
	ft_putstr_fd(res, 1);
	free(res);
	s++;
	return (len);
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
	else if (*s == 'b')
		return (pf_convert_bin(s, args));
	else if (*s == 'p')
		return (pf_convert_ptr(s, args));
	return (1);
}

/**
 * @brief ft_printf is a variadic function that prints to stdout 
 * according to a specific format.

 * @param s The format string. Use the ```%``` character 
 * to indicate a conversion.
 * @param %c The char to print.
 * @param %s The string to print.
 * @param %p The pointer to print.
 * @param %d The int to print.
 * @param %i The int to print.
 * @param %u The unsigned int to print.
 * @param %x The unsigned int to print as hex.
 * @param %X The unsigned int to print as HEX.
 * @param %b The unsigned int to print as binary.
 * @param %% The percent sign.
 * 
 * @return The number of chars printed.
*/
int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%' && ft_strchr("cspdiuxXb%", *(s + 1)))
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
