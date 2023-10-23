#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;

	d_len = 0;
	while (dst[d_len] && d_len < size)
		d_len++;
	s_len = 0;
	while (src[s_len] && (d_len + s_len) < (size - 1))
	{
		dst[d_len + s_len] = src[s_len];
		s_len++;
	}
	if (d_len < size)
		dst[d_len + s_len] = '\0';
	while (src[s_len])
		s_len++;
	return (d_len + s_len);
}

/* // not one which works

#include <stdio.h>

int	main(int argc, char const *argv[])
{
	char	*src;
	int		ret_val;
	int		ret_val2;

	src = (char *)argv[1];
	char dst[10] = "";
	char dst2[10] = "";
	ret_val = ft_strlcat(dst, src, sizeof(dst));
	ret_val2 = strlcat(dst2, src, sizeof(dst2));
	if (argc)
		printf("%s\n%d\n", dst, ret_val);
	printf("%s\n%d\n", dst2, ret_val2);
	return (0);
}
 */