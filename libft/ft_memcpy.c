#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	while (n > 0 || src != NULL)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dst);
} 

#include <stdio.h>
#include <string.h>

int main() {

    char *buffer = NULL;
	char mem[30];
    //ft_memcpy(buffer + 3, buffer, strlen(buffer) + 1);
    ft_memcpy(mem, buffer, 20);
    printf("%s\n", mem);

    return 0;
}
