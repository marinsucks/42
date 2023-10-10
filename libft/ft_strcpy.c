#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char	*ptr;

	ptr = dst;
	while (*src != 0)
	{
		*dst = *src;
		src++;
		dst++;
	}
	*dst = 0;
	return (ptr);
}
