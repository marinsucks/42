#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	int	i;
	int	j;

	i = 0;
	if (needle[0] == 0)
		return ((char *)haystack);
	while (haystack[i] && n > 0)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && n > 0)
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
			j++;
			n--;
		}
		i++;
		n += j;
		n--;
	}
	return (NULL);
}
