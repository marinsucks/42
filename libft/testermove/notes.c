#include <stdio.h>

int	main()
{
	char s[] = {-128, 0, 127, 0};
	char sCpy[] = {-128, 0, 127, 0};
	char s2[] = {0, 0, 127, 0};
	char s3[] = {0, 0, 42, 0};

	if (ft_memcmp(s, sCpy, 4) == NULL)
		printf("yes\n");
	else printf("no\n");
	if (ft_memcmp(s, 0, 1) == s)
		printf("yes\n");
	else printf("no\n");
	if (ft_memcmp(s, 2, 3) == s + 2)
		printf("yes\n");
	else printf("no\n");
	if (ft_memcmp(s, 6, 6) == NULL)
		printf("yes\n");
	else printf("no\n");
	if (ft_memcmp(s, 2 + 256, 3) == s + 2)
		printf("yes\n");
	else printf("no\n");

	printf("%c\n", 2 + 256);
}

//memchr ok
