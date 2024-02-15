/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:48:19 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/15 17:25:25 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "../libft.h"

short int	pf_convert_int(va_list args);
int			pf_convert_str(const char *s, va_list args);
short int	pf_convert_ui(const char *s, va_list args);
short int	pf_convert_hex(const char *s, va_list args, char c);
short int	pf_convert_ptr(const char *s, va_list args);
//ft_printf2.c

void		pf_backslash(const char *s, int *count);
short int	pf_convert_bin(const char *s, va_list args);
int			pf_convert(const char *s, va_list args);
int			ft_printf(const char *s, ...);
//ft_printf.c 

void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putlong_fd(long long n, int fd);
//ft_put.c

void		printtab(char **tab, int color);

#endif




