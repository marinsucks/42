/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:46:26 by mbecker           #+#    #+#             */
/*   Updated: 2023/11/25 15:23:12 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>

int			ft_printf(const char *s, ...);
int			convert(const char *s, va_list args);
void		put_backslash(const char *s, int *count);

short int	convert_int(va_list args);
int			convert_str(const char *s, va_list args);
short int	convert_ui(const char *s, va_list args);
short int	convert_hex(const char *s, va_list args, char c);
short int	convert_ptr(const char *s, va_list args);

#endif
