#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *str, int c)
{
	const char	*last_occ;

	last_occ = NULL;
	if (c == '\0')
		return ((char *)str);
	while (*str != 0)
	{
		if (*str == c)
			last_occ = str;
		str++;
	}
	return ((char *)last_occ);
}
