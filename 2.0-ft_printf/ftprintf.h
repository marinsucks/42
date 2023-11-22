#ifndef FTPRINT_H
# define FTPRINT_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>

# include <stdio.h>

int			ft_printf(const char *s, ...);
int			convert(const char *s, va_list args);
void		put_backslash(const char *s, int *count);

int			convert_str(const char *s, va_list args);
short int	convert_ui(char *s, va_list args);




#endif
