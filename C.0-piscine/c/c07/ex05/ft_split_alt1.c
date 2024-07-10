#include <stdio.h>
#include <stdlib.h>

int isSep(char c, char *charset)
{
	for (int i = 0; charset[i]; i++)
	{
		if(charset[i] == c)
			return 1;
	}
	return 0;
}

int wordcount(char *str, char *charset)
{
	int count = 0;
	int i = 0;

	if (str[0] == 0)
		return 0;
	while (str[i])
	{
		if (str[0] == '\0')
			return 0;
		if (!isSep(str[i], charset) 
			&& (isSep(str[i + 1], charset) || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return count;
}

char *ft_strdup(char *str, int *i, char *charset)
{
	char *dest;
	int x = 0;
	int j = 0;

	for (; str[x]; x++)
		x++;
	dest = (char*)malloc(x * sizeof(char));
	if (!dest)
		return 0;

	while (str[*i] && !isSep(str[*i], charset))
	{
		dest[j] = str[*i];
		*i = *i + 1;
		j++;
	}
	dest[j] = 0;
	return (dest);
}

char **ft_split(char *str, char *charset)
{
	char **res;
	int i = 0;
	int j = 0;

	res = (char **)malloc(wordcount(str, charset) * sizeof(char *) + 1);
	for (; j < wordcount(str, charset); j++)
	{
		while (str[i] && isSep(str[i], charset))
			i++;
		while (str[i] && !isSep(str[i], charset))
			res[j] = ft_strdup(str, &i, charset);
	}
	res[j] = 0;
	return res;
}

#include <stdio.h>
int main(int ac, char **av)
{
    (void) ac;

    char **tab;
    int    i;
    int    number;

    tab =ft_split(av[1], av[2]);
    i = 0;
    number = wordcount(av[1], av[2]);
    while (i < number)
    {
        printf("*%s*\n", tab[i]);
		if (tab[i] == 0)
			printf("void");
        i++;
    }
    printf("\n---\n\n");
}

