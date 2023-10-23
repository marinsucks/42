#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ub;
	unsigned char	uc;

	ub = b;
	uc = c;
	while (len > 0)
	{
		*ub = uc;
		ub++;
		len--;
	}
	return (b);
}
