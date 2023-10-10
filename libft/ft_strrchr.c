#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*last_occ;

	last_occ = NULL;
	while (*str != 0)
	{
		if (*str == c)
			last_occ = str;
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return ((char *)last_occ);
}
