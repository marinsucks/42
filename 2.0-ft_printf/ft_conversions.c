#include "ftprintf.h"

int	convert_str(const char *s, va_list args)
{
	char	*argstr;
	size_t	i;

	argstr = va_arg(args, char *);
	i = 0;
	while (argstr[i])
	{
		write(1, &argstr[i], 1);
		i++;
	}
	s++;
	return i;
}

short int	convert_ui(char *s, va_list args)
{
	unsigned int		argu;
	short int			len;

	argu = va_arg(args, unsigned int);
	
	if (argu >= 0 && argu <= 9)
		ft_putchar_fd(argu + '0', 1);
	else
	{
		convert_ui(argu / 10, 1);// PROBLEMESSSS
		convert_ui(argu % 10, 1);
	}
	len = 0;
	while (argu >= 10)
	{
		len++;
		argu /= 10;
	}
	s++;
	return (len);
}