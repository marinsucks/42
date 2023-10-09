#include "libft.h"
#include <string.h>

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	char	*ptr;

	ptr = s1;
	while (*s1 != 0)
		s1++;
	while (*s2 != 0)
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = 0;
	return (ptr);
}