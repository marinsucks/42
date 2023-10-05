#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *str, int c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (c == '\0')
		return ((char *)&str[i]);
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	while (str[i])
	{
		if (str[i] == c)
			count--;
		if (count == 0)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

#include <stdio.h>

int main()
{
	char *strrchr_char;
	char strrchr_str[] = "Remplace l'espace par un tiret.";
	printf("STRRCHR\n");
	printf("input = %s", strrchr_str);
	strrchr_char = strrchr(strrchr_str, ' ');
	*strrchr_char = '-';
	printf("\ntest result = %s\n\n", strrchr_str);
}
