#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (src < dst && src + len > dst)
	{
		d += len;
		s += len;
		while (len > 0)
		{
			*d = *s;
			d--;
			s--;
			len--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}

//INCOMPLETE FUNCTION - see example below

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char buffer[] = "0123456789";
	// char mem[30];
	ft_memmove(buffer + 4, buffer, strlen(buffer) + 1);
	// ft_memcpy(mem, buffer, 20);
	printf("%s\n", buffer);
	return (0);
} */
