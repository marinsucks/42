#include "libft.h"
#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*ptr;

	ptr = dst;
	while (*src != 0 && (int)len > 0)
	{
		*dst = *src;
		src++;
		dst++;
		len--;
	}
	*dst = 0;
	return (ptr);
}