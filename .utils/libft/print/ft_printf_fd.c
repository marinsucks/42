/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:14:21 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/23 16:56:08 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void	pf_fd_backslash(int fd, const char *s, int *count)
{
	write(fd, s, 2);
	s += 2;
	*count += 1;
}

short int	pf_fd_convert_bin(int fd, const char *s, va_list args)
{
	unsigned long	argl;
	char			*res;
	short int		len;

	argl = va_arg(args, unsigned long);
	res = NULL;
	res = ft_intbase(argl, "01", 2);
	len = ft_strlen(res);
	ft_putstr_fd(res, fd);
	free(res);
	s++;
	return (len);
}

int	pf_fd_convert(int fd, const char *s, va_list args)
{
	int	argi;

	if (*s == '%')
		write(fd, s, 1);
	else if (*s == 'c')
	{
		argi = va_arg(args, int);
		write(fd, &argi, 1);
	}
	else if (*s == 'd' || *s == 'i')
		return (pf_fd_convert_int(fd, args));
	else if (*s == 's')
		return (pf_fd_convert_str(fd, s, args));
	else if (*s == 'u')
		return (pf_fd_convert_ui(fd, s, args));
	else if (*s == 'x' || *s == 'X')
		return (pf_fd_convert_hex(fd, s, args, *s));
	else if (*s == 'b')
		return (pf_fd_convert_bin(fd, s, args));
	else if (*s == 'p')
		return (pf_fd_convert_ptr(fd, s, args));
	return (1);
}

/**
 * @brief ft_printf is a variadic function that prints to fd
 * according to a specific format.

 * @param fd The file descriptor to print to.
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
int	ft_printf_fd(int fd, const char *s, ...)
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
			count += pf_fd_convert(fd, s, args);
		}
		else if (*s == '\\')
			pf_fd_backslash(fd, s, &count);
		else
		{
			write(fd, s, 1);
			count++;
		}
		s++;
	}
	va_end(args);
	return (count);
}
